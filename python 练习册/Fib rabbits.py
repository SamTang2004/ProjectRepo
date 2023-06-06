# fibonacci rabbits

def r(n, k,memo):
    if n in memo:
        return memo[n]
    if n == 0:
        return 1
    if n == 1:
        return 1
    memo[n] = r(n-1,k,{}) + r(n-2,k,{}) * k
    return memo[n]

n = 32
k = 5
print(r(n-1,k,{}))
