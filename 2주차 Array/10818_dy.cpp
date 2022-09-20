#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
 
	int n;
	cin >> n;
 
	int array[n+1];
 
	for(int i = 0; i < n; i++) {
		cin >> array[i];
	}
 
	sort(array, array + n);
 
	cout << array[0] << " " << array[n - 1];
 
	return 0;
 
}
