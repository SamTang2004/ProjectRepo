import collections
#good triplets
n,c = input().split(" ")
points = input().split(" ")
for i in range(len(points)):
    points[i] = int(points[i])

pointCt = collections.Counter(points)
points = list(pointCt)


