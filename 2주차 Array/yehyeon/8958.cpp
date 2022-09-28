#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    char arr[81]; //OX가 들어갈 char type의 array
    int n; //test case
    cin >> n;

    int count = 0; //누적 점수
    int sum = 0; //최종 점수

    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr; //array에 OX값 입력

        for(int j = 0 ; j < strlen(arr) ; j++)
        {
            if(arr[j] == 'O')
            {
                count++; //누적 점수 + 1
                sum += count; //최종 점수에 더하기
            }
            else if(arr[j] == 'X')
            {
                count = 0; //누적 점수 초기화
            }
        }

        cout << sum << endl;
        count = 0; //한 번 실행 후 count 값 초기화
        sum = 0; //한 번 실행 후 sum 값 초기화
    }

    return 0;

}
