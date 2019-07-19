/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**
 * ?
 */

#include "OI.h"

#include <frc/WPILib.h>
#include <frc/GenericHID.h>

#include "commands/LegIn.h"
#include "commands/LegOut.h"
#include "commands/PusherIn.h"
#include "commands/PusherOut.h"
#include "commands/ElevatorSetSetpoint.h"
#include "commands/OneButtonClimb.h"
#include "Consts.h"

OI::OI() {
  stick_0_A.WhenPressed(new LegOut());
  stick_0_B.WhenPressed(new LegIn());
  
  stick_0_X.WhenPressed(new OneButtonClimb());

  stick_1_A.WhenPressed(new PusherIn());
  stick_1_B.WhenPressed(new PusherOut());

  stick_1_X.WhenPressed(new ElevatorSetSetpoint(Consts::ELEVATOR_CLIMB_PREP));
  stick_1_POVUp.WhenPressed(new ElevatorSetSetpoint(Consts::ELEVATOR_TOP));
  stick_1_POVDown.WhenPressed(new ElevatorSetSetpoint(Consts::ELEVATOR_BOTTOM));
}

frc::XboxController& OI::GetJoystick0() {
  return joystick_0;
}

frc::XboxController& OI::GetJoystick1() {
  return joystick_1;
}

double OI::Regularize(double value) {
  if (value < THRESHOLD && value > -THRESHOLD) {
    return 0;
  }
  return value;
}

double OI::GetDriveZ() {
  return Regularize(joystick_0.GetX(frc::GenericHID::JoystickHand::kRightHand));
}

double OI::GetDriveY() {
  return Regularize(-joystick_0.GetY(frc::GenericHID::JoystickHand::kLeftHand));
}

double OI::GetDriveX() {
  return Regularize(- joystick_0.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand)
                    + joystick_0.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand));
}

double OI::GetElevator() {
  return Regularize(-joystick_1.GetY(frc::GenericHID::JoystickHand::kLeftHand));
}

double OI::GetShooter() {
  return Regularize(-joystick_1.GetY(frc::GenericHID::JoystickHand::kRightHand));
}