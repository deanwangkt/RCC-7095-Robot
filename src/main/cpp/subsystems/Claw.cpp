/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**
 * claw class
 */

#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/ClawShootManual.h"
#include "subsystems/Claw.h"

Claw::Claw() : frc::Subsystem("Claw") {}

void Claw::InitDefaultCommand() {
  SetDefaultCommand(new ClawShootManual());
}

void Claw::Shoot(double vel) {
  shooter_high.Set(vel - 0.15);
  shooter_low.Set(vel);
}

void Claw::TogglePusher(bool state) {
  if (state) {
    pusher_in.Set(false);
    pusher_out.Set(true);
  } else {
    pusher_in.Set(true);
    pusher_out.Set(false);
  }
}

void Claw::Log() {
  frc::SmartDashboard::PutBoolean("Pusher Out", pusher_out.Get());
}
