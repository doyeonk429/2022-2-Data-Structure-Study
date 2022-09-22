#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long arr[301][301];
    int n, m, r;

    cin >> n >> m >> r;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    int k = min(n, m) / 2;
    for(int _r = 0; _r < r; _r++)
    {
        for(int i = 0; i < k; i++)
        { 
            int tmp = arr[i][i];      
     
            for(int j = i; j < m - i - 1; j++)   // left
                arr[i][j] = arr[i][j + 1];

            for(int j = i; j < n - i - 1; j++)  // down
                arr[j][m - i - 1] = arr[j + 1][m - i - 1];   

            for(int j = m - i - 1; j > i; j--)  // right
                arr[n - i - 1][j] = arr[n - i - 1][j - 1];

            for(int j = n - i - 1; j > i; j--)  // up
                arr[j][i] = arr[j - 1][i];

            arr[i+1][i] = tmp;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
