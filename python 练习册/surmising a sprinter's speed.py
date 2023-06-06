# surmising a sprinter's speed
"""
lines = int(input())
dataset = []
for i in range(lines):
    dataset.append(input().split(" "))
for i in range(len(dataset)):
    for j in range(len(dataset[i])):
        dataset[i][j] = int(dataset[i][j])

print(dataset)

"""
dataset = [[20,-5],[0,-17],[10,31],[5,-3],[30,11]]

dataset = sorted(dataset)
speed = 0;
print(dataset)
for i in range(len(dataset) -1 ):
    if abs(dataset[i+1][1] - dataset[i][1])/abs(dataset[i+1][0] - dataset[i][0]) > speed:
        speed = abs(dataset[i+1][1] - dataset[i][1])/abs(dataset[i+1][0] - dataset[i][0])
print(speed)
