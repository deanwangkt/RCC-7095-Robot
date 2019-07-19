/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**
 * elevator class
 */

#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/ElevatorLiftAutoRun.h"
#include "subsystems/Elevator.h"
#include "Consts.h"

Elevator::Elevator() : frc::Subsystem("Elevator") {}

void Elevator::InitDefaultCommand() {
  SetDefaultCommand(new ElevatorLiftAutoRun());
}

int Elevator::GetElevatorPosition() {
  return lift_motor.GetSelectedSensorPosition();
}

int Elevator::GetElevatorVelocity() {
  return lift_motor.GetSelectedSensorVelocity();
}

void Elevator::SetSetpoint(int setpoint) {
  lift_setpoint = setpoint;
  
  frc::SmartDashboard::PutNumber("Setsetpoint!!", lift_setpoint);
}

int Elevator::GetSetpoint() {
  return lift_setpoint;
}

void Elevator::EnablePID() {
  PID_enabled = true;
}

void Elevator::DisablePID() {
  PID_enabled = false;
}

bool Elevator::OnTarget(int threshold) {
  ontarget = abs(GetElevatorPosition() - GetSetpoint()) < threshold;
  return ontarget;
}

void Elevator::Reset() {
  lift_motor.SetSelectedSensorPosition(0);
}

double Elevator::Clamp(double val, double lower, double upper) {
  // Debug 可以使用，判断 upper 是否小于 lower
  /*
  if (lower - upper > 0.2) {
    ErrorBase error;
    error.SetErrnoError("Value error", "Robot.cpp", "Clamp", 38);
    throw error;
  }
  */
  if (val > upper) {
    val = upper;
  }
  if (val < lower) {
    val = lower;
  }
  return val;
}

double Elevator::DoPIDCalculation(double kP, double kI, double kD) {
  double error = Clamp(kP * (GetSetpoint() - GetElevatorPosition()), -1.0, 1.0);
  double diff_error = kD * GetElevatorVelocity();
  
  if (error > 0) {
    error -= Clamp(diff_error, 0.0, error);
  } else if (error < 0) {
    error -= Clamp(diff_error, error, 0.0);
  }
  // 不用积分算法
  // error += Clamp(kI * integral, -error, 0.0);
  return error;
}

void Elevator::Lift(double vel) {
  if (vel > 0 && GetElevatorPosition() < Consts::ELEVATOR_TOP_LIMIT) {
    lift_motor.Set(ControlMode::PercentOutput, -vel);
  } else if (vel < 0 && GetElevatorPosition() > Consts::ELEVATOR_BOTTOM_LIMIT) {
    lift_motor.Set(ControlMode::PercentOutput, -vel);
  } else {
    lift_motor.Set(ControlMode::PercentOutput, 0);
  }
}

void Elevator::Log() {
  frc::SmartDashboard::PutNumber("Elevator Position", GetElevatorPosition());
  frc::SmartDashboard::PutNumber("Elevator Velocity", GetElevatorVelocity());
  frc::SmartDashboard::PutNumber("Elevator Setpoint", lift_setpoint);
  frc::SmartDashboard::PutBoolean("Elevator On Target", ontarget);
  frc::SmartDashboard::PutBoolean("Elevator PID Enabled", PID_enabled);
  frc::SmartDashboard::PutNumber("Elevator Direction", upward);
}
