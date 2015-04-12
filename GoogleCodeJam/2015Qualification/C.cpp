//  Problem C. Dijkstra
//  https://code.google.com/codejam/contest/6224486/dashboard#s=p2

//  iとjが作れて、全体の積が-1ならば、残りは常にkになる。
//  Small:
//  積の計算を差分で行うようにすればO((LX)^3)となり間に合う。
//  Large:
//  任意の文字列を4回繰り返すと積が1になることから、調べる長さは4LXで充分。
//  下のコードでは念のため5LXまで見ている。
//  全体の積を求めるためにはバイナリ法を使う。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin>>T;

    for (int t=1; t<=T; t++)
    {
        int L;
        cin>>L;
        long long X;
        cin>>X;
        string s;
        cin>>s;

        //  1, i, j, k, -1, -i, -j, -k
        int Q[8][8] = {
            {0, 1, 2, 3, 4, 5, 6, 7},
            {1, 4, 3, 6, 5, 0, 7, 2},
            {2, 7, 4, 1, 6, 3, 0, 5},
            {3, 2, 5, 4, 7, 6, 1, 0},
            {4, 5, 6, 7, 0, 1, 2, 3},
            {5, 0, 7, 2, 1, 4, 3, 6},
            {6, 3, 0, 5, 2, 7, 4, 1},
            {7, 6, 1, 0, 3, 2, 5, 4},
        };

        int c = 0;
        for (int i=0; i<L; i++)
            c = Q[c][s[i]-'h'];
        int C = 0;
        for (int i=0; i<60; i++)
        {
            if (X>>i&1)
                C = Q[C][c];
            c = Q[c][c];
        }

        bool ans = false;

        string S;
        for (long long i=0; i<min(X, 10LL); i++)
            S += s;

        if (C==4)
        {
            int a=0;
            for (long long i=0; i<L*X && i<5*L && !ans; i++)
            {
                a = Q[a][S[i]-'h'];
                if (a==1)
                {
                    int b = 0;
                    for (long long j=i+1; j<L*X && j-i<5*L && !ans; j++)
                    {
                        b = Q[b][S[j]-'h'];
                        if (b==2)
                            ans = true;
                    }
                }
            }
        }

        cout<<"Case #"<<t<<": "<<(ans?"YES":"NO")<<endl;
    }
}
