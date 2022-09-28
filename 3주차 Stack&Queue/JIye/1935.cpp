#include <iostream>
#include <stack>
#include <map>
using namespace std;


int main() {

	int fn;
	cin >> fn;
	cin.ignore();//입력버퍼에 남은 \n을 삭제
	char c[100];//문자열 저장
	cin.getline(c, 100);
	map<char, float> f;
	for (int i = 0; i < fn; i++) { // 딕셔너리에 <영대문자, 실수> 저장
		float n;
		cin >> n;
		f.insert(pair<char, float>(char(i + 65), n));
	}

	stack <float> mod; // 실수 저장
	for (int i = 0; i<100; i++) {
		if ((int)c[i] >= 65 && (int)c[i] <= 90) {//영대문자를 스택에 저장
			mod.push(f[c[i]]);
		}

		else { //연산자를 만나면
				float op2 = mod.top();  mod.pop();
				float op1 = mod.top();  mod.pop();

				switch ((int)c[i]) {
				case 42:
					mod.push(op1 * op2);
					break;
				case 43:
					mod.push(op1 + op2);
					break;
				case 45:
					mod.push(op1 - op2);
					break;
				case 47:
					mod.push(op1 / op2);
					break;
				}
		}
	}

	cout << mod.top();
}
