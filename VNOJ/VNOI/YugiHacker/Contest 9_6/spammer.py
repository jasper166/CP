import pyautogui, time
from pynput.keyboard import Controller

time.sleep(10)
f = open("spam.in", 'r')

for word in f:
    s = "Mày là một con " + word
    Controller().type(s)    
    time.sleep(1)
    pyautogui.press("enter")