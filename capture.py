import cv2
cap = cv2.VideoCapture(0)  # 设置摄像头 0是默认的摄像头 如果你有多个摄像头的话呢，可以设置1,2,3....
while True:  # 进入无限循环
    ret, frame = cap.read()  # 将摄像头拍到的图像作为frame值
    cv2.imshow('frame', frame)  # 将frame的值显示出来 有两个参数 前一个是窗口名字，后面是值
    c = cv2.waitKey(1)  # 判断退出的条件 当按下'Q'键的时候呢，就退出
    if c == ord('q'):
        break
cap.release()  # 常规操作
cv2.DestroyAllWindows()
