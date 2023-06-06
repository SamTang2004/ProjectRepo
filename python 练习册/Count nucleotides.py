f = open("rosalind_dna.txt", "r")
lines = f.readlines()
lines = lines[0].strip()
lines = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"
print(lines.count("A"))
print(lines.count("C"))
print(lines.count("G"))
print(lines.count("T"))



