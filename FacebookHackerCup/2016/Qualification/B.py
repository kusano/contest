"""
Facebook Hacker Cup 2016 Qualification Round
High Security
https://www.facebook.com/hackercup/problem/1527664744192390/

動的計画法。
T[x][y][z]を、x列目までを考えて、xは上の行の状態、yは下の行の状態とする。
行の状態は、
  0: ここより右にガードが必要
  1: ガードは不要
  2: ここより左にガードがいる
"""

for t in range(input()):
    N = input()
    G = [raw_input() for _ in range(2)]
    T = [[[9999]*3 for i in range(3)] for j in range(N)]
    for i1 in range(2):
     for i2 in range(2):
        if ((G[0][0]=="." or i1==0) and
            (G[1][0]=="." or i2==0)):
            if i1!=0: x1 = 2
            elif G[0][0]!="." or i2!=0: x1 = 1
            else: x1 = 0
            if i2!=0: x2 = 2
            elif G[1][0]!="." or i1!=0: x2 = 1
            else: x2 = 0
            T[0][x1][x2] = min(T[0][x1][x2], i1+i2)
    for i in range(1, N):
        for j1 in range(3):
         for j2 in range(3):
            for k1 in range(2):
             for k2 in range(2):
                if ((G[0][i]=="." or k1==0) and
                    (G[1][i]=="." or k2==0) and
                    (G[0][i]=="." or j1!=0) and
                    (G[1][i]=="." or j2!=0)):
                    if k1!=0 or (G[0][i]=="." and j1==2): x1 = 2
                    elif (G[0][i]!="." or k2!=0) and j1!=0: x1 = 1
                    else: x1 = 0
                    if k2!=0 or (G[1][i]=="." and j2==2): x2 = 2
                    elif (G[1][i]!="." or k1!=0) and j2!=0: x2 = 1
                    else: x2 = 0
                    T[i][x1][x2] = min(T[i][x1][x2], T[i-1][j1][j2]+k1+k2)
    ans = 9999
    for i1 in range(1, 3):
     for i2 in range(1, 3):
        ans = min(ans, T[-1][i1][i2])
    print "Case #%s: %s"%(t+1, ans)
