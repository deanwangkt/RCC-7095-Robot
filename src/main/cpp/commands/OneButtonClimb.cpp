/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/OneButtonClimb.h"
#include "commands/LegOut.h"
#include "commands/ElevatorSetSetpoint.h"
#include "Consts.h"

OneButtonClimb::OneButtonClimb() {
  AddParallel(new ElevatorSetSetpoint(Consts::ELEVATOR_CLIMB_FIN));
  AddParallel(new LegOut());
}
