

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Use a map to store the difference of prefix sums
        map<ll, int> prefix_diff;
        ll odd_sum = 0, even_sum = 0;
        bool found = false;
        prefix_diff[0] = 1; // Base case: difference of 0 exists initially

        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                odd_sum += a[i];
            }
            else
            {
                even_sum += a[i];
            }

            ll diff = odd_sum - even_sum;
            if (prefix_diff.count(diff) > 0)
            {
                found = true;
                break;
            }
            prefix_diff[diff] = 1;
        }

        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
