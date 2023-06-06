#standing sim
wins = 0
losses = 0

# best-cases for him and average cases for me
# his best case is 5 scored in the same bin as me

for i in range(1,7):
    for j in range(1,5):
        selfScore = 240 + 70*i-80
        
        opponentScore = 200+80*j
        
        print("self: " + str(i) + " Opponent: " + str(j) + " selfScore: " +
              str(selfScore) + " OpponenetScore: " + str(opponentScore) +
              " win: " + str(selfScore > opponentScore))
        if selfScore > opponentScore:
            wins += 1
        if selfScore < opponentScore:
            losses += 1
print(wins/(losses + wins))
            
