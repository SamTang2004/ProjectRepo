from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
import time
import requests
import re
from bs4 import BeautifulSoup

def waitForLoad():
    wait.until(lambda browser: browser.execute_script("return document.readyState")=="Complete")
    
def getCookies(driver):
    cookies = {}
    selenium_cookies = driver.get_cookies()
    for cookie in selenium_cookies:
        cookies[cookie["name"]] = cookie["value"]
    return cookies
def getHTML():
    waitForLoad()
    return browser.page_source
def writeToFile(html):
    file = open("html.txt","w+",encoding = "utf-8")
    file.write(html)
    file.close()
# Login to PIXIV
options = webdriver.ChromeOptions()
options.add_argument("--headless")
chromedriver = r"C:\Users\12471\AppData\Local\Programs\Python\Python38\Lib\site-packages\selenium\webdriver\chrome\chromedriver.exe"
geturl = "https://accounts.pixiv.net/login?return_to=https%3A%2F%2Fwww.pixiv.net%2F&lang=zh&source=pc&view_type=page"
username = "20samtang04@gmail.com"
password = "sam1247167538"
browser = webdriver.Chrome(executable_path=chromedriver)
wait = WebDriverWait(browser, 30)
browser.get(geturl)
browser.find_element_by_xpath("//input[@placeholder='邮箱地址或pixiv ID']").send_keys(username)
browser.find_element_by_xpath("//input[@placeholder='密码']").send_keys(password)
browser.find_element_by_xpath("//button[@type='submit']").click()


waitForLoad()
# search tag
keyTag = ["乳交"]
browser.find_element_by_xpath('//input[@placeholder="搜索作品"]').send_keys(" ".join(keyTag) + Keys.ENTER)

# get hrefs
# the code below should be repeatable.
# this segment gets all artworks in a page.

waitForLoad()
hrefs = []

html = getHTML()

time.sleep(3)


waitForLoad()
begin = html.index('ul class="sc-l7cibp-1 krFoBL"')
end = html[begin:].index("</ul>")+begin
html = html[begin : end]
hrefs = re.findall('href="(.*?)"', html)
print(begin, end)
print(html)
print(hrefs)
i = 0
while i < len(hrefs):
    if hrefs[i][:9] != "/artworks":
        hrefs.remove(hrefs[i])
    else:
        hrefs[i] = "https://pixiv.net" + hrefs[i]
        i += 1
hrefs.remove(hrefs[0])


# this segment deals with one artwork in the page:
browser.get(hrefs[0])
pagehtml = getHTML()
waitForLoad()
tagElements =browser.find_elements(By.CLASS_NAME,"sc-d98f2c-0 gtm-new-work-tag-event-click")
print(tagElements)
tags = []
for i in tagElements:
    tags.append(i.name)
print(tags)
#for i in hrefs:
#    browser.get(i)
#    pagehtml = getHTML()
#    


