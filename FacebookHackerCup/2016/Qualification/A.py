"""
Facebook Hacker Cup 2016 Qualification Round
Boomerang Constellations
https://www.facebook.com/hackercup/problem/910374079035613/

3個の星の全ての組み合わせを試そうとすると、O(N^3)で間に合わない。
ある星を中心とするブーメラン座を考える。
この星から等しい距離にk個の星があるならば、このうちの2個と中心の星で1個のブーメ
ラン座ができるので、ブーメラン座の個数はk(k-1)/2。
等しい距離の星を数えるのは、辞書を用いるとO(N log N)でできる。
浮動小数点では誤差があるので距離は2乗して考える。
これを全ての星を中心として考えれば良い。
O(N^2 log N)。
"""

from collections import *

for t in range(input()):
    N = input()
    X = [0]*N
    Y = [0]*N
    for i in range(N):
        X[i],Y[i] = map(int, raw_input().split())
    ans = 0
    for i in range(N):
        A = defaultdict(int)
        for j in range(N):
            if j!=i:
                A[(X[j]-X[i])**2+(Y[j]-Y[i])**2] += 1
        for a in A.values():
            ans += a*(a-1)/2
    print "Case #%s: %s" % (t+1, ans)
