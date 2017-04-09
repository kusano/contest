def solve(N):
    ans = 0
    if list(str(N))==sorted(str(N)):
        ans = N
    d = 1
    while d<=N:
        if N/d%10!=0:
            t = N-N%d-1
            if list(str(t))==sorted(str(t)):
                ans = max(ans, t)
        
        d *= 10
    return ans

for t in range(input()):
    N = input()
    print "Case #%s: %s" % (t+1, solve(N))
