/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorSetSetpoint.h"

#include "Robot.h"

ElevatorSetSetpoint::ElevatorSetSetpoint(int target) {
  l_target = target;
}

void ElevatorSetSetpoint::Initialize() {
  Robot::m_elevator.SetSetpoint(l_target);
}
