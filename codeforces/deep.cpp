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
        int n;
        cin >> n;
        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin>>k;

            for (int j = 0; j < k; j++)
            {
                cin>>a[i][j];
            }
            cout<<endl;
        }

        

        
    }
}