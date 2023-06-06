#good groups

pair = int(input())
pairs = []
for i in range(pair):
    pairs.append(input().split(" "))
nopair = int(input())
nopairs = []
for i in range(nopair):
    nopairs.append(input().split(" "))
group = int(input())
groups = []
for i in range(group):
    groups.append(input().split(" "))
err = 0
pairsbin = []
nopairsbin = []

for i in groups:
    for j in pairs:
        
        if (j[0] in i or j[1] in i) and j not in pairsbin:
            if not(j[0] in i and j[1] in i):
                err += 1
                pairsbin.append(j)
                
        
    for j in nopairs:
        if (j[0] in i or j [1] in i) and j not in nopairsbin:
            if (j[0] in i and j[1] in i):
                err += 1
                nopairsbin.append(j)
print(err)
