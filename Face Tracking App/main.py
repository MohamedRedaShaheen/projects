import cv2
from random import randrange
face_data = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
webcam = cv2.VideoCapture(0)
while True:
    successful,frame = webcam.read()
    gray_img = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    face_coordinates = face_data.detectMultiScale(gray_img)
    for (x,y,w,h) in face_coordinates:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(randrange(256),randrange(256),randrange(256)),3)
        cv2.putText(frame,'Good Face',(x,y),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,255),2)
        cv2.imshow('shaheen',frame)
        key = cv2.waitKey(1)
        if key == 81 or key ==113:
            break
    if key == 81 or key == 113:
        break
webcam.release()