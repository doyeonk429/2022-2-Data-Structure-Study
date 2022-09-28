#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    deque<int> searching;
    deque<int> r_queue;

    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        searching.push_back(k);
    }

    for(int i = 1; i <= n; i++)
    {
        r_queue.push_back(i);
    }

    int count = 0;
    for(int i = 0; i < m; i++)
    {
        int tmp_count = 0;
        while(true)
        {
            if(r_queue.front() == searching.front()) break;
            
            r_queue.push_back(r_queue.front());
            r_queue.pop_front();
            tmp_count++;
        }

        if(tmp_count > r_queue.size() / 2)
        {
            while(tmp_count--)
            {   
                r_queue.push_front(r_queue.back());
                r_queue.pop_back();
            }

            while(true)
            {
                if(r_queue.front() == searching.front())
                {
                    r_queue.pop_front();
                    searching.pop_front();
                    break;
                }
                
                r_queue.push_front(r_queue.back());
                r_queue.pop_back();
                count++;
            }
        }
        else
        {
            r_queue.pop_front();
            searching.pop_front();
            count += tmp_count;
        }
    }

    cout << count << '\n';

    return 0;
}
