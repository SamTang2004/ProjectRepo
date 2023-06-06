
import collections
#good fours and good fives
"""
def r(k,path):
    if k == 0:
        if  str(collections.Counter(path)[5])  + " " + str(collections.Counter(path)[4]) not in val :
            val.append(( str(collections.Counter(path)[5])  + " " + str(collections.Counter(path)[4])))
        return
    if k < 0:
        return
    r(k-5,path + [5])
    r(k-4, path + [4])
r(int(s),[])
final = len(val)
"""

def find():
    s = int(input())
    fours = 0
    fives = 0
    while s%5 != 0:
        s -= 4
        fours += 1
        if s  < 0:
            print(0)
            return
    fives = s / 5
    final = 0
    while fives >= 0:
        fives -= 4
        fours += 5
        final += 1
    print(final)

find()
