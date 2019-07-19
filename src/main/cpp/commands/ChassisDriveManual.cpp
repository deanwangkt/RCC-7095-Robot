/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChassisDriveManual.h"
#include "Consts.h"
#include "Robot.h"

ChassisDriveManual::ChassisDriveManual() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_chassis);
}

// Called just before this Command runs the first time
void ChassisDriveManual::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ChassisDriveManual::Execute() {
  Robot::m_chassis.Drive(Consts::X_COEF * Robot::m_oi.GetDriveX(), Consts::Y_COEF * Robot::m_oi.GetDriveY(), Consts::Z_COEF * Robot::m_oi.GetDriveZ());
}

// Make this return true when this Command no longer needs to run execute()
bool ChassisDriveManual::IsFinished() { return false; }

// Called once after isFinished returns true
void ChassisDriveManual::End() {
  Robot::m_chassis.Drive(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChassisDriveManual::Interrupted() {
  Robot::m_chassis.Drive(0, 0, 0);
}
