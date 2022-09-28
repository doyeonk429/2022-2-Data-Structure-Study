#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;

    stack<int> s[6];
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        if(s[x-1].empty())
        {
            s[x-1].push(y);
            count++;
            continue;
        }

        while(true)
        {
            if(s[x-1].empty() || s[x-1].top() < y)
            {
                count++;
                s[x-1].push(y);
                break;
            }
            else if(s[x-1].top() > y)
            {
                count++;
                s[x-1].pop();
            }
            else
                break;
        }
    }

    cout << count << '\n';

    return 0;
}
