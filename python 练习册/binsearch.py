# binsearch
# access: O(1)
# search: O(log_2(n))
# mem: O(n log n) can be optimized to O(log n)

def binsearch(target:int, arr: list):
    print("run")
    if len(arr) == 1 and arr[0] != target:
        return False
    if arr[int(len(arr)/2)] == target:
        return True
    elif arr[int(len(arr)/2)] > target:
        return binsearch(target, arr[:int(len(arr)/2)])
    else:
        return binsearch(target, arr[int(len(arr)/2):])


arr = [0,1,2,3,4,5,6,7,8]

print(binsearch(9,arr))
    
