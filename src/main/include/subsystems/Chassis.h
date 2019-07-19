/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Talon.h>
#include <frc/Solenoid.h>

class Chassis : public frc::Subsystem {
  public:
    Chassis();
    void InitDefaultCommand() override;
    void Drive(double x, double y, double z);
    void ToggleLeg(bool state);
    void Log();

  private:
    frc::Talon LF_motor{0};
    frc::Talon LR_motor{1};
    frc::Talon RF_motor{2};
    frc::Talon RR_motor{3};

    frc::Solenoid leg_out{2};
    frc::Solenoid leg_in{3};
};
