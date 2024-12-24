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

ll numberOfZeroes(ll a)
{
    string s = to_string(a);
    int i = s.size() - 1;
    ll ans = 0;

    while (i >= 0)
    {
        if (s[i] == '0')
        {
            ans++;
        }
        else
            break;
        i--;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        ll numberOfDigits = 0;

        for (auto a : v)
        {
            string temp = to_string(a);
            numberOfDigits += temp.size();
        }

        vector<ll> zeroes(n);
        for (int i = 0; i < n; i++)
        {
            zeroes[i] = numberOfZeroes(v[i]);
        }

        sort(zeroes.rbegin(), zeroes.rend());

        ll cnt = 0;

        for (int i = 0; i < n; i += 2)
        {
            numberOfDigits -= zeroes[i];
        }

        if (numberOfDigits >= (m + 1))
            cout << "Sasha" << endl;
        else
            cout << "Anna" << endl;
    }
}