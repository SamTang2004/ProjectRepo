# remove dupes


# using sorting before calculation
# O(N log N) time, O(1) extra space
a = [1,2,2,3,6,3,4,5,0,5,5,5,7,5,5,5,6,6,7,8,9]

def removeDupesWithSort():
    a= sorted(a)
    # i is begin index
    i = 0
    while i < len(a)-1:
        if a[i] == a[i+1]:
            a.remove(a[i + 1])
        else:
            i += 1

# No sorting before calculation, all operations on the same list
# O(N) time, O(N) extra space
def removeDupesWOSort():
    seenElements = []
    i = 0
    while i < len(a):
        this = a[i]
        if this not in seenElements:
            seenElements.append(this)
            i += 1
        else:
            a.pop(i)


removeDupesWOSort()

print(a)
