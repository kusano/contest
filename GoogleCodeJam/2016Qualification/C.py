# coding: utf-8

"""
Google Code Jam 2016 Qualification Round
Problem C. Coin Jam
https://code.google.com/codejam/contest/6254486/dashboard#s=p2

"unusually for a Code Jam problem"で入力が固定なので、手元で試してみることができ
る。素直に探していくコードだと候補が素数のときにとても遅くなったから、d<=100で打
ち切ることにしたら、すぐに答えが出た。
"""

def solve(N, J):
    j = 0
    c = 0
    while j<J:
        t = "1"+format(c, "b").zfill(N-2)+"1"
        D = []
        for b in range(2, 11):
            a = int(t, b)
            d = 2
            while d*d<=a and d<=100:
                if a%d==0:
                    D += [d]
                    break
                d += 1
            else:
                break
        if len(D)==9:
            print t, " ".join(map(str, D))
            j += 1
        c += 1

for t in range(input()):
    N,J = map(int, raw_input().split())
    print "Case #%s:" % (t+1)
    solve(N, J)
