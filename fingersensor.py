from collections import Counter
import time
import cv2
import serial
from module import findnameoflandmark,findpostion #,speak
from controller import controlupdate


s = serial.Serial('COM3', 9600)
s.timeout = 1


#Use CV2 Functionality to create a Video stream and add some values + variables
cap = cv2.VideoCapture(0)
tip=[8,12,16,20]
tipname=[8,12,16,20]
fingers=[]
finger=[]

#Create an infinite loop which will produce the live feed to our desktop and that will search for hands
while True:
    ret, frame = cap.read() 
    
    #Determines the frame size, 640 x 480 offers a nice balance between speed and accurate identification
    frame1 = cv2.resize(frame, (640, 480))
    
    #Below is used to determine location of the joints of the fingers 
    a=findpostion(frame1)
    b=findnameoflandmark(frame1)
    
    # Determine which fingers are up and down
    tmp = []
    if len(b and a)!=0:
        finger=[]
        if a[0][1:] < a[4][1:]: 
           finger.append(1)
        else:
            finger.append(0)   
        fingers=[] 
        for id in range(0,4):
            if a[tip[id]][2:] < a[tip[id]-2][2:]:
                tmp.append(b[tipname[id]])
                fingers.append(1)
            else:
                fingers.append(0)       
    x=fingers + finger
    c=Counter(x)
    up=c[1]
    down=c[0]

    # based on collected data update movement on robot
    controlupdate(up,tmp,s)
    
    #Below shows the current frame to the desktop 
    cv2.imshow("Frame", frame1);
    key = cv2.waitKey(50) & 0xFF
    
    #Below states that if the |s| is press on the keyboard it will stop the system
    if key == ord("s"):
        break

s.close()