#include<iostream>
// First element is always greatest 
#include<queue>

using namespace std;
int main() {
    priority_queue<int>maxi;
    // this is max heap. this means jab bhi element bhaar nikaalenge it will always be greatest


    // min heap 
    priority_queue<int, vector<int>, greater<int>>mini; 

    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(0);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }cout<<endl;

    mini.push(5);
    mini.push(4);
    mini.push(3);
    mini.push(1);

    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }cout<<endl;

    cout<<mini.empty();
    
return 0;
}
