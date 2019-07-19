/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorLiftAutoRun.h"
#include "Consts.h"
#include "Robot.h"

ElevatorLiftAutoRun::ElevatorLiftAutoRun() {
  Requires(&Robot::m_elevator);
}

void ElevatorLiftAutoRun::Initialize() {
  Robot::m_elevator.EnablePID();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorLiftAutoRun::Execute() {
  double output;
  if (Robot::m_elevator.GetSetpoint() < Consts::ELEVATOR_TOP_LIMIT
      && Robot::m_elevator.GetSetpoint() > Consts::ELEVATOR_BOTTOM_LIMIT) {
    Robot::m_elevator.SetSetpoint(Robot::m_elevator.GetSetpoint() + Consts::JOYSTICK_CHANGE_RATE * Robot::m_oi.GetElevator());
  }
  if (Robot::m_elevator.GetElevatorPosition() < Robot::m_elevator.GetSetpoint()) {
    // Going Up
    Robot::m_elevator.upward = 1;
    output = Robot::m_elevator.DoPIDCalculation(Consts::UPWARD_kP, Consts::UPWARD_kI, Consts::UPWARD_kD);
  } else {
    // Going Down
    Robot::m_elevator.upward = -1;
    output = Robot::m_elevator.DoPIDCalculation(Consts::DOWNWARD_kP, Consts::DOWNWARD_kI, Consts::DOWNWARD_kD);
  }
  Robot::m_elevator.Lift(output);
}

bool ElevatorLiftAutoRun::IsFinished() { return false; }

void ElevatorLiftAutoRun::End() {
  Robot::m_elevator.DisablePID();
  Robot::m_elevator.Lift(0);
}

void ElevatorLiftAutoRun::Interrupted() {
  Robot::m_elevator.DisablePID();
  Robot::m_elevator.Lift(0);
}
