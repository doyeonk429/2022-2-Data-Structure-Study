#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int minmax[1000001];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> minmax[i];

    int min = minmax[0], max = minmax[0];
    for(int i = 1; i < n; i++)
    {
        if(min > minmax[i]) min = minmax[i];
        if(max < minmax[i]) max = minmax[i];
    }

    cout << min << ' ' << max << '\n';

    return 0;
}
