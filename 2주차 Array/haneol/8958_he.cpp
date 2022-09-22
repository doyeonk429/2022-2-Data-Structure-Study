#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ox_score[1000001];

    cin.get();
    for(int i = 0; i < n; i++)
    {
        int score = 1;
        for(int j = 0; j < 81; j++)
        {
            char tmp = cin.get();
            if(tmp == '\n' || tmp == EOF) break;
            if(tmp == 'O') ox_score[i] += score++;
            else if(tmp == 'X') score = 1; 
        }
    }

    for(int i = 0; i < n; i++)
        cout << ox_score[i] << '\n';

    return 0;
}
