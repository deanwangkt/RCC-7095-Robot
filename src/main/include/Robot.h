/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/WPILib.h>
#include "OI.h"
#include "subsystems/Chassis.h"
#include "subsystems/Claw.h"
#include "subsystems/Elevator.h"

class Robot : public frc::TimedRobot {
  public:
    static Chassis m_chassis;
    static Claw m_claw;
    static Elevator m_elevator;
    static OI m_oi;

    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

  private:
    bool inClimbState = false;
    frc::Command* m_autonomousCommand = nullptr;
    frc::SendableChooser<frc::Command*> m_chooser;
};
