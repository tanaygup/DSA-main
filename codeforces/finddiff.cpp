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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int q;
        cin >> q;
        vector<vector<int>> v(q, vector<int>(2));
        for (int i = 0; i < q; i++)
        {
            cin >> v[i][0] >> v[i][1];
            cout << endl;
        }
        vector<int> next(n);

        next[n-1] = n;
        for(int i=n-2;i>=0;i--){
            if(a[i]==a[i+1]) next[i] = next[i+1];
            else next[i] = i+1; 
        }

        for(int i=0;i<q;i++){
            int l = v[i][0]-1;
            int r = v[i][1]-1;
            
            if(next[l]<=r) cout<<l+1<<" " <<next[l]+1<<endl;
            else cout<<-1<<" " <<-1<<endl;

        }
    }
}