def selectionSort(k : list):
    cycle = 0
    for i in range(len(k)):

        minIndex = i
        for j in range(i + 1, len(k)):
            if k[j] < k[minIndex]:
                minIndex = j
        if i != minIndex:
            cycle += 1
            print(k[i],k[minIndex])
            k[i], k [minIndex] = k[minIndex],k[i]
    print(cycle)
    return k

a = [9,8,7,6,5]

a = selectionSort(a)
print(a)
