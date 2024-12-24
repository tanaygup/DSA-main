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
// int i = 0;
void helper(int i,bool flag,vector<int>& a){

    if(i==a.size()){
        return;
    }

    if(flag){
        br = helper(i,false,a);
        nbr = helper(i+1,true,a);
    }
    
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
        cin>>n;

        vector<int> a(n);

        for(auto &it: a){
            cin>>it;
        }

        

    }
}