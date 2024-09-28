#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int powr(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
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
    int n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll l = 1ll;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > l)
        {
            cout << l << endl;
            flag = false;
            break;
        }
        l += v[i];
    }
    if (flag)
        cout << l << endl;
}