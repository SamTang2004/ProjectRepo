# most frequent K-Mer

def getMostFrq(source:str, length:int):
    # int < len(source)

    item = []
    frq = []
    
    for i in range(len(source) - length + 1):
        if source[i : i + length] not in item:
            item.append(source[i : i + length])
            frq.append(0)
        else:
            frq[item.index(source[i : i + length])] += 1

    # get max and output in a list
    maxs= []
    for i in range(len(frq)):
        if frq[i] == max(frq):
            maxs.append(i)
    product = []
    for i in maxs:
        product.append((item[i], frq[i]))
    
    
    
        
    return product

print(getMostFrq("CGATATATCCATAG",3))
print(getMostFrq("aactctatacctcctttttgtcgaatttgtgtgatttatagagaaaatcttattaactgaaactaaaatggtaggtttggtggtaggttttgtgtacattttgtagtatctgatttttaattacataccgtatattgtattaaattgacgaacaattgcatggaattgaatatatgcaaaacaaacctaccaccaaactctgtattgaccattttaggacaacttcagggtggtaggtttctgaagctctcatcaatagactattttagtctttacaaacaatattaccgttcagattcaagattctacaacgctgttttaatgggcgttgcagaaaacttaccacctaaaatccagtatccaagccgatttcagagaaacctaccacttacctaccacttacctaccacccgggtggtaagttgcagacattattaaaaacctcatcagaagcttgttcaaaaatttcaatactcgaaacctaccacctgcgtcccctattatttactactactaataatagcagtataattgatctga,",9))

