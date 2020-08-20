//hexaspace computer algorithm 09
//matrix chain
//input : number of int [n] &\n& [0&1&2...n] n+1 integers
//output : minimum scalar multiplications value [m] &\n& order [(a(aa))(aa)]
/*
행렬 곱의 방식을 이용하여 "scalar 곱하기 횟수"를 최소화하는 방법을 찾는것입니다.
중간값이 두번 곱해진다는 부분을 유의합니다.
n+1개의 int값을 받으면 (0x1),(1x2),(2x3)..(n-1xn)총 n개의 행렬을 표현합니다.
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void order(int a, int b, int** index) {
	int k;
	if (a == b) { cout << a << " "; }
	else {
		k = index[a][b];	//연결부위
		cout << "( ";
		order(a, k, index);
		order(k + 1, b, index);
		cout << ") ";
	}
}
int main() {
	int i, k, l, j, q, num;
	cout << "#matrix chain\n\n";
	//입력
	cout << ">>number of matrices?\n";
	cin >> num;
	int** m = new int*[num + 1];	//동적할당 스칼라곱 횟수
	int** s = new int*[num + 1];	//	   최소위치 표기
	int* p = new int[num + 1];	//	   행렬 요소 값(입력받음)
	for (i = 0; i <= num; ++i) {	//(n+1)x(n+1)이차원행렬
		m[i] = new int[num + 1];
		s[i] = new int[num + 1];
	}
	cout << ">>enter " << num+1 << " element\n";
	for (i = 0; i <= num; ++i) {	//0으로 초기화
		m[i][i] = 0;
		s[i][i] = 0;
		cin >> p[i];		//행렬값 입력받음
	}
	//최소 찾기 - 소요시간 n^3
	//m[i,j]=min{m[i,k]+m[k+1,j]+p[i-1]p[k]p[j] if i<=k<j

	for (l = 2; l <= num; ++l) {//2~n, i와 j의 차(가능한 k의 수)
		for (i = 1; i <= num - l + 1; ++i) {//1~n-1, 1~n-2.. 1~1
			j = i + l - 1;		    //2~n,   3~n ... n~n
			m[i][j] = 1000000;	//일단 max설정
			for (k = i; k <= j - 1; ++k) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
	//[i,j]는 그 이전단계중 k를 같이한 값과 ([i,k],[k+1,j])
	//연결하는 값 (p[i-1]p[k]p[j])를 더한것들중 최소값을 고르면 된다.
				if (q < m[i][j]) {	//최소라면
					m[i][j] = q;
					s[i][j] = k;	//연결부위 k직후 괄호로 나뉘는 부위
				}
			}
		}
	}
	//출력
	cout << ">>result : \n";
	cout << "minimum scalar multiplications : " << m[1][num] << "\n";
	order(1, num, s);
	cout << "\n";
	//동적할당 해제
	delete[] p;
	for (i=0; i<=num; ++i){
		delete[] m[i];
		delete[] s[i];
	}
	delete[] m;
	delete[] s;

	return 0;
}
