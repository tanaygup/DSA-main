#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m++;
        }
        cnt++;
    }
    
    
    cnt += n - m;
    
    cout << cnt;

    return 0;
}
