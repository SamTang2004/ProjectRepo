# Merge-sort

def Merge(a : list, b : list):

    newList = []
    
    while min(len(a),len(b)) != 0:
        if a[0] < b[0]:
            newList.append(a[0])
            a.remove(a[0])
        else:
            newList.append(b[0])
            b.remove(b[0])
    if len(a) > 0:
        newList += a
    if len(b) > 0:
        newList += b
    return newList
    

def MergeSort(k : list):
    if len(k) == 1:
        return k
   
    a = MergeSort(k[ : int(len(k)/2) ])
    b = MergeSort(k[ int(len(k)/2) : ])

    return Merge(a,b)


print(MergeSort([1,4,2,5,6,2,51,2,6,7,4,66,234,-9]))
