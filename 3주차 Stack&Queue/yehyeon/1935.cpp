#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n; //num of operand
    string exp; //postfix expresssion
    cin >> n >> exp;

    int* arr = new int[n]; //num to substitute
    stack<double> stack; //stack of operand

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= 'A' && exp[i] <= 'Z') //operand
        {
            stack.push(arr[exp[i] - 'A']); //stack num corresponds to operand
        }
        else //operator
        {
            if (!stack.empty())
            {
                double res = stack.top();
                stack.pop();

                if (exp[i] == '+')
                {
                    res = stack.top() + res;
                }
                else if (exp[i] == '-')
                {
                    res = stack.top() - res;
                }
                else if (exp[i] == '*')
                {
                    res = stack.top() * res;
                }
                else if (exp[i] == '/')
                {
                    res = stack.top() / res;
                }

                stack.pop();
                stack.push(res);
            }
        }

    }
		//소숫점 둘째자리까지 자르기
    cout << fixed;
    cout.precision(2);
    cout << stack.top() << endl;

    return 0;
}
