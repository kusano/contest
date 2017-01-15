/*
https://www.facebook.com/hackercup/problem/1760870734198100/
左端にグループx、右端にグループyのビーチパラソルを置くことを考えると、ビーチの空
きは、
　m = M-R[x]-R[y]-(sum(R)-R[x]-R[y])*2
となる。
このときのビーチパラソルの置き方は、両端以外は自由な順番で並べられるので、
　C(m+N, N) * (N-2)!
となる。
両端のグループを素直に探索すると、O(N^3)で間に合わないが、Rの最大値が小さいので、
R[x]+R[y]ごとに置き方の数を事前に求めておけば良い。
O(max(R)N+N^2)。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long powmod(long long a, long long b, long long m)
{
    long long r = 1;
    for (; b>0; b>>=1, a=a*a%m)
        if (b&1)
            r = r*a%m;
    return r;
}

int main()
{
    long long mod = 1000000007LL;

    int T;
    cin>>T;
    for (int t=1; t<=T; t++)
    {
        int N;
        long long M;
        cin>>N>>M;
        vector<long long> R(N);
        for (int i=0; i<N; i++)
            cin>>R[i];

        long long sum = 0LL;
        for (int i=0; i<N; i++)
            sum += R[i];

        long long ans;
        if (N==1)
        {
            ans = M;
        }
        else
        {
            long long T[4001];

            for (int r=2; r<=4000; r++)
            {
                long long m = M - r - (sum-r)*2 - 1;
                if (m<0)
                {
                    T[r] = 0LL;
                }
                else
                {
                    long long tmp = 1LL;
                    for (int i=0; i<N; i++)
                        tmp *= m+i+1,
                        tmp %= mod;
                    tmp *= powmod(N, mod-2, mod);
                    tmp %= mod;
                    tmp *= powmod(N-1, mod-2, mod);
                    tmp %= mod;
                    T[r] = tmp;
                }
            }

            ans = 0;
            for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            if (i!=j)
                ans += T[R[i]+R[j]],
                ans %= mod;
        }
                
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
