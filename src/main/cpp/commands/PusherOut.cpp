/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PusherOut.h"

#include "Robot.h"

PusherOut::PusherOut() {}

void PusherOut::Initialize() {
  Robot::m_claw.TogglePusher(true);
}
