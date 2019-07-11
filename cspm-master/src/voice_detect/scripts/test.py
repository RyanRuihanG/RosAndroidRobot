__author__ = 'meng'
import numpy as np
import cv2
from matplotlib import pyplot as plt

img1 = cv2.imread('box.png',0)
img2 = cv2.imread('box_in_scene',0)

orb = cv2.SIFT()
kp1,des1 = orb.detectAndCompute(img1, None)
kp2,des2 = orb.detectAndCompute(img2,None)

bf = cv2.BFMatcher()


matches = bf.knnMatch(des1,des2,k=2)
good = []
for m,n in  matches:
    if m.distance < 0.75 * n.distance:
        good.append([m])
img3 = cv2.drawMatchesKnn(img1,kp1,img2,kp2,good[:10],flags=2)
plt.imshow(img3)
plt.show()