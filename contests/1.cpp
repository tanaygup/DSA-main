#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

const ld pi = acos(-1);
const ll MOD = 1000000007;
const ll N = 1e5 + 7;

typedef vector<long long> vll;
#define pb push_back
#define sz(x) ((int)(x).size())

vll factors(int n)
{
    vll ans;
    int l = sqrt(n);
    for (int i = 1; i <= l; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                ans.pb(i);
            else
            {
                ans.pb(i);
                ans.pb(n / i);
            }
        }
    }
    return ans;
}
string DecimalToBinary(ll num)
{
    string str;
    while (num)
    {
        if (num & 1)
            str.pb('1');
        else
            str.pb('0');
        num >>= 1;
    }
    return str;
}
ll BinaryToDecimal(string num)
{
    ll ans = 0;
    ll base = 1;
    for (int i = sz(num) - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            ans += base;
        base <<= 1;
    }
    return ans;
}
// ll dp[]
ll helper(ll n)
{
    if (n <= 3)
        return 1;

    ll take = 2 * helper(n / 4);

    return take;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;

        if (n <= 3)
        {
            cout << 1 << endl;
            continue;
        }
        ll ans = helper(n);
        cout << ans << endl;
    }

    return 0;
}