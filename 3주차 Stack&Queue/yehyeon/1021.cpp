#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queue;
    int n, m;
    int cnt = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        queue.push(i);
    }

    while (m--)
    {
        int num; //num to pop
        cin >> num;
        int mov = 0;
        
        if (queue.front() == num)
        { 
            queue.pop();
        }
            
        else
        {
            
            while (queue.front() != num)
            {
                int tmp = queue.front();
                queue.pop();
                queue.push(tmp);
                mov++;
            }

            if (mov > queue.size() - mov)
            {
                cnt += queue.size() - mov;
            }
            else
            {
                cnt += mov;
            }
            queue.pop();
        }
        
    }
    cout << cnt << endl;
}
