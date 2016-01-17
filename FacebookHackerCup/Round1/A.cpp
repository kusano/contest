/*
Facebook Hacker Cup 2016 Round 1 Coding Contest Creation
https://www.facebook.com/hackercup/problem/798506286925018/

既存の問題が使えない場合は、貪欲に難易度+10の問題を追加すれば良い。難易度が100を
超えてしまうこともあるけれど、この場合は同じ問題数で他の難易度設定があるはず。
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int N;
        cin>>N;
        vector<int> D(N);
        for (int &d: D)
            cin>>d;
        int ans = 0;
        int p = 0;
        while (p<N)
        {
            int x = D[p++];
            for (int i=0; i<3; i++)
            {
                if (p>=N || D[p]<=x || x+10<D[p])
                    x += 10,
                    ans++;
                else
                    x = D[p++];
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
}

