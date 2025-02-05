#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool dfs(int node, int par, unordered_map<int, vector<int>> &adj, vector<int> &res)
{
    bool hasChild = false;
    for (auto it : adj[node])
    {
        if (it != par)
        {
            hasChild = true;
            bool childResult = dfs(it, node, adj, res);
            if (childResult)
            {
                res[node] = 0;
            }
        }
    }
    if (!hasChild)
    {
        res[node] = 1; // Mark leaf node as 1
        return true;
    }
    return res[node] == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc = 1;
    while (tc--)
    {
        int n, t;
        cin >> n >> t;
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int node;
        cin >> node;
        vector<int> res(n + 1, 1);

        bool flag = dfs(node, 0, adj, res);

        // cout << "Flag: " << flag << "\n";
        // cout << "Result Array: ";
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << res[i] << " ";
        // }
        if (!flag)
        {
            cout << "Ron" << endl;
        }
        else
            cout << "Hermione" << endl;
        // cout << "\n";
    }
    return 0;
}
