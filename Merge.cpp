//hexaspace computer algorithm 02
//merge sort - decreasing order
//input : first [n] keys, next [ , , ..] nums
//output : sorted numbers

#include <iostream>
#include <stdio.h>

using namespace std;

int* merge(int* list, int p, int q, int r) {
	int left = p, right = q + 1;	//나뉜 두 묶음의 첫 index
	int size = r - p + 1;		//크기
	int *nlist = new int[size];	//동적할당
	int i, j;
	for (i = 0; left <= q && right <= r; ++i) {//두묶음 모두 끝에 도달안함 
		if (list[left] < list[right]) {//오른쪽 set의 요소가 더 클 때
			nlist[i] = list[right];//nlist에 오른쪽 요소 추가
			right++;
		}
		else {	//왼쪽 요소가 더 클때
			nlist[i] = list[left];
			left++;
		}
	}
	if (right <= r) {	//오른쪽 set이 남았다면
		for (; right <= r; ++i) {	//나머지 넣기
			nlist[i] = list[right];
			right++;
		}
	}
	else {	//왼쪽 set이 남았으면 나머지 넣기
		for (; left <= q; ++i) {
			nlist[i] = list[left];
			left++;
		}
	}
	//원본 list에 붙여넣기
	for (i = 0; i < size; ++i) {
		list[p] = nlist[i];
		p++;
	}
	delete[] nlist;	//동적할당 해제
	return list;
}
//divide before merge
int* divide(int* list, int p, int r) {
	if (p < r) {	// 2개 이상일 때
		int q = (p + r) / 2;	//중앙값
		list = divide(list, p, q);	//앞
		list = divide(list, q + 1, r);	//뒤
		list = merge(list, p, q, r);	//합치기

	}
	return list;
}
int main() {
	int num, k;
	//입력
	cout << "number of input keys? : ";
	cin >> num;	//입력받을 키의 개수

	int *list;
	list = new int[num];	//동적할당
	cout << "enter keys : \n";
	for (k = 0; k < num; ++k) {
		cin >> list[k];
	}
	//정렬
	list = divide(list, 0, num - 1);
	//출력
	cout << "result : \n";
	for (k = 0; k < num; ++k) {
		cout << list[k] << "\n";
		//printf("%d\n", list[k]);
	}
	delete[] list;	//동적할당 해제

	return 0;
}
