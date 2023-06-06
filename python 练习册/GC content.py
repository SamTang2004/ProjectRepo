f= open("rosalind_gc.txt","r").readlines()
for i in range(len(f)):
    f[i] = f[i].strip()
tags = []
contents = []
i = 0

def readContent(begin : int):
    returned = ""
    for i in range(begin, len(f)):
        if f[i][0] != ">":
            returned += f[i]
        else:
            break
    return returned

for i in range(len(f)):
    if f[i][0] == ">":
        tags.append(f[i])
        contents.append(readContent(i + 1))
GCp = []
for i in range(len(tags)):
    GCp.append((contents[i].count("G") + contents[i].count("C"))/len(contents[i]))

print(tags[GCp.index(max(GCp))], max(GCp) * 100)
