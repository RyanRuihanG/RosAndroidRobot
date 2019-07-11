#!/usr/bin/env python
import roslib
import sys
import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import color
import geometry_msgs.msg
from color_tracker import *

class image_converter:

  def __init__(self):

    self.cmd_pub = rospy.Publisher("/cmd_vel",geometry_msgs.msg.Twist,queue_size= 1)
    self.image_sub = rospy.Subscriber("/camera/image",Image,self.callback,queue_size = 1 )
    #cv2.namedWindow("Image window", cv2.CV_WINDOW_AUTOSIZE)
    self.bridge = CvBridge()
    self.twist = geometry_msgs.msg.Twist()
    self.index = 0


  def callback(self,data):
    try:
      cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError, e:
      print e

    (rows,cols,channels) = cv_image.shape
    (vx,vy,vz,wx,wy,wz) = color.action(cv_image,640,360)
    print (vx,vy,vz,wx,wy,wz)
    temp = self.twist.linear.y
    self.twist.linear.x = 0
    self.twist.linear.y = vy
    self.twist.linear.z = vz
    self.twist.angular.x = wx
    self.twist.angular.y = wy
    self.twist.angular.z = wz
    self.index += 1

    #cv2.imshow("Image window", cv_image)
    if not self.twist.linear.y == temp and self.index % 10 ==0:
         self.cmd_pub.publish(self.twist)

    cv2.waitKey(3)


def main(args):
  ic = image_converter()
  cv2.namedWindow(WINDOW_NAME,cv2.WINDOW_AUTOSIZE)
  cv2.setMouseCallback(WINDOW_NAME,select_color)

  rospy.init_node('color_tracker', anonymous=True)
  try:
    rospy.spin()
  except KeyboardInterrupt:
    print "Shutting down"
  cv2.destroyAllWindows()

if __name__ == '__main__':
    main(sys.argv)
