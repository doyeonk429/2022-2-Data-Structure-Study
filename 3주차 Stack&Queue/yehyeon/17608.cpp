#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack; //stack of sticks
    int n; //num of sticks
    int h; //height of stick
    cin >> n;
    
    for(int i = 0 ; i < n ; i++) //stacking sticks
    {
        cin >> h;
        stack.push(h);
    }

    int max = stack.top();
    int cnt = 1; //sticks we can see

    while(!stack.empty())
    {
        if(max < stack.top())
        {
            max = stack.top(); //change max height
            cnt++;
        }
        stack.pop();
    }
    cout << cnt;
    return 0;  
}
