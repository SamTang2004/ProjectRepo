import random
timeBeforeLastDrop = 1
p= 0.25
baseP = 0.1
# algo: for every 1 roll in 4, avg we should get a drop
# we then apply pseudorandom algo as such
# segmented: 
# if not drop then check random again after adding 1/4 to it

drops = 0
rolls = 0
maxtime = 0

it = 2000
i = 0
while i < 2000:
    i += 1
    nextInput = 1
    if nextInput != "":
        local = baseP * timeBeforeLastDrop
        rolls += 1
        if random.random() < local:
            drops += 1
            timeBeforeLastDrop = 1

        else:
            timeBeforeLastDrop += 1

        if timeBeforeLastDrop > maxtime:
            maxtime = timeBeforeLastDrop


print(drops, rolls, drops/rolls, maxtime)
            

    

    
