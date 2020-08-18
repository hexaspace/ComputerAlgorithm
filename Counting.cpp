//hexaspace computer algorithm 06
//counting
/* input
>N K M (n - number of input key / m - max value of input keys
	/ k - number of query ranges / 1<= n,m,k <= 100000)
>a b (a<=range<=b)
>...k번 반복
>x (key)
>...n번 반복
*/
//output : k개의 범위안에 포함되는 키의 갯수를 각각 한줄씩 출력


#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int keys, max, ranges, i, result, key;
	cout << "#counting number of keys in range\n\n";
	//입력
	cout << ">> number of [key & range] & max value? :\n";
	cin >> keys;
	cin >> ranges;
	cin >> max;
		//동적할당
	int *aarr = new int[ranges];	//범위A 값들 배열
	int *barr = new int[ranges];	//범위B 값들 배열
	int *narr = new int[max + 1];	//수직선 0~max
	for (i = 0; i <= max; ++i) {//all 0으로 초기화
		narr[i] = 0;
	}
	cout << ">> [start & end] range value? :\n";
	for (i = 0; i < ranges; ++i) { //범위 a ,b입력
		cin >> aarr[i];
		cin >> barr[i];
	}
	cout << ">> key? :\n";
	for (i = 0; i < keys; ++i) { //key 입력받고 수직선에 표기
		cin >> key;
		narr[key]++;
	}
	//카운팅
	for (i = 2; i <= max; ++i) { //누적 표시  nall
		narr[i] = narr[i - 1] + narr[i];	//현재=이전 값+현재값
	}
	//출력
	cout << ">> result :\n";
	for (i = 0; i < ranges; ++i) { //a-1 < num <= b
		result = narr[barr[i]] - narr[aarr[i] - 1];;
		cout << result << "\n";
	}
		//동적할당 해제
	delete[] aarr;
	delete[] barr;
	delete[] narr;

	return 0;
}
