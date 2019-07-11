#!/usr/bin/env python
import roslib

import rospy
import tf.transformations as tfs
import tf
import geometry_msgs.msg
import cv2
from nav_msgs.msg import Odometry
# Odometry:
#   pose:x1,x2,x3,th1,th2,th3
#   twist:v1,v2,v3,w1,w2,w3    the diff of pose
from sensor_msgs.msg import Imu
import numpy as np

# Imu:
# Imu.orientation:quaternion orientation
# Imu.angular_velocity:w1,w2,w3
# Imu.linear_acceleration:a1,a2,a3

# init
def callback(imu):

    pose = geometry_msgs.msg.Pose()
    pose.orientation = imu.orientation
    pose.position.x = 0
    pose.position.y = 0
    pose.position.z = 0
    global pose_pub
    pose_pub.publish(pose)
rospy.init_node('posepub', anonymous=True)
rospy.Subscriber('/android/imu', Imu, callback)
pose_pub = rospy.Publisher('pose', geometry_msgs.msg.Pose, queue_size=50)
rospy.spin()


