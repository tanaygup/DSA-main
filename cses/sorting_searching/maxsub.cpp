#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll maxi = LLONG_MIN;
    ll sum = 0;
    int i, j = 0;

    // deque<ll> dq;
    vector<ll> pref(n + 1);
    pref[0] = 0;

    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + v[i];
    }

    vector<pair<ll,int>> temp;

    for(int i=a;i<=b;i++) temp.push_back({pref[i+1],i});

    

    cout << maxi << endl;
}
