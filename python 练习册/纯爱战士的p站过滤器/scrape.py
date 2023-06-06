import requests
import re
from bs4 import BeautifulSoup
headers = {'Referer': 'https://accounts.pixiv.net/login?lang=zh&source=pc&view_type=page&ref=wwwtop_accounts_index','User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64)' 'AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36' }
html = ""
def getTT():
    login_url = "https://accounts.pixiv.net/login?return_to=https://www.pixiv.net/lang=zh&source=pc&view_type=page"
    response= requests.get(url = login_url,headers = headers, verify = False)
    html = response.text
    return re.findall('"pixivAccount.tt":"(.*?)",', html)[0]
tt = getTT()


session = requests.Session()


form_data = {"pixiv_id":"20samtang04@gmail.com","password":"sam1247167538","return_to":"https://www.pixiv.net/","tt":tt}
login_url1 = "https://accounts.pixiv.net/login?return_to=https://www.pixiv.net/lang=zh&source=pc&view_type=page"
res = session.post(url = login_url1, data = form_data)
print(res)

file = open("html.html","w+")
file.write(str(session.get("https://pixiv.net/").content))
file.close()
