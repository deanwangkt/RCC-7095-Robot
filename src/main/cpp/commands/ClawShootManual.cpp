/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClawShootManual.h"
#include "Consts.h"
#include "Robot.h"

ClawShootManual::ClawShootManual() {
  Requires(&Robot::m_claw);
}

// Called just before this Command runs the first time
void ClawShootManual::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClawShootManual::Execute() {
  double val = Robot::m_oi.GetShooter();
  if (val > 0) {
    Robot::m_claw.Shoot(Consts::OUT_COEF * val);
  } else {
    Robot::m_claw.Shoot(Consts::IN_COEF * val);
  }
  
}

// Make this return true when this Command no longer needs to run execute()
bool ClawShootManual::IsFinished() { return false; }

// Called once after isFinished returns true
void ClawShootManual::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawShootManual::Interrupted() {}
