#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
// int powr(int a, int b)
// {
//     int res = 1;
//     while (b)
//         ;
//     {
//         if (b & 1)

//         res *= a, res %= mod;
//         a *= a;
//         a %= mod;
//         b /= 2;
//     }
//     return res;
// }
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        // if (n == 1)
        //     cout << 0 << endl;

        ll l = 0;
        ll r = 1e15;

        ll minMax = 0, maxMin = 0;

        while (l <= r)
        {
            ll mid = (r + l) / 2ll;
            vector<ll> nv = v;

            for (int i = 0; i < n - 1; i++)
            {
                if (nv[i] > mid)
                {
                    ll leftover = nv[i] - mid;
                    nv[i] = mid;
                    nv[i + 1] += leftover;
                }
            }
            if (nv[n - 1] <= mid)
            {
                minMax = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        l = 0;
        r = 1e15;

        while (l <= r)
        {
            ll mid = (l + r) / 2ll;
            vector<ll> helper = v;

            for (ll i = n - 1; i > 0; i--)
            {
                if (helper[i] < mid)
                {
                    ll extra = mid - helper[i];
                    helper[i - 1] -= extra;
                    helper[i] = mid;
                }
            }

            if (helper[0] >= mid)
            {
                maxMin = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout << max(0ll, minMax - maxMin) << endl;
    }
}