/*
https://www.facebook.com/hackercup/problem/300438463685411/
まず、ワーシャルフロイドで全点対間最短距離を求める。
あとは動的計画法。
ルールを満たすような移動は、
　… → S[i] → D[i] → S[i+1] → …
か、
　… → S[i] → S[i+1] → D[i] → …
しかないので、D[i]に到達したときに、S[i+1]を経由していない場合とした場合それぞれ
の最小のガソリン量を記憶しておく。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int N, M, K;
        cin>>N>>M>>K;

        long long oo = 1000000000000LL;
        vector<vector<long long>> L(N, vector<long long>(N, oo));
        for (int i=0; i<N; i++)
            L[i][i] = 0LL;

        for (int i=0; i<M; i++)
        {
            int A, B;
            long long G;
            cin>>A>>B>>G;
            A--, B--;
            L[A][B] = L[B][A] = min(L[A][B], G);
        }

        vector<int> S(K), D(K);
        for (int i=0; i<K; i++)
        {
            cin>>S[i]>>D[i];
            S[i]--, D[i]--;
        }

        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                for (int k=0; k<N; k++)
                    L[j][k] = min(L[j][k], L[j][i]+L[i][k]);

        vector<vector<long long>> T(K, vector<long long>(2, oo));
        T[0][0] = L[0][S[0]] + L[S[0]][D[0]];
        if (1<K)
            T[0][1] = L[0][S[0]] + L[S[0]][S[1]] + L[S[1]][D[0]];
        for (int i=1; i<K; i++)
        {
            T[i][0] = min(
                T[i-1][0] + L[D[i-1]][S[i]] + L[S[i]][D[i]],
                T[i-1][1] + L[D[i-1]][D[i]]);
            if (i<K-1)
                T[i][1] = min(
                    T[i-1][0] + L[D[i-1]][S[i]] + L[S[i]][S[i+1]] + L[S[i+1]][D[i]],
                    T[i-1][1] + L[D[i-1]][S[i+1]] + L[S[i+1]][D[i]]);
        }

        cout<<"Case #"<<t<<": "<<(T[K-1][0]<oo ? T[K-1][0] : -1LL)<<endl;
    }
}
