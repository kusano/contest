/*
Facebook Hacker Cup 2016 Round 1 Laundro, Matt
https://www.facebook.com/hackercup/problem/1611251319125133/

洗濯機は選択終了時刻がもっとも遅いものを使えば良い。優先度付きキューを使えば、1
回の操作はO(log n)で行える。乾燥機は洗濯終了時刻と、前の乾燥が終了する時刻の遅い
ほうから時間Dが掛かる。乾燥機は全て所要時間が同じなので、前の乾燥が終了する時刻
（乾燥開始時刻）で管理しても問題無い。乾燥機の台数は最大10^9だが、洗濯物の個数よ
り多くても意味が無いし、優先度付きキューで管理しきれないので、minを取る。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int L, N, M;
        long long D;
        cin>>L>>N>>M>>D;
        vector<long long> W(N);
        for (long long &w: W)
            cin>>w;

        M = min(M, L);
        priority_queue<pair<long long, int>> wash;
        for (int i=0; i<N; i++)
            wash.push(make_pair(-W[i], i));
        priority_queue<long long> dry;
        for (int i=0; i<M; i++)
            dry.push(0);

        long long ans = 0;

        for (int l=0; l<L; l++)
        {
            pair<long long, int> w = wash.top();
            wash.pop();

            long long d = dry.top();
            dry.pop();

            long long a = min(w.first, d) - D;
            ans = max(ans, -a);

            w.first -= W[w.second];
            wash.push(w);

            dry.push(a);
        }

        printf("Case #%d: %lld\n", t, ans);
    }
}
