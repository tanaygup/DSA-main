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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(n);
        a[0] = 1;

        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = 0;
        int i = 0, j = 0;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        while (i < n)
        {
            if (a[j] < b[i])
            {
                i++;
                j++;
            }
            while (i < n && a[j] >= b[i])
            {
                ans++;
                i++;
            }
            j++;
            i++;
        }

        cout << ans << endl;
    }
}