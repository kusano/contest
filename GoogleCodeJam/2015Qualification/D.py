# coding: utf-8

# Problem D. Ominous Omino
# https://code.google.com/codejam/contest/6224486/dashboard#s=p3

# 全てのX-ominoについて、長方形の余った領域が連結になるような置き方ができるかど
# うか調べた。
# Smallは通ったが、Largeは落ちた。解放が間違っているのか、プログラムのバグなのか
# は不明。

Pt = [
#0
[
],

#1
[
"*",
],

#2
[
"**",
"  ",
],

#3
[
"*  ** ",
"*  *  ",
"*     ",
],

#4
[
"*   **  *   *   *   ",
"*   *   **  **  *   ",
"*   *   *    *  *   ",
"*               *   ",
],

#5
[
"*    **   **    **  *    ***  **   ***  *     *   *    **   ",
"*    **   *    **   **    *   *    *    **   ***  **    *   ",
"*    *    *     *    *    *   **   *     **   *   *     **  ",
"*         *          *                            *         ",
"*                                                           ",
],

#6
[
"*     **    *     *     *     **    **    **    *     ***   *     *     *     *     *      *     *     *     *    *     *     **    *     **    **    *     *     ***   * *   * *   *     ***   **    **    **    ",
"*     *     **    *     **    **    *     *     **    *     ***   ****  ****  ****  ****  ****  ****  ***   **    *     **    **    ***   ***    ***  ***   **    * *   ***   ***   ***   **    ***   **     **   ",
"*     *     *     **     *    *     **    *     **    *     *     *      *      *      *    *    *    *     *     **    **    **     *    *       *     *    ***  *     *      *      **  *      *     **     **  ",
"*     *     *     *      *    *     *     **    *     *     *                                         *     **     *     *           *                  *                                                         ",
"*     *     *     *      *                                                                                         *                                                                                              ",
"*                                                                                                                                                                                                                 ",
],
]

P = [[] for _ in range(7)]
for s in range(1,7):
    for p in range(len(Pt[s][0])/s):
        t = []
        for y in range(s):
            for x in range(s):
                if Pt[s][y][s*p+x]=="*":
                    t += [(x,y)]
        P[s] += [tuple(t)]
        
        """
        # rotate and flip
        for d in range(1,8):
            a = []
            for x in t:
                a += [[(1-(d&1)*2)*x[d>>1&1], (1-(d>>2&1)*2)*x[1-(d>>1&1)]]]
            mx = min(x[0] for x in a)
            my = min(x[1] for x in a)
            for x in a:
                x[0] -= mx
                x[1] -= my
            a = tuple([tuple(x) for x in a])
            f = True
            for x in P[s]:
                if set(x)==set(a):
                    f = False
            if f:
                P[s] += [a]
        """

def rotate(p, d):
    r = []
    for a in p:
        r += [[
            (1-(d>>1)*2)*a[d&1],
            (1-(d>>2)*2)*a[d&1^1],
        ]]
    mx = min(a[0] for a in r)
    my = min(a[1] for a in r)
    for a in r:
        a[0] -= mx
        a[1] -= my
    return tuple([tuple(a) for a in r])

def solve(X, R, C):
    if X>=7 or R*C%X!=0:
        return False

    R = min(R, 8)
    C = min(C, 8)

    for p in P[X]:
        ok = False
        
        for d in range(8):
            p = rotate(p, d)
            for y in range(R):
                if y+max(a[1] for a in p) < R:
                    for x in range(C):
                        if x+max(a[0] for a in p) < C:
                            B = [[0]*C for _ in range(R)]
                            for a in p:
                                B[y+a[1]][x+a[0]] = 1

                            def BT(B, x, y):
                                B[y][x] = 2
                                for d in range(4):
                                    tx = x + [0,0,1,-1][d]
                                    ty = y + [1,-1,0,0][d]
                                    if 0<=tx<C and 0<=ty<R and B[ty][tx]==0:
                                        BT(B, tx, ty)
                            for y in range(R):
                                for x in range(C):
                                    if B[y][x]==0:
                                        BT(B, x, y)
                                        break
                                else:
                                    continue
                                break

                            if min(min(b) for b in B)!=0:
                                ok = True
        if not ok:
            return False
    return True

for t in range(input()):
    X, R, C = map(int, raw_input().split())
    print "Case #%s: %s"%(t+1, "GABRIEL" if solve(X,R,C) else "RICHARD")
