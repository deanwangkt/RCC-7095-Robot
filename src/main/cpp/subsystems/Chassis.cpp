/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**
 * chassis with 4 motor
 */

#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/ChassisDriveManual.h"
#include "subsystems/Chassis.h"

Chassis::Chassis() : frc::Subsystem("Chassis") {}

void Chassis::InitDefaultCommand() {
  SetDefaultCommand(new ChassisDriveManual());
}

void Chassis::Drive(double x, double y, double z) {
  LF_motor.Set(x + y + z);
  LR_motor.Set(x - y - z);
  RF_motor.Set(x - y + z);
  RR_motor.Set(x + y - z);
}

void Chassis::ToggleLeg(bool state) {
  if (state) {
    leg_in.Set(false);
    leg_out.Set(true);
  } else {
    leg_in.Set(true);
    leg_out.Set(false);
  }
}

void Chassis::Log() {
  
}