#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int helper(vector<int> &a, int n, int start)
{

    int maxi = 0;

    int count = 0;

    for (int i = start; i < n; i += 2)
    {

        maxi = max(maxi, a[i]);
        count++;
    }

    return maxi + count;
}

int main()
{

    int t;

    cin >> t;

    while (t--)
    {

        int n;

        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {

            cin >> a[i];
        }

        int s0 = helper(a, n, 0);

        int s1 = helper(a, n, 1);

        cout << max(s0, s1) << endl;
    }

    return 0;
}