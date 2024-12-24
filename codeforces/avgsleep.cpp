#include <iostream>
#include <vector>
#include <iomanip> // for setting precision
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sliding window sum initialization
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += a[i]; // Initial window of size k
    }

    ll totalSum = sum;

    // Sliding the window across the array
    for (int i = k; i < n; i++)
    {
        sum += a[i] - a[i - k]; // Slide window: add next element, remove first of the current window
        totalSum += sum;
    }

    // Calculate the average
    double average = (double)totalSum / (n - k + 1);

    // Output the result with precision
    cout << fixed << setprecision(10) << average << endl;

    return 0;
}
