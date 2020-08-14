//hexaspace computer algorithm 04
//heapsort - decreasing order
//input : [n] keys, [k] steps, [ , , ..] nums
//output : k steps sorted numbers \n rest numbers

#include <stdio.h>
#include <iostream>

using namespace std;


void sort(int* list, int p, int size) {
	int l = 2 * p;	//child1
	int r = 2 * p + 1;	//child2
	int temp;
	//자식중 큰 값을 선택
	int max = l;	// l을 우선 선택
	if (r <= size) {	//배열 내에 r이 존재
		if (list[r] > list[l]) {	//r이 크다면
			max = r;	// 큰값=child2
		}
	}
	//부모와 자식M 비교
	if (list[p] > list[max]) {
		max = p;
		return;	//부모가 크다면 sort를 종료
	}
	// p <-> max	부모가 작다면 자식과 교체
	temp = list[p];
	list[p] = list[max];
	list[max] = temp;
	//새로운 자식 아래로 다시 정렬
	if (max <= (size / 2)) {	//leap(마지막줄)이 아니라면
		sort(list, max, size);
	}
	return;
}
// 힙 생성
void buildheap(int* list, int p, int size) {
	// p부터 앞으로 sort
	while (p >= 1) {
		sort(list, p, size);
		p--;
	}
	return;
}
int main() {
	int size, loop, i, j, temp;
	cout << "heap sort - decreasing order\n";

	//입력
	cout << "number of [keys & step]? : ";
	cin >> size;
	cin >> loop;
	int *list = new int[size + 1];	//동적할당
	cout << "enter keys : \n";
	for (i = 1; i <= size; ++i) {
		cin >> list[i];
	}

	//정렬
	buildheap(list, size / 2, size);	//heap생성,초기정렬

	//  loop번 추출
	for (j = 1; j <= loop; ++j) {
		temp = list[1];	//max값 (첫값) 추출
		list[1] = list[size - j + 1];	//마지막값을 [1]에 넣기
		list[size - j + 1] = temp;	//마지막 자리에 max값 넣기
		sort(list, 1, size - j);	//size를 1감소후 다시 sort
	}
	//출력
	cout << "result : \n\tsorted - ";
	//추출되었던 뒤에 쌓인 값들 출력
	for (i = size; i > size - loop; --i) {	//[size],[size-1]...[size-loop+1]
		cout << list[i] << " ";
	}
	cout << "\n\trest heap - ";
	//나머지 heap값들 출력
	for (i = 1; i <= size - loop; ++i) {	//[1],[2]...[size-loop]
		cout << list[i] << " ";
	}
	cout << "\n";
	delete[] list;	//동적할당 해제
	return 0;
}
