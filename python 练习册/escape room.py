# escape room
"""
# input
rows = input("rows: ")
columns = input("columns: ")
col = []
for i in range(int(rows)):
    col.append(input().split(" "))

print(col)
"""
#col = [ [3,10,8,14],[1,11,12,12],[6,2,3,9]]
col = [[4,1], [1,2]]
trash = []
trash.append((len(col[0]),len(col)))
def r(x,y):

    if x*y == 1:
        return True
    msum = []
    for i in range(len(col)):
        for j in range(len(col[i])):
            if col[i][j] == x * y and (i+1,j+1) not in trash:
                trash.append( (i+1,j+1) )
                msum.append(r(j + 1, i + 1))
    return sum(msum)

if r(len(col[0]),len(col)) == 1:
    print(True)
else:
    print(False)
