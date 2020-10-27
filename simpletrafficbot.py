import webbrowser
import time
import keyboard
# generate random integer values
from random import seed
from random import randint

count = 0
# You can change the urls to the websites you would like to open
urls = ['http://100topblog.blogspot.com/'] # your url
sleeptime = 0
while count != 10:
    # Opens a new tab
    for url in urls:
        webbrowser.open(url, new=0)
        # For itw not to open all at the same time
        value = randint(0, 10)
        # print(value)
        sleeptime = value+12
        time.sleep(sleeptime)
        print(sleeptime)
        keyboard.press_and_release('Command, W')
        # This will stop the loop after 100 times
        count = count + 1

else:
    pass
