# coding: utf-8

"""
Google Code Jam 2016 Qualification Round
Problem B. Revenge of the Pancakes
https://code.google.com/codejam/contest/6254486/dashboard#s=p1

---や+++の塊の途中で裏返す意味は無いので、圧縮して考える。そうすると、
　-, +, -+, +-, -+-, +-+, …
だけを考えれば良い。これを手でDPしてみると、最初が+ならば(長さ)*2、最初が-ならば
(長さ)*2+1となることが分かる。
"""

for t in range(input()):
    S = raw_input()
    ans = S.count("+-")*2 + int(S[0]=="-")
    print "Case #%s: %s" % (t+1, ans)
