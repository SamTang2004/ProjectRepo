# frequency analysis
keys = []
frq = {}
f = open("english words.txt", "r")
word = f.readlines()
words = []
for i in range(len(word)):
    if len(word[i].strip()) == 5 and word[i].strip().isalpha():
        words.append(word[i].strip().lower())

for i in words:
    for j in range(len(i)-1):
        if (i[j] + i[j+1]) not in keys:
            keys.append(i[j] + i[j+1])
            frq[i[j] + i[j+1]] = 1
        else:
            frq[i[j] + i[j+1]] += i.count(i[j] + i[j+1])
            
top = []
topDigrams = []

for i in range(len(keys)):
    if len(top) < 30:
        top.append(frq[keys[i]]/1000)
        topDigrams.append(keys[i])
    else:
        for j in range(len(top)):
            if top[j] < frq[keys[i]]/1000:
                top[j] = frq[keys[i]]/1000
                topDigrams[j] = keys[i]
                break
finalFrq = {}
for i in range(len(top)):
    finalFrq[topDigrams[i]] = top[i]
print("#################")
print(finalFrq)
print("#################")
# trigrams
keys = []
frq = {}
for i in words:
    for j in range(len(i)-2):
        if (i[j] + i[j+1] + i[j+2]) not in keys:
            keys.append(i[j] + i[j+1] + i[j+2])
            frq[i[j] + i[j+1] + i[j + 2]] = 1
        else:
            frq[i[j] + i[j+1]+ i[j + 2]] += i.count(i[j] + i[j+1]+ i[j + 2])
top = []
topDigrams = []
finalFrq = {}
for i in range(len(keys)):
    if len(top) < 30:
        top.append(frq[keys[i]]/1000)
        topDigrams.append(keys[i])
    else:
        for j in range(len(top)):
            if top[j] < frq[keys[i]]/1000:
                top[j] = frq[keys[i]]/1000
                topDigrams[j] = keys[i]
                break
for i in range(len(top)):
    finalFrq[topDigrams[i]] = top[i]
print("################# T R I G R A M S ########")
print(finalFrq)
print("#################")
