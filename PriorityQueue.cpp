//hexaspace computer algorithm 05
//priority queue - decreasing order
//input : [0~3 (n (b))] command numbers
//output : [extracted elements] \n [current heap]
/* 설명
 0 : 종료
 1 n : n을 집어넣기
 2 : 최대값 추출
 3 a b : a번째 숫자를 b로 바꾸기
두 가지의 값이 같다면 오른쪽이 부모로 올라감
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void sort(int* list, int p, int size)
{
	int max, temp;
	int l = 2 * p;
	int r = 2 * p + 1;

	if (r <= size && list[r]>list[p])
	{//부모보다 오른쪽이 클때 (오른쪽이 범위 내)
		max = r;	//오른쪽 우선
	}
	else
	{
		max = p;
	}

	if (l <= size && list[l]>list[max])
	{//부모보다 왼쪽이 클 때 (왼쪽이 범위 내)
		max = l;
	}
	if (max != p)//부모가 max가 아닐시
	{	//값 교환
		temp = list[p];
		list[p] = list[max];
		list[max] = temp;
		//아래로 정렬(바뀐 자식위치에서 다시 정렬)
		sort(list, max, size);
	}
}

void up(int* list, int index, int key)
{
	int temp;
	if (key < list[index]) { return; }
	list[index] = key;
	while (index > 1 && list[index / 2] < list[index])
	{//루트가 아니고 부모보다 값이 클 때 교환 반복
		temp = list[index];
		list[index] = list[index / 2];
		list[index / 2] = temp;
		//더 부모로 올라가기
		index = index / 2;
	}
}

int main()
{
	int input, key, index, i = 0, temp = 0;
	int end = 0, size = 0, rsize = 0;
	int list[1000000];	//queue 배열
	int root[1000000];	//추출된 배열
	cout << "priority queue\n[0]quit [1 n]insert [2]extract [3 a b]ath number = b\n";
	//입력
	while (end == 0)	//0 나올때까지 반복
	{
		cin >> input;
		switch (input)	//command
		{
		case(0) ://종료
			end = 1;	//종료 on
			break;

		case(1) ://삽입
			cin >> key;	//input number
			size++;
			list[size] = key;	//큐 마지막에 넣기
			up(list, size, key);	//큐 위로 정렬(조상과 비교)
			break;

		case(2) ://추출
			rsize++;
			root[rsize] = list[1];	//추출배열 마지막에 넣기
			//큐 마지막값 루트로 옮기기
			temp = list[size];
			list[size] = list[1];
			list[1] = temp;
			size--;
			//재정렬
			sort(list, 1, size);
			break;

		case(3) ://변경
			cin >> index;
			cin >> key;
			list[index] = key;//인덱스 위치의 값을 바꿈
			if (index != 1 && list[index] > list[index / 2])
			{//루트가 아니고 부모보다 클 경우
				up(list, index, key);//위로정렬
			}
			else
			{
				sort(list, index, size);//재정렬
			}
			break;

		default:
			break;
		}
	}
	//출력
	cout << "result : \n\textracted - ";
	for (i = 1; i <= rsize; i++)
	{
		cout << root[i] << ' ';
	}
	cout << "\n\trest heap - ";

	for (i = 1; i <= size; i++)
	{
		cout << list[i] << ' ';
	}
	cout << "\n";

	return 0;

}
