from bs4 import BeautifulSoup
def __init__(self):
    self.base_url = 'https://accounts.pixiv.net/login?lang=zh&source=pc&view_type=page&ref=wwwtop_accounts_index'
    self.login_url = 'https://accounts.pixiv.net/api/login?lang=zh'
    self.target_url = 'http://www.pixiv.net/search.php?' \
                          'word=%E5%9B%9B%E6%9C%88%E3%81%AF%E5%90%9B%E3%81%AE%E5%98%98&order=date_d&p='
    self.main_url = 'http://www.pixiv.net'
        # headers只要这两个就可以了,之前加了太多其他的反而爬不上
    self.headers = {
            'Referer': 'https://accounts.pixiv.net/login?lang=zh&source=pc&view_type=page&ref=wwwtop_accounts_index',
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) '
                          'AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'
        }
    self.pixiv_id = 'userid'
    self.password = '*****'
    self.post_key = []
    self.return_to = 'http://www.pixiv.net/'
    self.load_path = 'D:\psdcode\Python\pixiv_pic'
    self.ip_list = []

    def login(self):
        post_key_html = se.get(self.base_url, headers=self.headers).text
        post_key_soup = BeautifulSoup(post_key_html, 'lxml')
        self.post_key = post_key_soup.find('input')['value']
        # 上面是去捕获postkey
        data = {
            'pixiv_id': self.pixiv_id,
            'password': self.password,
            'return_to': self.return_to,
            'post_key': self.post_key
        }
        se.post(self.login_url, data=data, headers=self.headers)
    login(self)
__init__(self)
