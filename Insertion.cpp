//hexaspace computer algorithm 01
//insertion sort - decreasing order
//input : first [n] keys, next [ , , ,...] nums
//output : sorting numbers

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

	int num, i, j, turn;
	//입력
	cout << "number of input keys? : ";
	cin >> num;		//입력받을 키의 갯수

	int *list = new int[num];	//동적할당 배열 생성
	cout << "enter keys : \n";
	for (i = 0; i < num; ++i) {
		cin >> list[i];
	}
	//insertion sort :값이 들어올 때마다 앞의 항목들과 바로 비교하여 정렬한다
	for (j = 1; j<num; ++j) {
		turn = list[j];	// 이번 턴
		//i = j - 1;	// 이전 항목까지 탐색비교

		for (i=j-1; i>=0 && list[i]<turn; i--){	// 비교군보다 클때까지 앞으로 이동
			list[i + 1] = list[i];	//비교군을 뒤로 이동
			//i = i - 1;
		}
		list[i + 1] = turn;	//비교전 i--로 준 만큼 +1해준다
	}
	//출력
	cout << "result : \n";
	for (i = 0; i < num; ++i) {
		printf("%d\n", list[i]);

	}
	delete[] list;	//동적할당 배열 해제
	return 0;
}
