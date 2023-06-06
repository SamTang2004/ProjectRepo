import bs4
from bs4 import BeautifulSoup
import requests
from html.parser import HTMLParser
link = "https://www.pixiv.net/tags/膨乳/artworks"

def getText(url):
    r = requests.get(url)
    return r.text

html = getText(link)
soup = BeautifulSoup(html,"html.parser")
soup.prettify()



