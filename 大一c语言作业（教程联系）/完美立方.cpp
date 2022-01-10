///*
//形如a3= b3 + c3 + d3的等式被称为完美立方等式。例如
//123= 63 + 83 + 103 。编写一个程序，对任给的正整数N
//(N≤100)，寻找所有的四元组(a, b, c, d)，使得a3 = b3 +
//c3 + d3，其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。
//*/
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//	int N = 0;
//	cin >> N;
//	for (int a = 2; a <= N; a++) 
//		for(int b = 2; b < a ; b++)
//			for(int c = b; c < a ; c++)
//				for (int d = c; d < a; d++) {
//					if(pow((double)a,3)== pow((double)b, 3)+ pow((double)c, 3)+ pow((double)d, 3))
//						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c,d);	
//				}
//	return 0;
//}
