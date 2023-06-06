# secondary and tertiary strucures of DNA
# reverse compliment


DNA = open("rosalind_revc.txt","r").readlines()[0].strip()

product = ""

for i in DNA:
    if i == "A":
        product += "T"
    if i == "C":
        product += "G"
    if i == "G":
        product += "C"
    if i == "T":
        product += "A"

print(product[::-1])
