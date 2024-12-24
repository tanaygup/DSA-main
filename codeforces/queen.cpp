#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> respect(n + 1);
    vector<vector<int>> children(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int p, c;
        cin >> p >> c;
        parent[i] = p;
        respect[i] = c;
        if (p != -1)
        {
            children[p].push_back(i);
        }
    }

    vector<int> to_delete;
    for (int i = 1; i <= n; ++i)
    {
        if (parent[i] != -1 && respect[i] == 1)
        {
            bool can_delete = true;
            for (int child : children[i])
            {
                if (respect[child] == 0)
                {
                    can_delete = false;
                    break;
                }
            }
            if (can_delete)
            {
                to_delete.push_back(i);
            }
        }
    }

    if (to_delete.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        sort(to_delete.begin(), to_delete.end());
        for (int v : to_delete)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
