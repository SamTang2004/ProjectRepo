#tester

import re

file = open("html.txt",encoding="utf-8").read()
print(file.index('ul class="sc-l7cibp-1 krFoBL"'))
print(file[file.index('ul class="sc-l7cibp-1 krFoBL"'):].index("</ul>"))
print(re.findall('ul class="sc-l7cibp-1 krFoBL"(.*?)</ul>',file))
