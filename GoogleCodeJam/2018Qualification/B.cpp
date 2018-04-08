/*
Trouble Sort
https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb

Trouble Sortが何をしているのかというと、偶数番目の要素と奇数番目の要素それぞれのソートである。
偶数番目の要素と奇数番目の要素が入れ替わることは無いし、それぞれはソートが完了する。
Trouble Sortが完了した配列を実際に作って、間違っている場所を探せば良い。
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
        int N;
        cin>>N;
        vector<int> V(N);
        for (int &v: V)
            cin>>v;
        vector<int> E, O;
        for (int i=0; i<N; i++)
            (i%2==0 ? E : O).push_back(V[i]);
        sort(E.begin(), E.end());
        sort(O.begin(), O.end());
        for (int i=0; i<N; i++)
            V[i] = (i%2==0 ? E : O)[i/2];
        int ans = -1;
        for (int i=N-2; i>=0; i--)
            if (V[i] > V[i+1])
                ans = i;
        cout<<"Case #"<<t<<": ";
        if (ans>=0)
            cout<<ans<<endl;
        else
            cout<<"OK"<<endl;
    }
}
