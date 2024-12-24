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
#define MAX 500
int multiply(int x, vector<int> &res, int res_size);

vector<int> factorial(int n)
{
    vector<int> res(MAX);

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    return res;
}

int multiply(int x, vector<int> &res, int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n, d;

        cin >> n >> d;
        vector<int> v;
        v.push_back(1);

        if (n >= 7)
        {
            v.push_back(3);
            // v.push_back(5);
            v.push_back(7);
            v.push_back(9);
            // continue;
        }

        else
        {
            ll sum = 0;
            ll res = 1;
            for (ll i = 2; i <= n; i++)
                res = (res * i) % MOD;

            sum = (res * d) % MOD;

            if (d % 3 == 0 || sum % 3 == 0)
                v.push_back(3);
            if (d == 7 || sum % 7 == 0 || n > 2)
                v.push_back(7);
            if (((d % 3) == 0 && n >= 3) || sum % 9 == 0 || n > 5)
                v.push_back(9);
            // if (sum % 5 == 0)
            //     v.push_back(5);
        }

        if (d == 5)
            v.push_back(5);

        sort(v.begin(), v.end());
        for (auto &it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        v.clear();
    }

    return 0;
}