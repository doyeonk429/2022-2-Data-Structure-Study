#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string notation;
    cin >> notation;

    vector<int> v_data;
    for(int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v_data.push_back(input);
    }

    stack<double> s;
    for(int i = 0; i < notation.length(); i++)
    {
        if(notation[i] >= 'A' && notation[i] <= 'Z')
        {
            s.push(v_data[notation[i] - 'A']);
        }
        else
        {
            double first = s.top();
            s.pop();
            double second = s.top();
            s.pop();

            switch(notation[i])
            {
                case '+':
                    s.push(second + first);
                    break;
                case '-':
                    s.push(second - first);
                    break;
                case '*':
                    s.push(second * first);
                    break;
                case '/':
                    s.push(second / first);
                    break;
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top() << '\n';

    return 0;
}
