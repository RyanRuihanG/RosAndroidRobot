#coding:utf-8


# PID parameters
Kpx = 0.25
Kpy = 2
Kdx = 0.25
Kdy = 0.25
Kix = 0
Kiy = 0
pix_sum_old = 1
pix_sum_0 = 1
idx = 0
import cv2
import numpy as np
import color_tracker
# Routine called by C program.
def action(img_bytes, img_width, img_height):
    # Set up command defaults
    global pix_sum_old
    global pix_sum_0
    global idx

    vx = 0
    vy = 0
    vz = 0
    wx = 0
    wy = 0
    wz = 0

    #首次运行时的初始化设置
    if idx == 0:
        ctr,pix_sum_0 = color_tracker.track(img_bytes)
        pix_sum_0 = 1000
        idx += 1
        pix_sum_old = pix_sum_0
    # Set up state variables first time around
    if not hasattr(action, 'count'):
        action.count = 0
        action.errx_1 = 0
        action.erry_1 = 0
        action.phi_1 = 0
        action.gaz_1 = 0

    # Grab centroid of green ball
    ctr,pix_sum = color_tracker.track(img_bytes)
    if ctr == (-1,-1):
        return (0,0,0,0,0,0)
    # Use centroid if it exists
    if pix_sum / float(pix_sum_0) > 0:
        # Compute proportional distance (error) of centroid from image center
        erry =  _dst(ctr, 0, img_width)
        errx =  1 - pix_sum/float(pix_sum_0)
        pix_sum_old = pix_sum
        # Compute vertical, horizontal velocity commands based on PID control after first iteration
        if action.count > 0:
            vx = _pid( errx, action.errx_1, Kpx, Kix, Kdx)
            vy = -_pid( erry, action.erry_1, Kpy, Kiy, Kdy)
        # Remember PID variables for next iteration
        action.errx_1 = errx
        action.erry_1 = erry
        action.count += 1
    # Send control parameters back to drone
    return (vx,vy,vz,wx,wy,wz)
# Simple PID controller from http://www.control.com/thread/1026159301
def _pid(err, err_1, Kp, Ki, Kd):
    return Kp*err + Ki*(err+err_1) + Kd*(err-err_1) 
# Returns proportional distance to image center along specified dimension.
# Above center = -; Below = +
# Right of center = +; Left = 1
def _dst(ctr, dim, siz):
    siz = siz/2
    return (ctr[dim] - siz) / float(siz)    

    cv2.imshow(WINDOW_NAME, image)
    # Force image display, setting centroid to None on ESC key input
    if cv2.waitKey(1) & 0xFF == 27:
        ctr = None
    # Return coordinates of centroid
    return ctr
# Test with input from camera
if __name__ == '__main__':
    capture = cv2.VideoCapture(0)
    while True:
        okay, image = capture.read()
        if okay:
            if not color_tracker.track(image):
                break
            if cv2.waitKey(1) & 0xFF == 27:
                break
        else:
           print('Capture failed')
           break
