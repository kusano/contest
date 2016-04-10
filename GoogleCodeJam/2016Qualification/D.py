# coding: utf-8

"""
Google Code Jam 2016 Qualification Round
Problem D. Fractiles
https://code.google.com/codejam/contest/6254486/dashboard#s=p3

問題文に、一度Smallを通したら再投稿はできないと書かれている。SmallはS=Kという条
件だけど返す値はS個未満でも良いので、Largeに挑戦するつもりの人は、Smallで最小個
数を返して動作を確認しろということでしょう。最小個数が本当に最小かの確認はできな
いけど。
1個のタイルを調べると、オリジナルのC個のタイルのうち少なくとも1個が金であったか
どうかを知ることができる。例えば、C=4のとき、最終結果のa+K*(b+K*(c+d*K))番目のタ
イルは、オリジナルのa, b, c, d番目のタイルのうち少なくとも1個が金であるとき、か
つそのときに限り金となる。
"""

def solve(K, C, S):
    ans = []
    k = 0
    while k<K:
        x = 0
        for c in range(C):
            x = K*x + min(k, K-1)
            k += 1
        ans += [x]
    return " ".join(str(a+1) for a in ans) if len(ans)<=S else "IMPOSSIBLE"

for t in range(input()):
    K,C,S = map(int, raw_input().split())
    print "Case #%s: %s" % (t+1, solve(K,C,S))
