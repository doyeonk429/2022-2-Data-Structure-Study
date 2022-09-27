#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n, p; //note num, fret num
    int cnt = 0; //num of finger movements

    stack<int> stack[6];

    cin >> n >> p;

    for (int i = 0; i < n; i++)
    {
        int line, fret;
        cin >> line >> fret;

        if (stack[line - 1].empty())
        {
            stack[line - 1].push(fret);
            cnt++;
        }
        else
        {
            if (stack[line - 1].top() < fret)
            {
                stack[line - 1].push(fret);
                cnt++;
            }
            else
            {
                while (!stack[line - 1].empty() && stack[line - 1].top() > fret)
                {
                    stack[line - 1].pop();
                    cnt++;
                }

                if (!stack[line - 1].empty() && stack[line - 1].top() == fret )
                {
                    continue;
                }

                stack[line - 1].push(fret);
                cnt++;
            }

        }
    }
    cout << cnt;
}
