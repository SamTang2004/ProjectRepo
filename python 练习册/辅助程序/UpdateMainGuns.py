import requests
import pandas as pd
import sys
import io

url = "https://wiki.biligame.com/blhx/%E6%88%98%E5%88%97%E7%82%AE"
html = requests.get(url).content
df_list = pd.read_html(html)
db = open("MainGunsDB.csv","w+", encoding= "utf-8")
df_list[1].to_csv(db)
db.close()
