def maxArea(height):
        maxval = 0
        for i in range(len(height)):
            for j in range(i,len(height)):
                print(i,j)
                if min(height[i],height[j]) * (j-i) > maxval:
                    maxval = min(height[i],height[j]) * (j-i)
        return maxval

def maxArea2(height):
    i = 0
    j = len(height)-1
    maxval = 0
    while j-i >= 1 :
        print(i,j)
        if (min(height[i],height[j])) * (j-i) > maxval:
            maxval  = (min(height[i],height[j])) * (j-i)
        if height[i] <= height[j]:
            i += 1
        elif height[j] < height[i]:
            j -= 1
    return maxval
print(maxArea2([1,8,6,2,5,4,8,3,7])) # 49
