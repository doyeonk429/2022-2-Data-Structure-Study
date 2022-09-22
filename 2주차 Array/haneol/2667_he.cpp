#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int map[26][26];
    bool visited[26][26] = {false, };
    int block[1000] = {0, };
    stack<pair<int, int> > s;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char tmp = cin.get();
            if(tmp == '\n') tmp = cin.get();

            int num = tmp - '0';
            map[i][j] = num;
        }
    }

    int k = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 1 && !visited[i][j])
            {
                k++;
                s.push(make_pair(i, j));
                while(!s.empty())
                {
                    int x = s.top().first;
                    int y = s.top().second;
                    s.pop();

                    if(!visited[x][y])
                        visited[x][y] = true;
                    else
                        continue;

                    block[k]++;
                    if(map[x+1][y] == 1 && x+1 < n)
                    {
                        s.push(make_pair(x+1, y));
                    }
                    if(map[x-1][y] == 1 && x-1 >= 0)
                    {
                        s.push(make_pair(x-1, y));
                    }
                    if(map[x][y+1] == 1 && y+1 < n)
                    {
                        s.push(make_pair(x, y+1));
                    }
                    if(map[x][y-1] == 1 && y-1 >= 0)
                    {
                        s.push(make_pair(x, y-1));
                    }
                }
            }
        }
    }

    sort(block, block + k + 1);
    cout << k+1 << '\n';
    for(int i = 0; i <= k; i++)
        cout << block[i] << '\n';

    return 0;
}
