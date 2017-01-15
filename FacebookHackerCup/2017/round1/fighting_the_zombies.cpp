/*
https://www.facebook.com/hackercup/problem/235709883547573/
辺の長さRの正方形2個で倒せるゾンビの数を最大化すれば良い。
どのような正方形の配置でも正方形を重ねるような移動法が存在する。
正方形は左端と下端にそれぞれゾンビが存在するような位置を探索すれば充分。
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
        int N, R;
        cin>>N>>R;
        vector<int> X(N), Y(N);
        for (int i=0; i<N; i++)
            cin>>X[i]>>Y[i];
        int ans = 0;
        for (int x1=0; x1<N; x1++)
        for (int y1=0; y1<N; y1++)
        for (int x2=0; x2<N; x2++)
        for (int y2=0; y2<N; y2++)
        {
            int c = 0;
            for (int i=0; i<N; i++)
                if (X[x1]<=X[i] && X[i]<=X[x1]+R && Y[y1]<=Y[i] && Y[i]<=Y[y1]+R ||
                    X[x2]<=X[i] && X[i]<=X[x2]+R && Y[y2]<=Y[i] && Y[i]<=Y[y2]+R)
                    c++;
            ans = max(ans, c);
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
