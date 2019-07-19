/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

//电梯相关

class Consts {
 public:
  Consts();

  #pragma region Chassis
  constexpr static double X_COEF = 0.6;                     // 底盘的速度系数，X 为左右平移，Y 为前后，Z 为旋转
  constexpr static double Y_COEF = 0.6;
  constexpr static double Z_COEF = 0.6;
  #pragma endregion

  #pragma region Claw
  constexpr static double IN_COEF = 0.5;                    // 爪子收球速度系数
  constexpr static double OUT_COEF = 0.5;                   // 爪子射球速度系数
  #pragma endregion

  #pragma region Elevator
  const static int ELEVATOR_CLIMB_FIN = -800;           // 最后爬升结束位置
  const static int ELEVATOR_CLIMB_PREP = 10000;         // 爬升开始位置
  const static int ELEVATOR_TOP = 28000;                // 最高位置
  const static int ELEVATOR_BOTTOM = 400;               // 收球位置

  constexpr static double ELEVATOR_TOP_LIMIT = 30000;
  constexpr static double ELEVATOR_BOTTOM_LIMIT = -1500;

  constexpr static double JOYSTICK_CHANGE_RATE = 160;

  constexpr static double UPWARD_kP = 0.001;
  constexpr static double UPWARD_kI = 0.0;
  constexpr static double UPWARD_kD = 0.0;

  constexpr static double DOWNWARD_kP = 0.003;
  constexpr static double DOWNWARD_kI = 0.0;
  constexpr static double DOWNWARD_kD = 0.0005;
  #pragma endregion
};
