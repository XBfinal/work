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
	printf("\t\t---��ӭʹ��ѧ���ɼ�����ϵͳ---\n");
	while(j){
		i= menu();
		switch(i){
			case 0:
				j=0; 
				printf("�˳��ɹ�");
				break;
			case 1:
				head=input(head);system("pause");break;//�����ڵ㺯��
			case 2:
				head=add(head);system("pause");break;//����ѧ����Ϣ���ɼ�
			case 3:
				find(head);system("pause");break;//��ѯѧ����Ϣ���ɼ�
			case 4:
				del(head);system("pause");break;    //ɾ��ѧ����Ϣ���ɼ���
			case 5:
				head=change(head);system("pause");break;//05�޸�ѧ����Ϣ�ͳɼ�
			case 6:
				 output(head);system("pause");break;//���ѧ����Ϣ���ɼ�
			case 7:
				 file(head);system("pause");break;//���Լ����£����浽����
			case 8:
				 main1(head);system("pause");break;//�����£�ѧ���ɼ�����
			default:break;
	
		}
		printf("\n");
		printf("\t\t����������������������������\n");
	}//while����
	system("pause");
 }
