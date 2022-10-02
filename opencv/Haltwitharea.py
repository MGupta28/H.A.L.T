import cv2
import numpy as np
def Trafficupdate(p,l):
    frame=cv2.imread(p)
    brg=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(brg, 90, 255, cv2.THRESH_BINARY)
    inverted_image = cv2.bitwise_not(thresh)
    cropped_image1 = frame[100::, 0::]
    #cropped_image3 = inverted_image[100::, 0::]
    cropped_image3 = thresh[100::, 0::]
    contours, hierarchy = cv2.findContours(cropped_image3 , 1, cv2.CHAIN_APPROX_NONE)
    cv2.drawContours(cropped_image1, contours, -1, (0,255,0), 1)
    ty=0
    for i in range(len(contours)):
        area = cv2.contourArea(contours[i])
        ty+=area
    cv2.putText(cropped_image1, "Contour area is {0}".format(ty), ( 120,200), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
    print(l,ty)
    return cropped_image1
#MAIN
a=Trafficupdate('./images/r1.png',0)
b=Trafficupdate('./images/r2.png',1)
c=Trafficupdate('./images/r3.png',2)
d=Trafficupdate('./images/r4.png',3)
while True:
        cv2.imshow("1",a)
        cv2.imshow("2",b)
        cv2.imshow("3",c)
        cv2.imshow("4",d)
        if cv2.waitKey(10) & 0xff == ord('q'):   # 1 is the time in ms
            break

cv2.destroyAllWindows()
