#include<stdio.h>
//�ṹ��
struct node
{
	int date;	//ѧ��
	int me_class;	  //�༶
	double yuwen;//���ĳɼ�
	double shuxue;//��ѧ�ɼ�
	double yingyu;//Ӣ��ɼ�
	double num;			//�ܷ�
	double avg;			//ƽ����
	char name[20];		//����	 
	char kemu[20];		//��ѡ��Ŀ
	struct node *next;
};
struct node*input(struct node*head);   //01¼��ѧ�������Ϻͳɼ�.
struct node*add(struct node*head);	   //02����ѧ����Ϣ���ɼ�
struct node*find(struct node*head);    //3.��ѯѧ����Ϣ���ɼ�
void del(struct node*head);			   //04ɾ��ѧ����Ϣ���ɼ���
struct node*change(struct node*head);  //05�޸�ѧ����Ϣ�ͳɼ�
struct node* output(struct node*head); //06���ѧ����Ϣ���ɼ�
void file(struct node*head);   //�ļ��в�����

 //���˵�
int menu(){
	 int i=1;
		printf("\t\t 1.¼��ѧ����Ϣ���ɼ�\n");
		printf("\t\t 2.����ѧ����Ϣ���ɼ�\n");
		printf("\t\t 3.��ѯѧ����Ϣ���ɼ�\n");
		printf("\t\t 4.ɾ��ѧ����Ϣ���ɼ�\n");
		printf("\t\t 5.�޸�ѧ����Ϣ���ɼ�\n");
		printf("\t\t 6.���ѧ����Ϣ���ɼ�\n");
		printf("\t\t 7.����ѧ���ɼ���c��\n");
		printf("\t\t 8.�ɼ�����ϵͳ\n");
		printf("\t\t 0.�˳�\n");
		printf("\t\t-----------------------------\n");
		printf("\t��ѡ�����\n");
		scanf_s("%d",&i);
		while(1)
		{
			if(i<0||i>8)
			{
				printf("***û�д�ѡ�������ѡ��***\n");
				system("pause");
			}
			break;
		}

	return i;
}
struct node *last;//β�ڵ�
 //01¼��ѧ�������Ϻͳɼ�.
 struct node*input(node *head)//
{
	int i=0,j=1;
	struct node *p,*n;
	p=(struct node*)malloc(sizeof(struct node));
	p=head;
	while(1)
	{

		if(j>0)
		{
			i++;
			n=(struct node*)malloc(sizeof(struct node));
			printf("�������%d��ѧ����ѧ�ţ�����\n",i);
			scanf("%d %s",&n->date,&n->name);
			getchar();
			printf("�������Ŀ���Ļ����Ͱ༶��1����2��\n");
			scanf("%s %d",&n->kemu,&n->me_class);
			fflush(stdin);
			printf("���䵱ǰѧ�������ģ���ѧ��Ӣ��ɼ�\n");
			scanf("%lf %lf %lf",&n->yuwen,&n->shuxue,&n->yingyu);
			getchar();
			n->num=n->yuwen+n->shuxue+n->yingyu;
			n->avg=(p->num)/3;
			
			p->next=n;
			p=n;
			printf("�Ƿ����������һ��ͬѧ����Ϣ������ 1 ����������  0  ��ֹͣ����\n");
			fflush(stdin);
			scanf("%d",&j);
			fflush(stdin);
		}
	
		else 
		{
			p->next=last=NULL;
				p=last;
			
			break;
		}
	}
	free(p);//�ͷ�p
	return head;
}
//02����ѧ����Ϣ���ɼ�
 struct node*add(struct node*head)
 {
	 if(head->next==NULL)
	 {
		printf("��û�д洢���ݣ����ȴ洢����");
		return head;
	 }
	 else
	{
		struct node*head1,*p;
		head1=(struct node*)malloc(sizeof(struct node));
		printf("�������ѧ����Ϣ���ɼ�\n");
		head1=input(head1);//����Ľڵ�������ķ�ʽ�洢.
		p=head->next;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=head1->next;//��Ϊͷ����ǿյ�����Ӧ������ͷ������һ���ڵ㡣
		return head;
	 }
 }
  //3.��ѯѧ����Ϣ���ɼ�
 struct node*find(struct node*head)
 {
	int i;
	struct node*p;
	if(head==NULL)
	{
		printf("��û�д洢���ݣ����ȴ洢����\n");
	}
	else
	{
		printf("��������Ҫ�Ҳ��ѧ��:");
		scanf("%d",&i);
		p=head->next;
		while(p->date!=i&&p->next!=NULL)
		{
				p=p->next;
		}
			if(p->date==i)
			{
				printf("ѧ��\t����\t�༶\t��Ŀ\t����\t\t��ѧ\t\tӢ��\n");
				printf("%d\t%s\t%d\t%s\t%lf\t%lf\t%lf",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
				printf("\n");
				return p;
			}
			else
			{
			printf("û���ҵ���Ҫ���ҵ�ͬѧ\n");
			return NULL;
			}
	}
	
 }
 //04ɾ��ѧ����Ϣ���ɼ���
 void del(struct node*head)
 {
 int key,j=0;
	struct node*p,*s;
	s=head->next;
	p=head;
	printf("��������Ҫɾ��ѧ����ѧ��");
	fflush(stdin);//ɾ����������ݡ�
	scanf("%d",&key);
	
	while(s!=NULL)
	{
		if(s->date!=key)
		{
			p=s;
			s=s->next;
		}
		else
			break;	
	}
	if(s!=NULL)
	{
		p->next=s->next;
		free(s);
		printf("ɾ���ɹ�\n");
	}
	else
		printf("ɾ��ʧ��\n");
 }
 //05�޸�ѧ����Ϣ�ͳɼ�
 struct node*change(struct node*head)
 {
	struct node*p=NULL;
	p=find(head);
	if(p==NULL)
	{
		printf("�޸�ʧ��\n");
		return head;
	}
	else
	{
		printf("�������޸ĵ�ѧ����Ϣ\n");
		printf("���� �༶ ��Ŀ\n");
		scanf("%s %d %s",&p->name,&p->me_class ,&p->kemu);
		fflush(stdin);
		printf("�������޸ĵ�ѧ���ɼ�\n");
		printf("���� ��ѧ Ӣ��\n");
		scanf("%lf %lf %lf",&p->yuwen,&p->shuxue,&p->yingyu);
		fflush(stdin);//getchar()
		printf("\nѧ��\t����\t�༶\t��Ŀ\t����\t\t��ѧ\t\tӢ��\n");
		printf("%d\t%s\t%d\t%s\t%lf\t%lf\t%lf\n",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
		return head;
	}
 }
 //06���ѧ����Ϣ���ɼ�(����)
 struct node* output(struct node*head)
 {
	if(head==NULL)
		printf("��û������������������\n");
	else
	{
		struct node *p;
		p=head->next;
		printf("ѧ��\t����\t�༶\t��Ŀ\t����\t\t��ѧ\t\tӢ��\n");
		while(p!=NULL)
		{
			printf("%d\t%s\t%d\t%s\t%lf\t%lf\t%lf",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
			p=p->next;
			printf("\n");
		}
	printf("\n");
	
	}
	return head;
 }
 void file(struct node*head)
 {
 int i=0;
	FILE *fp;
	struct node*p=head->next;
	fp=fopen("C:\\ѧ���ɼ���.txt","wt");

	fprintf(fp,"ѧ��\t����\t�༶\t��Ŀ\t����\t\t   ��ѧ\t\t   Ӣ��\n");
	 while(p!=NULL) 
 {
	 fprintf(fp,"%d\t%s\t%d\t%s\t%lf\t\t%lf\t\t%lf\n",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
	 p = p->next;
	 i++;
 }
	 if(i>0)
		 printf("\t\t\t\t\t�����������ɹ�����c�̡���������\n");
	 else printf("\t\t\t\t\t����������û�����ݱ���ʧ�ܵ����桪��������\n");
	fclose(fp);
 
 }