# Mendel's First Law
k = 28 # AA
m = 18 # Aa
n = 28 # aa
K = []
M = []
N = []
for i in range(k):
    K.append(("AA"))
for i in range(m):
    M.append(("Aa"))
for i in range(n):
    N.append(("aa"))
# return prob of any organism that produces a dominant allele
# prob of k + k : 100% with AA -> 100% contains A
# prob of k + m : 50% AA, 50% Aa -> 100% contains A
# prob of k + n : 100% with Aa -> 100% contains A
# prob of m + m : 75% contains A
# prob of m + n : 50% contains A
# prob of n + n : 0% contains A
As = 0
count = 0
def r(AA,Aa,aa,selection,memo:dict):
    global As
    global count
    if len(selection) == 2:
        
        count += 1
        if str(selection) in memo:
            As += memo[str(selection)]
            return
        if "AA" in selection:
            As += 4
            memo[str(selection)] = 4 
        elif ("Aa" in selection) and ("aa" in selection):
            As += 2
            memo[str(selection)] = 2
        elif ("Aa" in selection):
            As += 3
            memo[str(selection)] = 3
        return

    if len(AA) >= 1:
        for i in AA:
            newAA = AA.copy()
            newAA.remove(i)
            r(newAA, Aa, aa, selection + [i],memo)
    if len(Aa) >= 1:
        for i in Aa:
            newAa = Aa.copy()
            newAa.remove(i)
            r(AA, newAa, aa, selection + [i],memo)
    if len(aa) >= 1:
        for i in aa:
            newaa = aa.copy()
            newaa.remove(i)
            r(AA, Aa, newaa, selection + [i],memo)
r(K,M,N,[],{})
print(As/2)
print(count * 2)
print((As/2) / count / 2)
            


