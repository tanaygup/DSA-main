#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> helper(long long n, vector<long long> &x)
{
    unordered_map<long long, long long> freq;

    for (long long c = 1; c <= n; ++c)
    {

        long long k_p = (c - 1) * (n - c + 1) + (n - c);
        freq[k_p]++;

        if (c < n)
        {
            long long delta = x[c] - x[c - 1] - 1;
            if (delta > 0)
            {
                long long k2 = c * (n - c);
                freq[k2] += delta;
            }
        }
    }

    return freq;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;

        vector<long long> x(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> x[i];
        }

        vector<long long> queries(q);
        for (long long i = 0; i < q; ++i)
        {
            cin >> queries[i];
        }

        unordered_map<long long, long long> freq = helper(n, x);

        for (long long ki : queries)
        {
            cout << freq[ki] << " ";
        }
        cout << endl;
    }

    return 0;
}
