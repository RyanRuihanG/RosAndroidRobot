# CSPM
This is a ROS package for cspm project.
##Introduction
CSPM means computer, smart phone and microcontrollers. We developed a simple robot, and put the smart phone on it.Then we read the data from the smart phone, just like ths imu data, camera, gps and geomagnitic.

We use ROS to manage these messages. And this repository is the ROS package we created. At the same time, we developed several android app to controll the robot, and the apk file will be uploaded recently.

##Tutorials
###Install
Download this package, cd to cspm folder, then type

```
catkin_make
source devel/setup.bash
```

Download CSPMRobot.apk,CSPMRemoter.apk and joystick.apk and install them in your smart phone.

###Quick to start
Open CSPMRobot, then put your mobile phone in your robot. type
```
rosrun face_detect facedetect _param:=/camera/image
```
Then you will see an opencv windows which mark your face apeared.

Open CSPMRemoter, type
```
rosrun voice_detect voice_py.py
```
Talking to your mobile phone, your voice will be translated to mandarin and Pinyin.This node publish them as rostopic in your computer.
