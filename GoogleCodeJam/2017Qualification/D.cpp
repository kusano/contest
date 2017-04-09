#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

vector<vector<int>> maxflow(vector<vector<int>> E_, vector<vector<int>> F_, int s, int t)
{
    int n = (int)E_.size();

    vector<vector<int>> E(n), F(n), R(n);
    for (int i=0; i<n; i++)
    for (int j=0; j<(int)E_[i].size(); j++)
    {
        int v = E_[i][j];
        R[i].push_back(int(E[v].size()));
        R[v].push_back(int(E[i].size()));
        E[i].push_back(v);
        E[v].push_back(i);
        F[i].push_back(F_[i][j]);
        F[v].push_back(0);
    }
    
    vector<vector<int>> Forg = F;

    vector<bool> U(n);
    function<int (int, int)> dfs = [&](int p, int f)
    {
        if (p==t)
            return f;
        U[p] = true;
        for (int i=0; i<(int)E[p].size(); i++)
        if (!U[E[p][i]] && F[p][i]>0)
        {
            int t = dfs(E[p][i], min(f, F[p][i]));
            if (t>0)
            {
                F[p][i] -= t;
                F[E[p][i]][R[p][i]] += t;
                return t;
            }
        }
        return 0;
    };

    int flow = 0;
    while (true)
    {
        for (int i=0; i<n; i++)
            U[i] = false;
        int f = dfs(s, 0x7fffffff);
        if (f==0)
            break;
        flow += f;
    }

    vector<vector<int>> result;
    for (int i=0; i<n; i++)
        for (int j=0; j<(int)F[i].size(); j++)
            if (F[i][j]<Forg[i][j])
                result.push_back(vector<int>{i, E[i][j]});

    return result;
}

vector<vector<int>> bipartite(vector<vector<int>> M)
{
    int n = (int)M.size();
    int m = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<(int)M[i].size(); j++)
            m = max(m, M[i][j]+1);

    vector<vector<int>> E(n+m+2), F(n+m+2);

    for (int i=0; i<n; i++)
    for (int j=0; j<(int)M[i].size(); j++)
        E[i].push_back(n+M[i][j]),
        F[i].push_back(1);
    for (int i=0; i<n; i++)
        E[n+m].push_back(i),
        F[n+m].push_back(1);
    for (int i=0; i<m; i++)
        E[n+i].push_back(n+m+1),
        F[n+i].push_back(1);

    vector<vector<int>> result = maxflow(E, F, n+m, n+m+1);
    vector<vector<int>> result2;
    for (int i=0; i<(int)result.size(); i++)
    {
        int a = result[i][0];
        int b = result[i][1];
        if (a==n+m || a==n+m+1 || b==n+m || b==n+m+1)
            continue;
        if (a>b)
            swap(a, b);
        b -= n;
        result2.push_back({a, b});
    }

    return result2;
}

int main()
{
    int T;
    cin>>T;
    for (int test=1; test<=T; test++)
    {
        int N, M;
        cin>>N>>M;
        vector<string> Borg(N, string(N, '.'));
        vector<bool> C1(N, true), C2(N, true), D1(2*N-1, true), D2(2*N-1, true);
        for (int i=0; i<M; i++)
        {
            char a;
            int r, c;
            cin>>a>>r>>c;
            r--, c--;
            Borg[r][c] = a;
            if (a=='o' || a=='x')
                C1[r] = C2[c] = false;
            if (a=='o' || a=='+')
                D1[r+c] = D2[r-c+N-1] = false;
        }

        vector<string> Bans = Borg;
        vector<vector<int>> P(N);
        for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            if (C1[r] && C2[c])
                P[r].push_back(c);
        vector<vector<int>> R = bipartite(P);
        for (auto res: R)
        {
            int r = res[0];
            int c = res[1];
            Bans[r][c] = Bans[r][c]=='.' ? 'x' : 'o';
        }
        P = vector<vector<int>>(2*N-1);
        for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            if (D1[r+c] && D2[r-c+N-1])
                P[r+c].push_back(r-c+N-1);
        R = bipartite(P);
        for (auto res: R)
        {
            int r = (res[0] + res[1] - N + 1)/2;
            int c = res[0] - r;
            Bans[r][c] = Bans[r][c]=='.' ? '+' : 'o';
        }

        int ans = 0;
        int cnt = 0;
        for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
        {
            if (Bans[r][c]=='o')
                ans+=2;
            if (Bans[r][c]=='+' || Bans[r][c]=='x')
                ans++;
            if (Bans[r][c] != Borg[r][c])
                cnt++;
        }
        //for (auto b: Borg)
        //    cout<<b<<endl;
        //cout<<endl;
        //for (auto b: Bans)
        //    cout<<b<<endl;
        cout<<"Case #"<<test<<": "<<ans<<" "<<cnt<<endl;
        for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            if (Bans[r][c] != Borg[r][c])
                cout<<Bans[r][c]<<" "<<r+1<<" "<<c+1<<endl;
    }
}
