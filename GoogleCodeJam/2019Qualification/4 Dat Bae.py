# coding: utf-8

"""
https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881de

1 ≤ B ≤ min(15, N-1).
F = 5.
という制約から、2^xが出てくる解法なのだと予想が付く。

TEST_STORE 01010101010101010101010101010101...
TEST_STORE 00110011001100110011001100110011...
TEST_STORE 00001111000011110000111100001111...
TEST_STORE 00000000111111110000000011111111...

というクエリの返り値は15個以下の連続した故障を検出できる。
"""

from sys import stdout

T = input()
for t in range(T):
  N, _B, _F = map(int, raw_input().split())

  R = []
  for i in range(4):
    q = ""
    for j in range(N):
      q += str(j>>i&1)
    print q
    stdout.flush()
    R += [raw_input()]

  ans = []
  p = 0
  for i in range(N):
    if p<len(R[0]):
      ok = True
      for j in range(4):
        if R[j][p]!=str(i>>j&1):
          ok = False
    else:
      ok = False
    if ok:
      p += 1
    else:
      ans += [i]
  print " ".join(map(str, ans))
  stdout.flush()
  input() # 1
