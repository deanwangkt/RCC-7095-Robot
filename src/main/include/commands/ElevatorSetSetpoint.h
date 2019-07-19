/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/InstantCommand.h>


class ElevatorSetSetpoint : public frc::InstantCommand {
  public:
    ElevatorSetSetpoint(int target);
    void Initialize() override;
  private:
    int l_target;
};
