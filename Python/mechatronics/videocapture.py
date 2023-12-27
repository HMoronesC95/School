import numpy as np
import cv2

cap = cv2.VideoCapture(0)
#cap1 = cv2.VideoCapture(1)

#Los siguientes valores son los de default de la camara que se este usando
print('El ancho de la captura es: ',cap.get(3))
print('El largo de la captura es: ',cap.get(4))
print('El numero de cuadros FPS que se capturan es: ',cap.get(5))

#En las siguientes lineas se trata de cambiar la resolucion de la captura de la imagen
cap.set(3,1280)
cap.set(4,960)

print('El ancho de la captura es: ',cap.get(3))
print('El largo de la captura es: ',cap.get(4))

while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    #ret1, frame1 = cap1.read()

    # Our operations on the frame come here
    #gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Display the resulting frame
    ret, frame = cap.read()
    #ret1, frame1 = cap.read()
    if cv2.waitKey(1) & 0xFF == ord('q'):
        cv2.imwrite('C:/imagenes/rostros/homero.jpg',frame)
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()
