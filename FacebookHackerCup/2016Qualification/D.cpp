/*
Facebook Hacker Cup 2016 Qualification Round
Text Editor
https://www.facebook.com/hackercup/problem/1525154397757404/

問題ではN個中K個の単語を選ぶ必要があるが、まずはK個の単語が決まったとして、どの
ような順番で入力すれば良いかを考える。
直感的には辞書順に並べれば良さそう。
実際これは正しい。
操作数を最小にするには、1文字目がa, 1文字目がb, …の単語をそれぞれまとめて入力
すれば良い。
1文字目がaの単語の中では、同様に2文字目がa, 2文字目がbの単語をまとめる。
辞書順に並べた列はこの条件を満たす。

順番さえ決まってしまえば、あとは動的計画法で解ける。
現在の単語を入力するのに必要な操作数は直前に入力した単語にのみ依存する。
T[x][y][z]を、（ソートした単語の）x個までから、y-1個を使い、z番目の単語を最後に
入力した場合の文字数として、この表を埋めれば良い。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int N, K;
        cin>>N>>K;
        vector<string> W(N);
        for (string &w: W)
            cin>>w;
        sort(W.begin(), W.end());

        vector<vector<int>> P(N, vector<int>(N));
        for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            int c = 0;
            while (c<(int)W[i].size() &&
                   c<(int)W[j].size() &&
                   W[i][c]==W[j][c])
                c++;
            P[i][j] = (int)W[i].size() + (int)W[j].size() - 2*c;
        }

        vector<vector<vector<int>>> A(N, vector<vector<int>>(N, vector<int>(N, 99999999)));
        A[0][0][0] = (int)W[0].size()+1;
        for (int i=1; i<N; i++)
        {
            for (int k=0; k<i; k++)
                A[i][0][k] = min(A[i][0][k], A[i-1][0][k]);
            A[i][0][i] = min(A[i][0][i], (int)W[i].size()+1);

            for (int j=1; j<=i; j++)
            {
                for (int k=0; k<i; k++)
                    A[i][j][k] = min(A[i][j][k], A[i-1][j][k]);
                for (int k=0; k<i; k++)
                    A[i][j][i] = min(A[i][j][i], A[i-1][j-1][k]+(int)P[i][k]+1);
            }
        }

        int ans = 99999999;
        for (int i=0; i<N; i++)
            ans = min(ans, A[N-1][K-1][i] + (int)W[i].size());

        printf("Case #%d: %d\n", t, ans);
    }
}
