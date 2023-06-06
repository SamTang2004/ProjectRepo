def insertionSort(arr):
    count = 0
    for i in range(len(arr)):
        
        temp = arr[i]
        possibleIndex = i
        print(temp, possibleIndex)
        while (possibleIndex > 0) and (temp < arr[possibleIndex - 1]):
            count += 1
            arr[possibleIndex]  = arr[possibleIndex-1]
            possibleIndex -= 1
            print(arr)
            
        arr[possibleIndex] = temp
        print(arr)
    
    print(count)
a = [4,12,4,7,19,6]
insertionSort(a)

print(a)

