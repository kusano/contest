/*
Facebook Hacker Cup 2016 Round 1 Yachtzee
https://www.facebook.com/hackercup/problem/512731402225321/

区間[0, X]についての期待値をf(X)とすると、区間[A, B]の場合は、
　(f(B)B-f(A)A)/(B-A)
となる。各ステップごとに期待値を考えて足し合わせれば良い。
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    for (int t=1; t<=T; t++)
    {
        int N;
        long long A, B;
        cin>>N>>A>>B;
        vector<long long> C(N);
        for (long long &c: C)
            cin>>c;

        long long S = accumulate(C.begin(), C.end(), 0LL);
        
        auto f = [&](long long A) -> double
        {
            double a = 0.;
            long long s = 0;
            for (long long c: C)
            {
                a += (c*.5)*(double((A/S)*c)/A);
                if (s+c<=A%S)
                    a += (c*.5)*(double(c)/A);
                if (s<=A%S && A%S<s+c)
                    a += ((A%S-s)*.5)*(double(A%S-s)/A);
                s += c;
            }
            return a;
        };
        double a = A==0 ? 0.0 : f(A);
        double b = f(B);
        double ans = (b*B - a*A) / (B-A);

        printf("Case #%d: %.16f\n", t, ans);
    }
}
