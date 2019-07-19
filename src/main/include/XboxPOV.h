/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/buttons/Button.h>
#include <frc/XboxController.h>

#pragma once

class XboxPOV : public frc::Button {
  public:
    XboxPOV(frc::XboxController* joystick, int buttonNumber);
    virtual ~XboxPOV() = default;
    
    
    XboxPOV(XboxPOV&&) = default;
    XboxPOV& operator=(XboxPOV&&) = default;

    virtual bool Get();

  private:
    frc::XboxController* m_stick;
    int m_dir;
  
};
