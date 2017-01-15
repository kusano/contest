/*
Facebook Hacker Cup 2016 Round 1 Boomerang Tournament
https://www.facebook.com/hackercup/problem/1424196571244550/

変わったトーナメントだが、N=2^Kという制約の下では通常のトーナメントと変わらない。
トーナメントなので、ありうる順位は1, 2, 3, …, 2^k+1。
最低順位は誰にも負けないなら1位、誰かに負けるなら初戦でその人に負けることを考え
ると最下位になる。
最高順位はビットDPで求める。トーナメント名がヒント？　A[a][b]を参加者aの中でbが1
位になれるかどうかを表す。ある集団aの中でaiが1位になれて、別の集団bの中でbiが1位
になれ、aiがbiに勝てるならば、aiはa∪bの中で1位になれる。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countbit(int n) {int c=0; while(n)c+=n&1,n>>=1; return c;}

int main()
{
    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int N;
        cin>>N;
        vector<vector<bool>> W(N, vector<bool>(N));
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            int t;
            cin>>t;
            W[i][j] = t!=0;
        }

        int K=0;
        while ((1<<K) < N)
            K++;

        vector<int> num2rank(N+1);
        for (int k=0; k<K; k++)
            num2rank[1<<k] = (1<<(K-k-1))+1;
        num2rank[1<<K] = 1;

        vector<vector<bool>> A(1<<N, vector<bool>(N));
        for (int i=0; i<N; i++)
            A[1<<i][i] = true;
        for (int k=0; k<K; k++)
        {
            for (int b=0; b<(1<<N); b++)
            if (countbit(b) == (1<<k))
            {
                int m = ((1<<N)-1) ^ b;
                for (int c=m; c>0; c=(c-1)&m)
                if (countbit(c) == (1<<k))
                {
                    for (int bi=0; bi<N; bi++)
                    if (b>>bi&1)
                    for (int ci=0; ci<N; ci++)
                    if (c>>ci&1)
                    {
                        if (A[b][bi] && A[c][ci] && W[bi][ci])
                            A[b|c][bi] = true;
                    }
                }
            }
        }

        printf("Case #%d:\n", t);
        for (int i=0; i<N; i++)
        {
            int best = N;
            for (int j=0; j<(1<<N); j++)
                if (A[j][i])
                    best = min(best, num2rank[countbit(j)]);
            int worst = 1;
            for (int j=0; j<N; j++)
                if (W[j][i])
                    worst = num2rank[1];
            printf("%d %d\n", best, worst);
        }
    }
}
