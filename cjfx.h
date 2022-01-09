#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node1
{
	int date;	//学号
	int me_class;	  //班级
	double yuwen;//语文成绩
	double shuxue;//数学成绩
	double yingyu;//英语成绩
	double num;			//总分
	double avg;			//平均分
	char name[20];		//姓名	 
	char kemu[20];		//所选科目
}stu1[50],stu2[50],t;
int si1=0,si2=0;
void lbzsz(struct node*head);
void OutPx(struct node*head,struct node1 stu[50],int si,int n);//输出成绩排序//输出成绩统计
void Outtj(struct node1 stu[50],int si,int n);//输出成绩统计
int cjmenu(){
	 int i=1;
		printf("\t\t 1.1班成绩排序\n");
		printf("\t\t 2.2班成绩排序\n");
		printf("\t\t 3.1班成绩统计\n");
		printf("\t\t 4.2班成绩统计\n");
		printf("\t\t 0.退出\n");
		printf("\t\t-----------------------------\n");
		printf("\t请选择序号\n");
		scanf_s("%d",&i);
		while(1)
		{
			if(i<0||i>4)
			{
				printf("***没有此选项。请重新选择***\n");
				system("pause");
			}
			break;
		}

	return i;
}
void main1(struct node*head)
{
	int i,j=1;
	printf("\t\t---成绩分析系统---\n");
	while(j){
		i= cjmenu();
		 lbzsz(head);
		switch(i){
			case 0:
				j=0; 
				printf("退出成功");
				break;
			case 1:
				 OutPx(head,stu1,si1,1);system("pause");break;system("pause");
			case 2:
				OutPx(head,stu2,si2,2);system("pause");break;system("pause");
			case 3:
				Outtj(stu1,si1,1);system("pause");break;system("pause");
			case 4:
				Outtj(stu2,si2,2);system("pause");break;system("pause");
			default:break;
	
		}
		printf("\n");
		printf("\t\t——————————————\n");
	}//while结束
 }
//链表存入两个数组
void lbzsz(struct node*head)
{
	struct node*p;
	p=head;
	if(head->next==NULL)
		{printf("没有数据请先存入数据");}
	if(head->next)
	{
		for(si1=0,si2=0;p->next !=NULL;)
		{
			p=p->next ;
			if(p->me_class %2==0)
			{
				stu2[si2].avg =p->avg ;//平均分
				stu2[si2].date=p->date;//学号
				strcpy(stu2[si2].kemu,p->kemu);//字符串要用strcpy
				stu2[si2].me_class=p->me_class;
				strcpy(stu2[si2].name,p->name);
				stu2[si2].num=p->num;
				stu2[si2].shuxue=p->shuxue;
				stu2[si2].yingyu=p->yingyu;
				stu2[si2].yuwen=p->yuwen;
				si2++;
			}
			else
			{
				stu1[si1].avg =p->avg ;//平均分
				stu1[si1].date=p->date;//学号
				strcpy(stu1[si1].kemu,p->kemu);
				stu1[si1].me_class=p->me_class;
				strcpy(stu1[si1].name,p->name);
				stu1[si1].num=p->num;
				stu1[si1].shuxue=p->shuxue;
				stu1[si1].yingyu=p->yingyu;
				stu1[si1].yuwen=p->yuwen;
				si1++;
			}
		}
	
	}
	/******************************************************/
	
}//链表存入两个数组
//输出成绩排序
void OutPx(struct node*head,struct node1 stu[],int si,int n){//stu[50]数组，int si长度，int n班级。
	int j,k=0;
	int i,h;//控制学科。
	 struct xueke
	{
		char aa[15];
	 }km[4]={{"语文"},{"数学"},{"英语"},{"总成绩"}};
	lbzsz(head);
	printf("\t\t%d班的成绩排序\n",n);
	for(i=0,h=1;i<4;i++,h++){//for1
		for(j=0;j<si;j++){//for2
			for(k=0;k<si-1-j;k++){//for3
				if(h==1){
					if(stu[k].yuwen<stu[k+1].yuwen){
					t=stu[k+1];
					stu[k+1] =stu[k] ;
					stu[k]=t;
					}
				}
				if(h==2){
					if(stu[k].shuxue<stu[k+1].shuxue){
					t =stu[k+1];
					stu[k+1] =stu[k] ;
					stu[k] =t ;
					}
				}
				if(h==3){
					if(stu[k].yingyu<stu[k+1].yingyu){
					t=stu[k+1];
					stu[k+1] =stu[k] ;
					stu[k] =t ;
					}
				}
				if(h==4){
					if(stu[k].num  <stu[k+1].num  ){
					t =stu[k+1];
					stu[k+1] =stu[k] ;
					stu[k] =t ;
					}
				}
			}//for3结束
		}//for2结束
		printf("%s排名\n学号\t姓名\t班级\t%s成绩\t排名\n",km[i].aa,km[i].aa);
		if(h==1){
			for(j=0,k=1;j<si;j++,k++)
			printf("%d\t%s\t%d\t%lf\t%d\n",stu[j].date,stu[j].name,stu[j].me_class,stu[j].yuwen,k);
			}
		if(h==2){
				for(j=0,k=1;j<si;j++,k++)
					printf("%d\t%s\t%d\t%lf\t%d\n",stu[j].date,stu[j].name,stu[j].me_class,stu[j].shuxue ,k);
			}
		if(h==3){
				for(j=0,k=1;j<si;j++,k++)
				printf("%d\t%s\t%d\t%lf\t%d\n",stu[j].date,stu[j].name,stu[j].me_class,stu[j].yingyu ,k);
			}
		if(h==4){
				for(j=0,k=1;j<si;j++,k++)
				printf("%d\t%s\t%d\t%lf\t%d\n",stu[j].date,stu[j].name,stu[j].me_class,stu[j].num  ,k);
			}
	}
  }
//输出成绩统计
void Outtj(struct node1 stu[50],int si,int n)
{
	double  avg1=0,avg2=0,avg3=0;
	double  k1=0,k2=0,k3=0;//及格率
	double  j1=0,j2=0,j3=0;//优秀率
	double  max1;
	double  min1;
	int j;
	
		max1=stu[0].yuwen;
		min1=stu[0].yuwen;
	for(j=0;j<si;j++)
	{	
		avg1+=stu[j].yuwen;
		if(stu[j].yuwen>=60) k1++;
		if(stu[j].yuwen>=90) j1++;
		if(stu[j].yuwen>max1) max1=stu[j].yuwen;
		if(stu[j].yuwen<min1) min1=stu[j].yuwen;
	}
	avg1/=j;
	k1/=j;
	j1/=j;
	printf("\t\t*********%d班成绩*************\n",n);
	printf("语文平均成绩\t\t及格率\t\t优秀率\t\t最高分\t\t最低分\n");
	printf("%f\t\t%f\t%f\t%lf\t%lf\n",avg1,k1,j1,max1,min1);
		max1=stu[0].shuxue;
		min1=stu[0].shuxue;
	for(j=0;j<si;j++)
	{
		avg2+=stu[j].shuxue;
		if(stu[j].shuxue>=60)k2++;
		if(stu[j].shuxue>=90)j2++;
		if(stu[j].shuxue>max1) max1=stu[j].shuxue;
		if(stu[j].shuxue<min1) min1=stu[j].shuxue;
	}
	avg2/=j;
	k2/=j;
	j2/=j;
	printf("数学平均成绩\t\t及格率\t\t优秀率\t\t最高分\t\t最低分\n");
	printf("%lf\t\t%lf\t%lf\t%lf\t%lf\n",avg2,k2,j2,max1,min1);
		max1=stu[0].yingyu;
		min1=stu[0].yingyu;
	for(j=0;j<si;j++)
	{
		avg3+=stu[j].yingyu ;
		if(stu[j].yingyu>=60) k3++;
		if(stu[j].yingyu>=90)j3++;
		if(stu[j].yingyu>max1) max1=stu[j].yingyu;
		if(stu[j].yingyu<min1) min1=stu[j].yingyu;
	}
	avg3/=(j);
	k3/=(j);
	j3/=(j);
	printf("英语平均成绩\t\t及格率\t\t优秀率\t\t最高分\t\t最低分\n");
	printf("%lf\t\t%lf\t%lf\t%lf\t%lf\n",avg3,k3,j3,max1,min1);

}