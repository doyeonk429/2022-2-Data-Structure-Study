#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<double>stacks; // 전체 연산식 stack
string str;
int numArr[27];

bool check_Op(int num) { // 문자열이 연산자인지 피연산자인지 구분한다.
	if (str[num] - 'A' >= 0) { // 문자열이 피연산자인 경우
		return false;
	}
	else { // 문자열이 연산자인 경우
		return true;
	}
}

int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;
	cin >> str;
	cin.ignore(); // 버퍼 비우기

	for (int i = 0; i < N; i++) {
		cin >> numArr[i];
	}

	for (int i = 0; i < str.length(); i++) {
		if (check_Op(i) == false) { // 피연산자인 경우
			int num = numArr[str[i] - 'A'];
			stacks.push(num); // 해당 피연산자가 가지는 자연수를 전체 연산식 stack에 넣어주기
		}
		else { // 연산자인 경우
			double num1 = stacks.top();
			stacks.pop(); // top 뽑아내기
			double num2 = stacks.top();
			stacks.pop(); // top 뽑아내기
			if (str[i] == '+') { // 각각의 연산 기호에 맞는 연산을 진행한 뒤, 전체 연산식 stack에 계산값을 push()하기
				stacks.push(num2 + num1);
			}
			else if (str[i] == '-') {
				stacks.push(num2 - num1);
			}
			else if (str[i] == '*') {
				stacks.push(num2 * num1);
			}
			else if (str[i] == '/') {
				stacks.push(num2 / num1);
			}
		}	
	}
	cout << fixed;
	cout.precision(2); // 소수점 둘째 자리까지 나타내기
	cout << stacks.top(); // 전체 연산 결과값인 top을 출력하기
}
