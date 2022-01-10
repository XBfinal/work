//
////3.某女生理想男朋友的数据为，a=22 h=177 w=120 m=90 ,
////那么男盆友的数学模型为：
////s=k1*exp(-(a-22)^2/4^2) + k2*exp(-(h-177)^2/5^2) + k3*exp(-(w-120)^2/5^2) + k4*(m/90)
////其中k1+k2+k3+k4=1，且k1,k2,k3,k4>0,
////那么请编写程序来判断理想男朋友的程序，并给出10个男生的数据，并排序。
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#define N 4//创建10个男生的结构体数组
//int main(){
//	struct man{
//	int x,a,h;//男生编号（int x）年龄（int a），身高cm（int h ）
//	float w,m;//体重g（float w），数学成绩（float m）
//	double s;//理想值
//	}a[N];//创建10个男生的结构体数组
//	double k1,k2,k3,k4;
//	printf("请输入10个男生的数据\n");
//	for(int i=0;i<N;i++){
//		printf("请输入第%d个男生的编号，年龄，身高cm，体重g数学成绩\n",i+1);
//		fflush(stdin);//清楚缓冲区数据
//		scanf("%d %d %d %f %f",&a[i].x,&a[i].a,&a[i].h,&a[i].w,&a[i].m);
//	}
//	
//	k1=k2=k3=k4=0.25;
//	//计算理想值大小
//	for(int i=0;i<N;i++){
//		a[i].s=(k1*exp((double)(-1*(a[i].a-22)*(a[i].a-22)/(4.0*4))) )+ k2*exp((double)(-(a[i].h-177)*(a[i].h-177)/(5.0*5))) + k3*exp((double)((a[i].w-120)*(a[i].w-120)/(5*5.0))) + k4*exp((double)(a[i].m/90.0));
//	}
//	//根据理想值排序(这里我们用冒泡排序)
//	man ta;//创建临时的结构体 用来交换数据
//	for(int i=0;i<N;i++){
//		for(int j=0;j<N-1-i;j++){
//			if(a[i].s<a[i+1].s){
//				ta=a[i+1];
//				a[i+1]=a[i];
//				a[i]=ta;
//			}
//		}		
//	}
//	//输出数据及排名 
//	printf("编号\t年龄\t身高cm\t体重\t\t数学成绩\t理想值\t\t排名\n");
//	for(int i=0;i<N;i++){
//		printf("%d\t%d\t%d\t%f\t%f\t%f\t%d\n",a[i].x, a[i].a, a[i].h, a[i].w, a[i].m, a[i].s,i+1);
//	}
//	system("pause");
//	return 0;
//}