#!/usr/bin/env python
#coding:utf-8

'''
Track a green ball using OpenCV.
    Copyright (C) 2015 Conan Zhao and Simon D. Levy
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation, either version 3 of the 
    License, or (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 You should have received a copy of the GNU Lesser General Public License 
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
'''

import cv2
import numpy as np


select_point = [0,0]
px_hsv = np.uint8([[[0,0,0]]])
enable_flags = False
select_flags = False
# For OpenCV2 image display
WINDOW_NAME = 'ColorTracker'
def select_color(event,x,y,flags,param):
    global select_point
    global enable_flags
    global select_flags
    if event==cv2.EVENT_LBUTTONDOWN:
        select_point=[x,y]
        enable_flags = True
        select_flags =True
        print '我选择了'+str(select_point)+'点'
    if event == cv2.EVENT_RBUTTONDOWN:
        enable_flags = False
#cv2.setMouseCallback(WINDOW_NAME,select_color)

def track(image):

    '''Accepts BGR image as Numpy array
       Returns: (x,y) coordinates of centroid if found
                (-1,-1) if no centroid was found
                None if user hit ESC
    '''

    # Blur the image to reduce noise
    global select_point
    global enable_flags
    global select_flags
    global px_hsv

    image = cv2.resize(image,(640,360))
    blur = cv2.GaussianBlur(image, (5,5),0)
    if enable_flags:
        if select_flags:
            px = np.uint8([[image[select_point[1],select_point[0]]]])

            px_hsv = cv2.cvtColor(px,cv2.COLOR_BGR2HSV)
            select_flags = False
        print px_hsv[0,0,0]


        if px_hsv[0,0,0]>20 and px_hsv[0,0,0]<235:
            lower_color = np.array([px_hsv[0,0,0] - 20,70,70])
            upper_color = np.array([px_hsv[0,0,0] + 20,200,200])
        elif px_hsv[0,0,0] <= 20:
            lower_color = np.array([0,70,70])
            upper_color = np.array([px_hsv[0,0,0] + 20,200,200])
        elif px_hsv[0,0,0] >=235:
            lower_color = np.array([px_hsv[0,0,0] - 20,70,70])
            upper_color = np.array([255,200,200])

        # Convert BGR to HSV
        hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

        # Threshold the HSV image for only green colors


        # Threshold the HSV image to get only green colors
        mask = cv2.inRange(hsv, lower_color, upper_color)


        # Blur the mask
        bmask = cv2.GaussianBlur(mask, (5,5),0)
        cv2.imshow("bmask",bmask)


        # Take the moments to get the centroid
        moments = cv2.moments(bmask)
        sum_pix = np.sum(mask)


        m00 = moments['m00']
        centroid_x, centroid_y = None, None
        if m00 != 0:
            centroid_x = int(moments['m10']/m00)
            centroid_y = int(moments['m01']/m00)

        # Assume no centroid
        ctr = (-1,-1)

        # Use centroid if it exists
        if centroid_x != None and centroid_y != None:

            ctr = (centroid_x, centroid_y)

            # Put black circle in at centroid in image
            cv2.circle(image, ctr, 4, (0,0,0))

        # Display full-color image
        cv2.imshow(WINDOW_NAME, image)

        # Force image display, setting centroid to None on ESC key input
        if cv2.waitKey(1) & 0xFF == 27:
            ctr = None

        # Return coordinates of centroid
        print ctr
        return ctr,sum_pix/(255*255*255)

    cv2.imshow(WINDOW_NAME, image)
    return (-1,-1),-1

# Test with input from camera
if __name__ == '__main__':
    cv2.namedWindow(WINDOW_NAME)

    capture = cv2.VideoCapture("test.mp4")
    cv2.setMouseCallback(WINDOW_NAME,select_color)
    while True:

        okay, image = capture.read()


        if okay:

            if not track(image):
                break
          
            if cv2.waitKey(1) & 0xFF == 27:
                break

        else:

           print('Capture failed')
           break
