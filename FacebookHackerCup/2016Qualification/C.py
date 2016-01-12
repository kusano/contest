"""
Facebook Hacker Cup 2016 Qualification Round
The Price is Correct
https://www.facebook.com/hackercup/problem/881509321917182/

尺とり法で、各位置rについて、sum(B[l:r])がP以下で、sum(B[l+1:r])がPを超えるよう
な位置lを求める。
これより短ければ常に合計はP以下となるので、その個数を足し合わせれば良い。
"""

for t in range(input()):
    N,P = map(int, raw_input().split())
    B = map(int, raw_input().split())
    ans = 0
    l = 0
    s = 0
    for r in range(N):
        s += B[r]
        while s>P:
            s -= B[l]
            l += 1
        ans += r-l+1
    print "Case #%s: %s"%(t+1, ans)
