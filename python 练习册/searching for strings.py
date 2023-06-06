#perms
import collections
def generatePerms(s : str):
    strList = list(s)
    perms = []
    def r(chars:list, f:str):
        if len(chars) == 0:
            perms.append(f)
            return

        for i in range(len(chars)):
            newchars = chars.copy()
            newchars.remove(chars[i])
            r(newchars, f + chars[i])

        
    r(strList, "")
    return perms
target = input("target string ")
haystack = input("haystack string ")
perms = collections.Counter(generatePerms(target))
val = 0
for i in perms:
    if i in haystack:
        val += 1
print(val)
