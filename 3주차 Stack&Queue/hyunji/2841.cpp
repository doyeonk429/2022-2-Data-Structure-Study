#include <iostream>
#include <stack>
using namespace std;

stack <int> lineStack[7]; // 기타줄은 6개로 고정됨.
 
int main() {
	int melodyNum, flatNum;
	cin >> melodyNum >> flatNum;

	int line, plat;
	int cnt = 0;

	for (int i = 0; i < melodyNum; i++) {
		cin >> line >> plat;


		while (1) {
			if (lineStack[line - 1].empty()) { // 스택이 비어있으면, push()하고 loop 빠져나오기
				lineStack[line - 1].push(plat);
				cnt++;
				break;
			}
			else if (lineStack[line - 1].top() < plat) { // top보다 프랫의 수가 높으면, push()하고 loop 빠져나오기
				lineStack[line - 1].push(plat);
				cnt++;
				break;
			}
			else if (lineStack[line - 1].top() > plat) { // top보다 프랫의 수가 작으면, pop()해주기
				lineStack[line - 1].pop();
				cnt++;
			}
			else { // top = '프랫의 수'이면, 그냥 loop 빠져나오기
				break;
			}
		}
	}
	cout << cnt << endl;
}
