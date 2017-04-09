def solve(N, K):
    S = {N: 1}
    while True:
        s = sorted(S.keys())[-1]
        n = S[s]
        del S[s]
        L = (s-1)/2
        R = s/2
        if n>=K:
            return max(L,R), min(L,R)
        K -= n
        if L not in S:
            S[L] = 0
        S[L] += n
        if R not in S:
            S[R] = 0
        S[R] += n

for t in range(input()):
    N,K = map(int, raw_input().split())
    print "Case #%s: %s %s" % ((t+1,)+solve(N, K))
