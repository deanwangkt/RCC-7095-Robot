# RCC 7095 Robot

## 机器人坐标定义

X轴：机器人的左右，向右为正

Y轴：机器人的前后，向前为正

Z轴：机器人的上下，向上为正 （所以旋转正方向为逆时针）

Claw：射球方向为正，收球为负

## 文件

### 主要的文件们

##### Consts

定义了**所有需要调整的常量**，具体内容见文件注释

##### OI

定义了与手柄有关的逻辑

##### Robot

机器人的主体程序

##### XboxPOV

因为 Command System 没有对 Xbox 手柄 POV 键的原生支持，所以写了一个小程序。不用管这个。


### 子系统 Subsystems

##### 底盘 Chassis
	
- 四颗底盘电机

- 后面爬升用的两个 Cylinder

##### 爪子 Claw

- 上下两颗电机

- 爪子伸出用的 Cylinder

##### 电梯 Elevator

- 升降电机，有编码器，可以读角度和角速度

- 带 PD 运算

- 带电子限位

### 命令 Commands

##### ChassisDriveManual

手动操作的程序，是 Chassis 子系统的默认程序

##### ClawShootManual

手动操作的程序，是 Claw 子系统的默认程序

##### ElevatorLiftAutoRun

Elevator 自动移动到子系统的 setpoint，是 Elevator 子系统的默认程序

##### ElevatorSetSetpoint

设置 Elevator 子系统的目标位置

##### LegIn

缩回后面爬升的小脚脚

##### LegOut

伸出后面爬升的小脚脚

##### OneButtonClimb

名字看起来像是一键爬升，但实际作用只是让 Elevator 和小脚脚同时下降/伸出，让机器人升高到台阶高度

##### PusherIn

缩回前面的小手手（收球机构）

##### PusherOut

伸出前面的小手手（收球机构）


