# coding: utf-8
"""
Saving The Universe Again
https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard

CCとSSの交換には意味が無い。
SCをCSにするとダメージが増える。
ダメージが減るのはCSをSCにする交換である。
また、なるべく右にあるCSを交換するほど減少量が大きい。
ダメージがD以下になるまで最右のCSを交換することを繰り返せば答えが求まる。
"""

T = input()
for t in range(T):
  D,P = raw_input().split()
  D = int(D)
  P = list(P)
  ans = 0
  while True:
    d = 0
    s = 1
    for p in P:
      if p == "C":
        s *= 2
      else:
        d += s
    if d<=D:
      break
    for i in range(len(P)-1)[::-1]:
      if P[i:i+2]==["C","S"]:
        P[i:i+2] = ["S", "C"]
        break
    else:
      ans = "IMPOSSIBLE"
      break
    ans += 1
  print "Case #%d: %s" % (t+1, ans)
