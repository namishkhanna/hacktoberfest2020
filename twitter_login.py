from selenium import webdriver
import time

# create a new Chrome session
driver = webdriver.Chrome()
driver.implicitly_wait(30)
driver.maximize_window()

# navigate to the application home page
driver.get("https://twitter.com/login")


# get the username textbox
login_field = driver.find_element_by_class_name("js-username-field")
login_field.clear()

# enter username
login_field.send_keys("ENTER USERNAME HERE")
time.sleep(1)

#get the password textbox
password_field = driver.find_element_by_class_name("js-password-field")
password_field.clear()

#enter password
password_field.send_keys("ENTER PASSWORD HERE")
time.sleep(1)
password_field.submit()