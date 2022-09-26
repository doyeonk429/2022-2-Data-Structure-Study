#include <iostream>
#include <stack>
using namespace std;

stack <int> lineStack[7];
 
int main() {
	int melodyNum, flatNum;
	cin >> melodyNum >> flatNum;

	int line, plat;
	int cnt = 0;

	for (int i = 0; i < melodyNum; i++) {
		cin >> line >> plat;


		while (1) {
			if (lineStack[line - 1].empty()) {
				lineStack[line - 1].push(plat);
				cnt++;
				break;
			}
			else if (lineStack[line - 1].top() < plat) {
				lineStack[line - 1].push(plat);
				cnt++;
				break;
			}
			else if (lineStack[line - 1].top() > plat) {
				lineStack[line - 1].pop();
				cnt++;
			}
			else {
				break;
			}
		}
	}
	cout << cnt << endl;
}
