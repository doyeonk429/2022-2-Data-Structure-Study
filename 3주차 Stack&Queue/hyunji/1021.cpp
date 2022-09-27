#include <iostream>
#include <deque>
using namespace std;

deque<int> myQueue; //원형 큐
int selecNum[51];

int main() {

	int N, M; // N은 큐의 크기, M은 뽑아내려는 수의 개수
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		myQueue.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		cin >> selecNum[i];
	}

	int cnt = 0;
	int idx = 0;
	int queueSize = 0;

	for (int i = 0; i < M; i++) { // 뽑아내려는 수의 개수만큼 반복한다
		queueSize = myQueue.size();

		for (int j = 0; j < queueSize; j++) {
			if (selecNum[i] == myQueue.at(j)) {
				idx = j;
			}
		}

		int num = 0;

		if (queueSize - idx > idx) { // 2번(왼쪽)으로 가는 것이 더 유리한 경우
			while(selecNum[i] != myQueue.front()){
				num = myQueue.front();
				myQueue.push_back(num);
				myQueue.pop_front(); // 첫번째 원소를 가장 뒤쪽으로 보낸다.
				cnt++;
			}
		}
		else { // 3번(오른쪽)으로 가는 것이 더 유리한 경우
			while(selecNum[i] != myQueue.front()) {
				num = myQueue.back();
				myQueue.push_front(num);
				myQueue.pop_back(); // 가장 마지막 원소를 가장 앞쪽으로 보낸다.
				cnt++;
			}
		}
		myQueue.pop_front(); // 뽑아내려고 하는 자연수와 큐의 첫번째 원소가 같은 경우에는, 해당 원소를 제거한다. (cnt에는 영향 X)
	}
	cout << cnt << endl;
}
