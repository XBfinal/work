////Ϊ���������� [m,n] ֮��������������ù�ʽ rand()%(n-m+1)+m��
//#include<iostream>
//using namespace std;
//#define N 20
//int main(){
//	int arry[N]={0};
//	for(int i=0;i<N;i++)
//		arry[i]=rand()%(100-1+1)+1;
//	for (int i = 1; i <= N; i++) {
//		printf("%d \t", arry[i - 1]);
//		if (i % 5 == 0)
//			printf("\n");
//	}
//		
//	printf("\n�����:\n");	
//	/*****************ð������*********************/
//	int s = 0;//	����һ����ȫ����ʱֱ������s������С��0������
//	for(int e=N-1;e>0;e--){		
//		for(int b=0;b<e;b++){
//			if(arry[b]<arry[b+1]){
//				int tep=arry[b];
//				arry[b]=arry[b+1];
//				arry[b+1]=tep;
//				s=b+1;//��¼���һ�ν�����λ�ã�ȡѭ���±����ֵ��
//			}
//		}
//		e=s;
//	}
//	for (int i = 1; i <= N; i++) {
//		printf("%d \t", arry[i-1]);
//		if (i % 5 == 0)
//			printf("\n");
//	}
//	getchar();
//	return 0;
//}