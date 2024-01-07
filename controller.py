##   HELLO

import time
import serial

def controlupdate(up, tmp, s):
    if up == 5: # USE RIGHT HAND palm to camera
            i = "forward\n"
            s.write(i.encode())
            time.sleep(0.5)
            print("forward")
        
    elif up == 2 and "PINKY TIP" in tmp: # and "THUMB TIP" in tmp
        i = "right\n"
        s.write(i.encode())
        time.sleep(0.5)
        print("right")

    elif up == 2 and "INDEX FINGER TIP" in tmp:
        i = "left\n"
        s.write(i.encode())
        time.sleep(0.5)
        print("left")

    else:
        i = "stop\n"
        s.write(i.encode())
        time.sleep(0.5)
        print("stop")

