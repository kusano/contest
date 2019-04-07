# coding: utf-8

"""
https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
基本的にA=Nとし、4が出てきたらA=B=2とする。
"""

T = input()
for t in range(T):
  N = input()
  A = 0
  B = 0
  d = 1
  while N>0:
    if N%10==4:
      A += 2*d
      B += 2*d
    else:
      A += N%10*d
    N /= 10
    d *= 10
  print "Case #%s: %s %s" % (t+1, A, B)
