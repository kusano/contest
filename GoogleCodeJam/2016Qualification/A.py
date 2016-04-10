# coding: utf-8

"""
Google Code Jam 2016 Qualification Round
Problem A. Counting Sheep
https://code.google.com/codejam/contest/6254486/dashboard#s=p0

N=0の場合は不眠症。N>0の場合はそんなに時間がかからずに、常に眠れそうだと予想は付
く。LargeでもN≦10^6なので、全部試して解が出ることを確認してから、問題をダウンロ
ードすれば良い。
"""

def solve(N):
    if N==0:
        return "INSOMNIA"
    d = set()
    i = 1
    while True:
        d |= set(str(i*N))
        if len(d)==10:
            return i*N
        i += 1

for t in range(input()):
    N = input()
    print "Case #%s: %s" % (t+1, solve(N))
