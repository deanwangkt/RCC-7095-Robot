/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/XboxController.h>
#include <frc/buttons/JoystickButton.h>
#include "XboxPOV.h"

#pragma once

class OI {
  public:
    OI();

    frc::XboxController joystick_0{0};
    frc::XboxController joystick_1{1};

    frc::JoystickButton stick_0_A{&joystick_0, 1};
    frc::JoystickButton stick_0_B{&joystick_0, 2};
    frc::JoystickButton stick_0_X{&joystick_0, 3};
    frc::JoystickButton stick_0_Y{&joystick_0, 4};
    frc::JoystickButton stick_0_LBumper{&joystick_0, 5};
    frc::JoystickButton stick_0_RBumper{&joystick_0, 6};

    frc::JoystickButton stick_1_A{&joystick_1, 1};
    frc::JoystickButton stick_1_B{&joystick_1, 2};
    frc::JoystickButton stick_1_X{&joystick_1, 3};
    frc::JoystickButton stick_1_Y{&joystick_1, 4};
    frc::JoystickButton stick_1_LBumper{&joystick_1, 5};
    frc::JoystickButton stick_1_RBumper{&joystick_1, 6};
    XboxPOV stick_1_POVUp{&joystick_1, 0};
    XboxPOV stick_1_POVRight{&joystick_1, 90};
    XboxPOV stick_1_POVDown{&joystick_1, 180};
    XboxPOV stick_1_POVLeft{&joystick_1, 270};
    
    frc::XboxController& GetJoystick0();
    frc::XboxController& GetJoystick1();

    double Regularize(double value);
    double GetDriveX();
    double GetDriveY();
    double GetDriveZ();
    double GetElevator();
    double GetShooter();

  private:
    const double THRESHOLD = 0.15;
};
