import requests
import pandas as pd
import sys
import io

url = "https://wiki.biligame.com/blhx/%E8%BD%B0%E7%82%B8%E6%9C%BA"
html = requests.get(url).content
df_list = pd.read_html(html)
db = open("BomberDB.csv","w+", encoding= "utf-8")
df_list[1].to_csv(db)
db.close()

url = "https://wiki.biligame.com/blhx/%E6%88%98%E6%96%97%E6%9C%BA"
df_list = pd.read_html(requests.get(url).content)
db = open("FighterDB.csv","w+", encoding = "utf-8")
df_list[1].to_csv(db)
db.close()


url = "https://wiki.biligame.com/blhx/%E9%B1%BC%E9%9B%B7%E6%9C%BA"
df_list = pd.read_html(requests.get(url).content)
db = open("TorpedoBomberDB.csv","w+", encoding = "utf-8")
df_list[1].to_csv(db)
db.close()
