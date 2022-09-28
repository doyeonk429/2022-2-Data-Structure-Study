#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        int stick;
        cin >> stick;

        if(s.empty()) s.push(stick);
        else
        {
            while(!s.empty())
            {
                if(s.top() <= stick) s.pop();
                else break;
            }
            s.push(stick);
        }
    }

    cout << s.size() << '\n';

    return 0;
}
