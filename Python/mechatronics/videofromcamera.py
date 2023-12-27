import numpy as np
import cv2

cap = cv2.VideoCapture(0)

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('video_from_camera.avi',fourcc, 20.0, (640,480))

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret==True:
        #frame = cv2.flip(frame,1)

        cv2.line(frame,(0,0),(511,511),(255,0,0),5)
        cv2.line(frame,(0,511),(511,0),(0,0,255),3)

        cv2.rectangle(frame,(384,0),(510,128),(0,255,0),3)

        cv2.circle(frame,(447,63), 63, (0,0,255), -1)

        cv2.ellipse(frame,(256,256),(100,50),0,0,180,255,-1)

        pts = np.array([[10,5],[20,30],[70,20],[50,10]], np.int32)
        pts = pts.reshape((-1,1,2))
        cv2.polylines(frame,[pts],True,(0,255,255))

        font = cv2.FONT_HERSHEY_SIMPLEX
        cv2.putText(frame,'OpenCV',(10,500), font, 4,(255,255,255),2,cv2.LINE_AA)

        # write the flipped frame
        out.write(frame)

        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()
