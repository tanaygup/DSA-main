#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

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
    unordered_set<ll> st;

    for (int k = 2; k <= 1000; k++)
    {
        ll val = 1 + k;
        ll temp = k * k;

        for (int j = 2; j <= 20; j++)
        {
            val += temp;
            if (val > 1e6)
                break;
            st.insert(val);

            temp *= k;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (st.find(n) != st.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}