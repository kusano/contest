# coding: utf-8

"""
L[x]とL[x+1]が異なるならば、L[x]=ab, L[x+1]=bcと表せる。
L[x]とL[x+1]から最大公約数を求めるとbとなる。
全ての文字が少なくとも1回は現われるという問題の制約から、
これによって26個の素数が得られる。

平文の1文字を2通り試し、最後まで文字が決められるほうが答え。
この問題の制約では、ABABABのような答えが一意に定まらない平文は入力にならない。
"""

from fractions import gcd

T = input()
for t in range(T):
  N, L = map(int, raw_input().split())
  C = map(int, raw_input().split())

  F = []
  for i in range(L-1):
    if C[i]!=C[i+1]:
      f = gcd(C[i], C[i+1])
      F += [C[i]/f, f, C[i+1]/f]
  F = sorted(list(set(F)))

  P = [None for _ in range(L)]
  for i in range(L):
    for f in F:
      if C[i]%f==0:
        P[i] = [
          chr(ord("A")+F.index(f)),
          chr(ord("A")+F.index(C[i]/f)),
        ]

  for i in range(2):
    ans = P[0][i]
    p = P[0][i]
    for j in range(L):
      if p==P[j][0]:
        ans += P[j][1]
        p = P[j][1]
      elif p==P[j][1]:
        ans += P[j][0]
        p = P[j][0]
      else:
        break
    if len(ans)==L+1:
      break
  print "Case #%s: %s" % (t+1, ans)
