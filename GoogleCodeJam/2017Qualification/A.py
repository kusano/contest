def solve(S, K):
    S = list(S)
    ans = 0
    for i in range(len(S)-K+1):
        if S[i]=="-":
            for j in range(K):
                if S[i+j]=="-":
                    S[i+j] = "+"
                else:
                    S[i+j] = "-"
            ans += 1
    for i in range(K):
        if S[-i]=="-":
            ans = "IMPOSSIBLE"
    return ans

for t in range(input()):
    S, K = raw_input().split()
    print "Case #%s: %s" % (t+1, solve(S, int(K)))
