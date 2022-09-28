#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n; //length
    cin >> n;

    int arr[n + 1]; //동적으로 배열 생성
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i]; //배열에 값 저장
    }

    sort(arr, arr + n); //sort를 사용해 오름차순 정렬

    cout << arr[0] << " " << arr[n - 1]; //최솟값과 최댓값 출력
    
    return 0;
}
