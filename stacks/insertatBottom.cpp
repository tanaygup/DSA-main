/*#include <bits/stdc++.h> 

void solve(stack<int>& s, int x){

    // base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int cnt = s.top();
    s.pop();

    // recursive call
    solve(s,x);

    s.push(cnt);




}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}
*/
