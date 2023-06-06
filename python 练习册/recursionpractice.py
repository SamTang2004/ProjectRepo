diff = 0.63
shutoff = 0
#quarters = 0.25, dimes = 0.1,nickels = 0.05, pennies = 0.01
def r(q,d,n,p,k):
    currentSum = q*0.25 + d*0.1 + n*0.05 + p*0.01
    if currentSum == diff and k == 0:
        print ([q,d,n,p])
        return [q,d,n,p]
    if currentSum > diff:
        return
    if k == 0:
        return
    if k>=1:
        r(q+1,d,n,p,k-1)
        r(q,d+1,n,p,k-1)
        r(q,d,n+1,p,k-1)
        r(q,d,n,p+1,k-1)
    return
r(0,0,0,0,6)
#0,3,5,8
