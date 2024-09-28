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
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;

        vector<ll> v(n);

        for(int i=0;i<n;i++) cin>>v[i];

        
    }
}