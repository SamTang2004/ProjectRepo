# reverse complement
def reverseComplement(strand: str):
    comp = ""
    for i in strand:
        if i == "a":
            comp += "t"
        if i == "t":
            comp += "a"
        if i == "c":
            comp += "g"
        if i == "g":
            comp += "c"
    return comp

print(reverseComplement("gtgcttccaattgacatcttcagcgcctattgcgctggccaaggtgacggagcgggattacgaaagcatgatcatggctgttgttctgtttatcttgttttgactgagacttgttaggatagacggtttttcatcactgactagcc"))
    
