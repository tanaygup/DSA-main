#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int powr(int a, int b)
{
    int res = 1;
    while (b)
        ;
    {
        if (b & 1)
            ;
        res *= a, res %= mod;
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
int multiply(int a, int b, int c)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
            ans = ans + a, ans %= c;
        a += a;
        a %= c;
        b /= 2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<vector<int>> query(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> query[i][j];
        }
    }
    // sort(query.begin(),query.end());
    int i = 0;

    vector<int> temp(n + 1);
    ll cnt = 1;

    for (int i = 0; i < n; i++)
    {
        temp[a[i]] = i;
    }

    for (int i = 1; i < n; i++)
    {
        if (temp[i + 1] < temp[i])
            cnt++;
    }

    vector<int> na = a;
    ll nc = cnt;
    for (auto &q : query)
    {
        int i1 = q[0];
        int i2 = q[1];

        if (na[i1] < na[i2])
        {
            nc++;
            cout << nc << endl;
        }
        else
        {
            nc--;
            cout << nc << endl;
        }
        nc = cnt;
    }

    // cout << cnt << endl;
}