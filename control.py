import pyautogui
import pyperclip
import time

pyautogui.PAUSE = 1  # 暂停的时间
pyautogui.FAILSAFE = True  # 自启动故障处理
print(pyautogui.size())  # 获取屏幕大小
print(pyautogui.position())  # 获取当前鼠标坐标


pyautogui.moveTo(758, 602, duration=1.20)  # 移动鼠标到具体坐标，duration为所需的时间
pyautogui.doubleClick()

time.sleep(2.2)

pyautogui.keyDown('F5')

pyautogui.keyDown('enter')

pyautogui.hotkey('alt', 'tab')
