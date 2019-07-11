#!/usr/bin/env python
import roslib

import rospy
import tf.transformations as tfs
import tf
import geometry_msgs.msg
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

class Fuck():
    def __init__(self, x=[0,0,0], v=[0,0,0], a=[0,0,0], e=[0,0,0], w=[0,0,0]):
        # local coordinate
        self.e = e
        self.w = w
        self.a = a
        # global coordinate
        self.x = x
        self.v = v

    def pose(self):
        return self.x + self.e

    def twist(self):
        return self.v + self.w





class IMU():
    def __init__(self, o=0, w=0, a=0):
        self.o = o
        self.w = w
        self.a = a


def callback(dat):
    global fuck
    global imu
    global past
    global odom
    # dat.orientation
    o1, o2, o3, o4 = dat.orientation.x, dat.orientation.y, dat.orientation.z, dat.orientation.w
    # dat.angular_velocity
    w1, w2, w3 = dat.angular_velocity.x, dat.angular_velocity.y, dat.angular_velocity.z
    # dat.linear_acceleration
    a1, a2, a3 = dat.linear_acceleration.x, dat.linear_acceleration.y, dat.linear_acceleration.z
    
    now = dat.header.stamp
    if past:
        dt = (now - past).to_sec();
    else:
        dt = 0
    past = now
    
    imu.o, imu.w, imu.a = [o1, o2, o3, o4], [w1, w2, w3], [a1, a2, a3]
    w = np.dot(tfs.quaternion_matrix(imu.o)[:3,:3],[0,0,-1])#
    a1,a2,a3=imu.a
    vx,vy,vz=fuck.v
    x,y,z=fuck.x
    ax = a1*w[0]+a3*w[1]
    ay = a1*w[1]-a3*w[0]
    wz = imu.w[2]
    vx += (fuck.a[0]+ax)/2.0*dt
    vy += (fuck.a[1]+ay)/2.0*dt
    x += fuck.v[0]*dt+(ax+2*fuck.a[0])/6.0*dt**2
    y += fuck.v[1]*dt+(ay+2*fuck.a[1])/6.0*dt**2
    fuck.v[0] = vx
    fuck.v[1] = vy
    fuck.x[0] = x
    fuck.x[1] = y
    odom_quat = geometry_msgs.msg.Quaternion()

    odom.header.stamp = now
    odom.header.frame_id = "odom"
    odom.pose.pose.position.x,odom.pose.pose.position.y,odom.pose.pose.position.z = fuck.x
    odom.pose.pose.orientation=fuck.e[2]
    odom.child_frame_id='base_link'
    odom.twist.twist.linear.x,odom.twist.twist.linear.y,odom.twist.twist.linear.z=fuck.v
    #odom.twist = fuck.twist()
    odom_pub.publish(odom)
    print x,y,vx,vy


    
    


if __name__ == '__main__':
    
    odom = Odometry()
    fuck = Fuck()
    imu = IMU()
       
    past = None
    fuck = Fuck()
    
    rospy.init_node('imulistener', anonymous=True)
    rospy.Subscriber('/android/imu', Imu, callback)
    odom_pub = rospy.Publisher('odom_pub', Odometry, queue_size=50)
    
    rospy.spin()

 
