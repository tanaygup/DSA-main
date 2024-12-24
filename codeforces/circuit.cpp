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

        vector<int> v(2 * n);
        int one = 0, zero = 0;
        for (int i = 0; i < v.size(); i++)
        {
            cin >> v[i];
            if (v[i] == 0)
                zero++;
            else
                one++;
        }
        int mini = 0, maxi = 0;
        // if(zero%2 ==0 && one%2==0) mini = 0;
        mini = (zero % 2 + one % 2) / 2;
        maxi = min(zero, one);

        cout << mini << " " << maxi << endl;
    }
}