/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/**
 * utils
 */

#include "XboxPOV.h"

XboxPOV::XboxPOV(frc::XboxController* stick, int dir)
    : m_stick(stick), m_dir(dir) {}

bool XboxPOV::Get() {
    return m_stick->GetPOV() == m_dir;
}