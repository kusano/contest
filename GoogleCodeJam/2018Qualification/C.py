# coding: utf-8
"""
Go, Gopher!
https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/0000000000007a30

67x3の長方形を作れば良い。
ある場所を指定して、その場所の左3マスに耕されていない場所があれば、同じ場所を指示し続ける。
"""

import sys

T = input()
for _ in range(T):
  A = input()
  p = 2
  S = set()
  while True:
    print p, 2
    sys.stdout.flush()
    i,j = map(int, raw_input().split())
    if (i, j) == (0, 0):
      break
    S.add((i, j))
    if p<66 and (p-1, 1) in S and (p-1, 2) in S and (p-1, 3) in S:
      p += 1
