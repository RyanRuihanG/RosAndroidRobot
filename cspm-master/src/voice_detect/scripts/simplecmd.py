#!/usr/bin/env python
#coding:utf-8
import roslib

import rospy
from geometry_msgs.msg import Twist
import std_msgs.msg
from nav_msgs.msg import Odometry



class CSPMRobot:
    def __init__(self):
        self.tt = Twist()
        self.refresh()
        self.cmd_pub = rospy.Publisher('/cmd_vel',Twist, queue_size=1)
        #语音指令
        self.tts_pub = rospy.Publisher('/tts',std_msgs.msg.String, queue_size=1)
        self.commond_pub = rospy.Publisher('/commond',std_msgs.msg.String,queue_size=1)
        self.tts = std_msgs.msg.String()
    def move_forword(self,speed):
        self.tt.linear.x = speed
        self.cmd_pub.publish(self.tt)
        self.refresh()
    def move_back(self,speed):
        self.tt.linear.x = -speed
        self.cmd_pub.publish(self.tt)
        self.refresh()
    def turn_left(self,speed):
        self.tt.angular.z = speed
        self.cmd_pub.publish(self.tt)
        self.refresh()
    def turn_right(self,speed):
        self.tt.angular.z = -speed
        self.cmd_pub.publish(self.tt)
        self.refresh()
    def stop(self):
        self.refresh()
        self.cmd_pub.publish(self.tt)
    def refresh(self):
        self.tt.angular.x = 0;
        self.tt.angular.y = 0;
        self.tt.angular.z = 0;
        self.tt.linear.x = 0;
        self.tt.linear.y = 0;
        self.tt.linear.z = 0;

    def speak(self,message):
        self.tts.data = message
        self.tts_pub.publish(self.tts)

    def send_commond(self,message):
        self.tts.data = message
        self.commond_pub.publish(self.tts)

def callback(msg):
    global cr
    message = msg.data

    cr = CSPMRobot()
    if message == "qian-jin":
        cr.speak("好的，马上前进")
       
        cr.move_forword(0.5)
        print 'qian jin'
    if message == "hou-tui":
        cr.speak("好的，马上后退")
        cr.move_back(0.5)
    if message == "zuo-zhuan":
        cr.speak("好的，马上左转")
        cr.turn_left(0.5)
    if message == "you-zhuan":
        cr.speak("好的，马上右转")
        cr.turn_right(0.5)
    if message == "ting-zhi":
        cr.speak("好的，马上停止")
        cr.stop()
    if message.find('yao')>=0 and message.find('qing')>=0:
        cr.send_commond('rec')
        cr.speak("好的，请把药放在我面前吧！")
    if message.find('qing')>=0 and message.find('wo')>=0 and message.find('zou')>=0:
        cr.send_commond('follow_mode')
        cr.speak("好的主人，我会一直跟着您！")
    if message.find('ni')>=0 and message.find('hao')>=0:
        cr.speak("我是若斯机器人,很高兴为您服务")
    if message.find('qing')>=0 and message.find('na')>=0 and message.find('ban')>=0:
        cr.speak("好的,马上为您拿六角扳手")


rospy.init_node('simplecmd', anonymous=True)
rospy.Subscriber('voice_py', std_msgs.msg.String, callback)
cr = CSPMRobot()

rospy.spin()
