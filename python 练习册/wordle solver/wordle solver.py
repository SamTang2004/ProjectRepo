# wordle solver: brute force
# relative consistent solutions based on efficient brute forcing in min.3 rounds?
# Bugs found:
# words like shale, share, shake, sha*e cause prolonged guessing and program
# fails.
#
######################################## preparation and getting first word
# using a TXT file to store all wordle words, the file is obtained from github.
f = open("english words.txt","r")
word = f.readlines()
words = []
for i in range(len(word)):
    if len(word[i].strip()) == 5 and word[i].strip().isalpha():
        words.append(word[i].strip().lower())


# frequencies for individual characters
weights = {"a" : 0.08167, "b":0.01492, "c":0.02782,"d":0.04253,"e":0.12072,"f":0.02228,
           "g": 0.02015,"h":0.06094,"i":0.06966,"j":0.00153,"k":0.00772,
           "l":0.04025,"m":0.02406,
           "n":0.06749,"o":0.07507,"p":0.01929,"q":0.00095,"r":0.05987,
           "s":0.06327,"t":0.09056,"u":0.02758,"v":0.00978,"w":0.02360,
           "x":0.00150,"y":0.01974,"z":0.00074}
# bigrams and corresponding frequencies
segWeights = {'er': 0.189, 'st': 0.123,
              'ra': 0.114, 'ch': 0.103,
              'sh': 0.088, 'se': 0.083,
              'un': 0.079, 'te': 0.088,
              'th': 0.069, 'ma': 0.061,
              'ic': 0.06, 'll': 0.059,
              'ha': 0.059, 'ta': 0.059,
              'ca': 0.056, 'or': 0.098,
              'et': 0.053, 'id': 0.055,
              'de': 0.078, 'sp': 0.05, 'le': 0.094, 'ru':
              0.049, 'tr': 0.048, 'hi': 0.039, 'ou': 0.067,
              'ut': 0.044, 'br': 0.039, 've': 0.08, 'fl': 0.037, 'us': 0.055}
segs = ['er', 'st', 'ra', 'ch', 'sh',
        'se', 'un', 'te', 'th', 'ma',
        'ic', 'll', 'ha', 'ta', 'ca',
        'or', 'et', 'id', 'de', 'sp',
        'le', 'ru', 'tr', 'hi', 'ou',
        'ut', 'br', 've', 'fl', 'us']
# trigrams. Could cause problems
triSegWeights = {'ing': 0.031, 'lly': 0.022,
                 'sta': 0.021, 'tch': 0.019, 'lea': 0.019,
                 'ine': 0.018, 'ate': 0.018, 'sto': 0.018,
                 'sha': 0.018, 'int': 0.015, 'gra': 0.015,
                 'cra': 0.014, 'lan': 0.013, 'eat': 0.013,
                 'eed': 0.013, 'har': 0.013, 'cre': 0.013,
                 'ide': 0.018, 'tal': 0.013, 'ble': 0.013,
                 'own': 0.012, 'ush': 0.012, 'oun': 0.012,
                 'ick': 0.012, 'ump': 0.012, 'sty': 0.012,
                 'igh': 0.012, 'out': 0.018, 'pri': 0.012,
                 'ove': 0.021}
# bigram constant
kSeg = 0.1
# trigram constant
kTri = 1
# a method to get the best opener in a set of words
def getMaxWord(words):
    maxWordWeight = 0
    maxWord = ""
    for i in range(len(words)):
        wordWeight = 0
        for j in list(set(words[i])):
            try:
                wordWeight += weights[j]
            except Exception:
                print(words[i])

        for k in range(len(words[i])-1):
            if words[i][k] + words[i][k+1] in segs:
                wordWeight += segWeights[(words[i][k] + words[i][k+1])] * kSeg
        for k in range(len(words[i]) -2):
            if words[i][k] + words[i][k+1] + words[i][k+2] in triSegWeights:
                wordWeight += triSegWeights[(words[i][k] + words[i][k+1] + words[i][k+2])] * kTri
        if wordWeight > maxWordWeight:
            maxWordWeight = wordWeight
            maxWord = words[i]
    print(maxWordWeight)
    return maxWord

print("first guess: "+ getMaxWord(words))
######################################### cycle begins here
guessed = False
lastGuess = getMaxWord(words)
candidates = words.copy()
guesses = 0
slots = ["","","","",""]
while not guessed:
    if lastGuess in candidates:
        candidates.remove(lastGuess)
    correctness = input("enter accuracy.|g| for green, |y| for yellow, |b| for black, |No| if word is not valid. e.g. ggggg means all correct")
    
    # green is right place/in word, yellow is in word, black is not in word
    if correctness == "ggggg":
        print("Process finished. Target word is: " + lastGuess)
        guessed = True
        break
    guesses += 1
    if correctness == "No":
        candidates.remove(lastGuess)
        print("next guess:" + getMaxWord(candidates))
        lastGuess = getMaxWord(candidates)
        guesses -= 1
        continue


    
    if guesses == 6:
        print("More efficiency required")
        break
    Gs = []
    Ys = []
    Bs = []
    for i in range(len(correctness)):
        if correctness[i] == "g":
            Gs.append((i,lastGuess[i]))
            slots[i] = lastGuess[i]
        if correctness[i] == "y":
            Ys.append((i,lastGuess[i]))
        if correctness[i] == "b":
            Bs.append(lastGuess[i])

    
    # delete those that has black letters in free slots
    indexes = []
    for i in candidates:
        possibility = []
        for k in range(len(slots)):
            if slots[k] == "":
                possibility.append(i[k])
        for j in Bs:
            if j in possibility:
                indexes.append(i)
                break
        
    for i in indexes:
        candidates.remove(i)
    
    #delete those that does not have yellows in them
    indexes = []
    for i in candidates:
        for j in Ys:
            if j[1] not in i:
                indexes.append(i)
                break
            
            if i[j[0]] == j[1]:
                indexes.append(i)
                break
    for i in indexes:
        candidates.remove(i)
    #delete those that does not have greens in them, or greens at incorrect positions
    indexes = []
    for i in candidates:
        for j in Gs:
            if i[j[0]] != j[1]:
                indexes.append(i)
                break
    for i in indexes:
        candidates.remove(i)
    if len(candidates) < 20:
        print("current candidates:" + str(candidates))
    if len(candidates) == 0:
        print("Target word does not exist in library")
        break
    print("next guess: " + getMaxWord(candidates))
    lastGuess = getMaxWord(candidates)
