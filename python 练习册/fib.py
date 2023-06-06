#fib

def fib(k:int,memo:dict):
    if k == 0:
        return 1
    if k == 1:
        return 1
    memo[k] = fib(k-1,memo) + fib(k-2,memo)
    return memo[k]

print(fib(10,{}))
