//hexaspace computer algorithm 03
//selection sort - increasing order
//input : [n] keys, [m] steps, [ , , ...]numbers
//output : m steps sorted numbers

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	cout << "Selection sort - increasing order\n";
	int num, loop, i, j, min, temp;
	//입력
	cout << "number of input [keys & step]? : ";
	cin >> num;
	cin >> loop;
	int *list = new int[num];	//동적 할당
	cout << "enter keys : \n";
	for (i = 0; i < num; ++i) {
		cin >> list[i];
	}
	//selection sort
	for (i = 0; i < loop; ++i) {
		min = i;	//최소값 찾기
		for (j = i + 1; j < num; ++j) {
			if (list[min] > list[j]) {
				min = j;
			}
		}
		temp = list[i];	// i위치에 최소값 교환
		list[i] = list[min];
		list[min] = temp;

	}
	//출력
	cout << "result :\n";
	for (i = 0; i < num; ++i) {
		//printf("%d\n", list[i]);
		cout << list[i] << "\n";
	}
	delete[] list;	//동적할당 해제

	return 0;
}
