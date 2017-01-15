# coding: utf-8

# https://www.facebook.com/hackercup/problem/1800890323482794/
# 同じ日により高いパイを買う意味は無いので、各日ごとに値段順でソートして、
# 何個買うかで動的計画法

T = input()
for t in range(T):
    N,M = map(int, raw_input().split())
    oo = N*(M*10**6+M*M)
    T = [0]+[oo]*N
    for n in range(N):
        C = map(int, raw_input().split())
        C.sort()
        P = T
        T = [oo]*(N+1)
        for i in range(M+1):
            a = sum(C[:i])+i*i
            for j in range(N+1):
                if i+j<=N:
                    T[i+j] = min(T[i+j], P[j]+a)
        for j in range(n):
            T[j] = oo
    print "Case #%s: %s" % (t+1, T[N])
