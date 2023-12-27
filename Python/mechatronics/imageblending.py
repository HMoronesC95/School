import cv2
import numpy as np

img1 = cv2.imread('C:\imagenes\ejemplo23.jpg')
img2 = cv2.imread('C:\imagenes\ejemplo20.jpg')

img2_resized = cv2.resize(img2,(img1.shape[1],img1.shape[0]),cv2.INTER_CUBIC)

cv2.imshow('img1',img1)
cv2.imshow('img2',img2_resized)

for i in range (1,100,2):
    a = i/100.0
    dst = cv2.addWeighted(img1,a,img2_resized,(1-a),0)
    cv2.imshow('dst',dst)
    cv2.waitKey(100)
    
cv2.waitKey(0)
cv2.destroyAllWindows()
