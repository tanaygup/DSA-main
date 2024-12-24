#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

bool helper(string &s, int a)
{
    for (char &c : s)
    {
        if (c - '0' == a)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(s[i] - '0');
    }

    while (1)
    {
        // int top = pq.top();
        while (!helper(s, pq.top()))
        {
            pq.pop();
        }
        string nt = to_string(stoi(s) - pq.top());
        for (char &c : nt)
        {
            pq.push(c - '0');
        }
        cnt++;
        if (stoi(nt) == 0)
            break;
        s = nt;
    }
    cout << cnt;
}