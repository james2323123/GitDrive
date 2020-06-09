import numpy as np
import cv2
import math
import functions

axis = np.float32([[0.1,0,0], [0,0.1,0], [0,0,0.1]]).reshape(-1,3)



front_face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

cam = cv2.VideoCapture(0)

# read camera params
f = cv2.FileStorage("webcam_param_out.xml", cv2.FILE_STORAGE_READ)
intrinsicNode = f.getNode("intrinsic")
distortionNode = f.getNode("distortion")
intrinsic = intrinsicNode.mat()
distortion = distortionNode.mat()
f.release()

while True:
    ret, img = cam.read()
    front_faces = front_face_cascade.detectMultiScale(img,1.3,5)
    pts = np.array([(0,479),(639,479),(60,0),(579,0)], dtype = "float32")
    warped = functions.four_point_transform(img, pts)

    # converts (x,y,w,h) to (x1,y1,x2,y2)
    for i in range(len(front_faces)):
        front_faces[i][2] += front_faces[i][0]
        front_faces[i][3] += front_faces[i][1]
        
    front_face_boxes = functions.non_max_suppression_fast(front_faces)
    
    for (x1,y1,x2,y2) in front_face_boxes:
        imgPoints = np.array([[x1,y1],[x1,y2],[x2,y1],[x2,y2]], dtype = np.float)
        objPoints = np.array([[-0.1,-0.1,0],[-0.1,0.1,0],[0.1,-0.1,0],[0.1,0.1,0]], dtype = np.float)
        ret, rvec, tvec = cv2.solvePnP(objPoints, imgPoints,intrinsic,distortion)
        img = cv2.rectangle(img, (x1,y1), (x2,y2), (255,0,0), 4)
        cv2.putText(img, str(tvec[0][0]), (x2,y2), cv2.FONT_HERSHEY_DUPLEX, 1, (255,0,0), 2, cv2.LINE_AA)
        cv2.putText(img, str(tvec[1][0]), (x2,y2+20), cv2.FONT_HERSHEY_DUPLEX, 1, (0,255,0), 2, cv2.LINE_AA)
        cv2.putText(img, str(tvec[2][0]), (x2,y2+40), cv2.FONT_HERSHEY_DUPLEX, 1, (0,0,255), 2, cv2.LINE_AA)
        
    cv2.imshow('camera',img)
    cv2.imshow('warped',warped)
    key = cv2.waitKey(30)
    if key == 27:
        break
    
cv2.destroyAllWindows()







