# coding: utf-8

"""
https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da

1. PがE...Sならば、SS...SEE...E
2. PがS...Eならば、EE...ESS...S
3. PがE...Eならば、SS...SEE...ESS...S
4. PがS...Sならば、EE...ESS...SEE...E
を出力する。

3のとき、Pの中でSが2個連続する行が少なくとも1個あるはずなので、そこでEを出力する。
4も同様。
"""

T = input()
for t in range(T):
  N = input()
  P = raw_input()
  if P[0]=="E" and P[-1]=="S":
    ans = "S"*(N-1)+"E"*(N-1)
  if P[0]=="S" and P[-1]=="E":
    ans = "E"*(N-1)+"S"*(N-1)
  if P[0]=="E" and P[-1]=="E":
    c = 0
    for i in range(len(P)):
      if P[i]=="S":
        c += 1
      if P[i:i+2]=="SS":
        ans = "S"*c+"E"*(N-1)+"S"*(N-c-1)
        break
  if P[0]=="S" and P[-1]=="S":
    c = 0
    for i in range(len(P)):
      if P[i]=="E":
        c += 1
      if P[i:i+2]=="EE":
        ans = "E"*c+"S"*(N-1)+"E"*(N-c-1)
        break
  print "Case #%s: %s" % (t+1, ans)
