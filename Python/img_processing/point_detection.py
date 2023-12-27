import numpy as np
import cv2
import math

mtx=np.load('matriz.npy')
dist=np.load('distorsion.npy')

cap = cv2.VideoCapture(0)

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
        
        h,  w = frame.shape[:2]
        newcameramtx, roi=cv2.getOptimalNewCameraMatrix(mtx,dist,(w,h),1,(w,h))
        # undistort
        dst = cv2.undistort(frame, mtx, dist, None, newcameramtx)

        # crop the image
        x,y,w,h = roi
        dst = dst[y:y+h, x:x+w]

        hsv = cv2.cvtColor(dst, cv2.COLOR_BGR2HSV)
        
        green_lower = np.array([30, 100, 100], np.uint8)
        green_upper = np.array([50, 255, 255], np.uint8)
        green_mask = cv2.inRange(hsv, green_lower, green_upper)
        
        kernal = np.ones((3, 3), "uint8")
        
        green_mask = cv2.dilate(green_mask, kernal)
        
        res_green = cv2.bitwise_and(dst, dst, mask = green_mask)

        # Creating contour to track green color
        contours, hierarchy = cv2.findContours(green_mask,
                                               cv2.RETR_TREE,
                                               cv2.CHAIN_APPROX_SIMPLE)
        centroxn=0
        centroyn=0
        contador=0

        for pic, contour in enumerate(contours):
            area = cv2.contourArea(contour)
            if(area > 200):
                x, y, a, b = cv2.boundingRect(contour)
                centroxn=int(x+a/2)
                centroyn=int(y+b/2)
                #dst = cv2.rectangle(dst, (x, y),(x + w, y + h),(0, 255, 0), 2)
                dst = cv2.circle(dst, (centroxn, centroyn),5,(0, 255, 0), 2)
                if(contador>0):
                    dst = cv2.line(dst, (centroxn, centroyn),(centrox, centroy),(255, 0, 0), 2)
                centrox=centroxn
                centroy=centroyn
                contador=contador+1
                
                
        cv2.imshow('frame',dst)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()
