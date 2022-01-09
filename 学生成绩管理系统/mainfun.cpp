#include<stdio.h>
#include<stdlib.h>
#include"stdd.h"
#include<string.h>
#include"cjfx.h"

 int main()
 {
	int i,j=1;
	struct node*head;
	last=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head->next =NULL;
	printf("\t\t---欢迎使用学生成绩管理系统---\n");
	while(j){
		i= menu();
		switch(i){
			case 0:
				j=0; 
				printf("退出成功");
				break;
			case 1:
				head=input(head);system("pause");break;//创建节点函数
			case 2:
				head=add(head);system("pause");break;//增加学生信息及成绩
			case 3:
				find(head);system("pause");break;//查询学生信息及成绩
			case 4:
				del(head);system("pause");break;    //删除学生信息及成绩；
			case 5:
				head=change(head);system("pause");break;//05修改学生信息和成绩
			case 6:
				 output(head);system("pause");break;//浏览学生信息及成绩
			case 7:
				 file(head);system("pause");break;//（自己创新）保存到桌面
			case 8:
				 main1(head);system("pause");break;//（创新）学生成绩分析
			default:break;
	
		}
		printf("\n");
		printf("\t\t——————————————\n");
	}//while结束
	system("pause");
 }
