///*
//����a3= b3 + c3 + d3�ĵ�ʽ����Ϊ����������ʽ������
//123= 63 + 83 + 103 ����дһ�����򣬶��θ���������N
//(N��100)��Ѱ�����е���Ԫ��(a, b, c, d)��ʹ��a3 = b3 +
//c3 + d3������a,b,c,d ���� 1, С�ڵ���N����b<=c<=d��
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
