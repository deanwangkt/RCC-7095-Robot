/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Spark.h>
#include <frc/Solenoid.h>

class Claw : public frc::Subsystem {
 public:
  Claw();
  void InitDefaultCommand() override;
  void Shoot(double vel);
  void TogglePusher(bool state);
  void Log();

 private:
  frc::Spark shooter_high{5};
  frc::Spark shooter_low{6};

  frc::Solenoid pusher_in{0};
  frc::Solenoid pusher_out{1};
};
