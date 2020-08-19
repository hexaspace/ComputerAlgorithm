//hexaspace computer algorithm 07
//assembly line
//a라인(n)과 t소모값(n-1)이 있을때 최소 합을 위한 경로 선택을 a1 a2중 뭘 택하는지 출력하는것
//시작값이 e,x
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main() {
	int i, j, n, e1, e2, x1, x2;
	int a[3][100], t[3][100];
	int s[3][100], l[3][100];
	cout << "#assembly line\n\n";
	//입력
	cout << ">>N\n";
	cin >> n;	//1줄
	cout << ">>e1 & e2\n";
	cin >> e1 >> e2;	//2줄
	cout << ">>x1 & x2\n";
	cin >> x1 >> x2;	//3줄
	cout << ">>a1 & a2 ... an *2\n";
	for (i = 1; i <= 2; ++i) {	//4,5줄
		a[i][0] = 0;	//첫값=0
		for (j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	cout << ">>t1 & t2 ... t(n-1) *2\n";
	for (i = 1; i <= 2; ++i) {	//6,7줄
		t[i][0] = 0;
		for (j = 1; j <= n - 1; ++j) {
			cin >> t[i][j];
		}
	}
	//어샘블
	s[1][1] = e1 + a[1][1];
	s[2][1] = e2 + a[2][1];
	for (i = 2; i < n; ++i) {
		if (s[1][i - 1] + a[1][i] <= s[2][i - 1] + t[2][i - 1] + a[1][i]) {
			s[1][i] = s[1][i - 1] + a[1][i];
			l[1][i] = 1;
		}
		else {
			s[1][i] = s[2][i - 1] + t[2][i - 1] + a[1][i];
			l[1][i] = 2;
		}
		if (s[2][i - 1] + a[2][i] < s[1][i - 1] + t[1][i - 1] + a[2][i]) {
			s[2][i] = s[2][i - 1] + a[2][i];
			l[2][i] = 2;
		}
		else {
			s[2][i] = s[1][i - 1] + t[1][i - 1] + a[2][i];
			l[2][i] = 1;
		}
	}
	if (s[1][n - 1] + a[1][n] <= s[2][n - 1] + t[2][n - 1] + a[1][n]) {
		s[1][n] = s[1][n - 1] + a[1][n] + x1;
		l[1][n] = 1;
	}
	else {
		s[1][n] = s[2][n - 1] + t[2][n - 1] + a[1][n] + x1;
		l[1][n] = 2;
	}
	if (s[2][n - 1] + a[2][n] < s[1][n - 1] + t[1][n - 1] + a[2][n]) {
		s[2][n] = s[2][n - 1] + a[2][n] + x2;
		l[2][n] = 2;
	}
	else {
		s[2][n] = s[1][n - 1] + t[1][n - 1] + a[2][n] + x2;
		l[2][n] = 1;
	}
	
	//최종값 찾기
	int route[100000];
	int before;
	int max;
	if (s[1][n] <= s[2][n]) {
		before = 1;
		max = s[1][n];
	}
	else {
		before = 2;
		max = s[2][n];
	}
	route[n] = before;
	for (i = n; i > 1; --i) {
		before = l[before][i];
		route[i - 1] = before;
	}
	//출력
	//printf("%d\n", max);
	cout << max << "\n";
	for (i = 1; i <= n; ++i) {
		cout << route[i] << " " << i << "\n";
//printf("%d %d\n", route[i], i);
	}
	return 0;
}
