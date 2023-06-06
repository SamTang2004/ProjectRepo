def getStartingLoc(source:str, target:str):
    starts = []

    for i in range(len(source) - len(target)+ 1):
        if source[i : i + len(target)] == target:
            starts.append(i)
    
    return starts
print(getStartingLoc("atcatcatc","atc"))
        
