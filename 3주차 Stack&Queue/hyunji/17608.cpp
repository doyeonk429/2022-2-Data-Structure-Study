#include <iostream>
using namespace std;

int height[1000001];

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> height[i]; // 배열에 순서대로 높이를 입력받기
	}

	int top = 0;
	int cnt = 0;

	for (int i = num - 1; i >= 0; i--) { // 입력받은 순서의 반대로 stack 이용하기
		if (height[i] > top) {
			top = height[i]; // 높이가 top보다 크면, top이 해당 높이로 바뀐다.
			cnt++;
		}
	}

	cout << cnt << endl;

}
