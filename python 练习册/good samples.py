# good samples

N,M,K = input().split(" ")
n = int(N) # number of notes
m = int(M) # max note
k = int(K) # number of good samples
maxnum = int(n * (n+1) / 2)
# solution for M = 2
maxnum = n + n-1

def goodSamples():
    if k > maxnum:
        print(-1)
        notes = []
        return
    notes = [1] * n
    if k < n:
        print(-1)
        notes = []
        return
    numextra = int(k - n)
    
    if numextra % 2 == 1:
        notes[len(notes) -1] = 2
        for i in range(int((numextra -1 )/2)):
            notes[i*2 + 1] = 2
    else:
        for i in range(int(numextra/2)):
            notes[i*2+1] = 2
    string = ""
    for i in range(len(notes)):
        string += str(notes[i]) + " "
    print(string)
    return

goodSamples()
