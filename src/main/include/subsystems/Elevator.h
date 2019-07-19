/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

class Elevator : public frc::Subsystem {
  public:
    Elevator();
    void InitDefaultCommand() override;

    int GetElevatorPosition();
    int GetElevatorVelocity();
    void Reset();
    bool OnTarget(int threshold);
    double Clamp(double val, double lower, double upper);
    double DoPIDCalculation(double kP, double kI, double kD);
    void Lift(double vel);
    void Log();

    
    void SetSetpoint(int setpoint);
    int GetSetpoint();

    void EnablePID();
    void DisablePID();
    int upward = 0;

  private:
    bool PID_enabled = false;
    bool ontarget = false;
    int lift_setpoint = 100;

    TalonSRX lift_motor{11};
};
