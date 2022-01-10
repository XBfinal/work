////为了生成区间 [m,n] 之间的整数，可以用公式 rand()%(n-m+1)+m。
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
//	printf("\n排序后:\n");	
//	/*****************冒泡排序*********************/
//	int s = 0;//	当第一次完全有序时直接跳过s可以是小于0的数字
//	for(int e=N-1;e>0;e--){		
//		for(int b=0;b<e;b++){
//			if(arry[b]<arry[b+1]){
//				int tep=arry[b];
//				arry[b]=arry[b+1];
//				arry[b+1]=tep;
//				s=b+1;//记录最后一次交换的位置（取循环下标最大值）
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