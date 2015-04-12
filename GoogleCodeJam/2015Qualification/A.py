# coding: utf-8

# Problem A. Standing Ovation
# https://code.google.com/codejam/contest/6224486/dashboard#s=p0

# 足りない人数を加えていく

for t in range(input()):
    s = map(int, list(raw_input().split()[1]))
    ans = 0
    n = 0
    for i in range(len(s)):
        ans += max(i-n, 0)
        n += max(i-n, 0)
        n += s[i]
    print "Case #%d: %d"%(t+1, ans)
