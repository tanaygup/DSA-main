#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n);
        unordered_set<ll> st;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        sort(v.begin(), v.end());

        if (n % 2 == 0)
        {
            ll ans = v[1] - v[0];

            for (ll i = 2; i < n; i += 2)
            {
                ans = max(ans, v[i + 1] - v[i]);
            }

            cout << ans << endl;
            continue;
        }
        else
        {
            ll ans = LLONG_MAX;

            for (ll i = 0; i < n; i++)
            {
                vector<ll> temp;
                for (ll j = 0; j < n; j++)
                {
                    if (i != j)
                        temp.push_back(v[j]);
                }

                ll res = temp[1] - temp[0];

                for (ll i = 2; i < temp.size(); i += 2)
                {
                    res = max(res, temp[i + 1] - temp[i]);
                }
                ans = min(ans, res);
            }
            cout << ans << endl;
        }
    }
}