#include<stdio.h>
//结构体
struct node
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
	struct node *next;
};
struct node*input(struct node*head);   //01录入学生的资料和成绩.
struct node*add(struct node*head);	   //02增加学生信息及成绩
struct node*find(struct node*head);    //3.查询学生信息及成绩
void del(struct node*head);			   //04删除学生信息及成绩；
struct node*change(struct node*head);  //05修改学生信息和成绩
struct node* output(struct node*head); //06浏览学生信息及成绩
void file(struct node*head);   //文件夹操作。

 //主菜单
int menu(){
	 int i=1;
		printf("\t\t 1.录入学生信息及成绩\n");
		printf("\t\t 2.增加学生信息及成绩\n");
		printf("\t\t 3.查询学生信息及成绩\n");
		printf("\t\t 4.删除学生信息及成绩\n");
		printf("\t\t 5.修改学生信息及成绩\n");
		printf("\t\t 6.浏览学生信息及成绩\n");
		printf("\t\t 7.保存学生成绩到c盘\n");
		printf("\t\t 8.成绩分析系统\n");
		printf("\t\t 0.退出\n");
		printf("\t\t-----------------------------\n");
		printf("\t请选择序号\n");
		scanf_s("%d",&i);
		while(1)
		{
			if(i<0||i>8)
			{
				printf("***没有此选项。请重新选择***\n");
				system("pause");
			}
			break;
		}

	return i;
}
struct node *last;//尾节点
 //01录入学生的资料和成绩.
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
			printf("请输入第%d个学生的学号，姓名\n",i);
			scanf("%d %s",&n->date,&n->name);
			getchar();
			printf("请输入科目（文或理）和班级（1或者2）\n");
			scanf("%s %d",&n->kemu,&n->me_class);
			fflush(stdin);
			printf("请输当前学生的语文，数学，英语成绩\n");
			scanf("%lf %lf %lf",&n->yuwen,&n->shuxue,&n->yingyu);
			getchar();
			n->num=n->yuwen+n->shuxue+n->yingyu;
			n->avg=(p->num)/3;
			
			p->next=n;
			p=n;
			printf("是否继续输入下一个同学的信息？输入 1 继续，输入  0  就停止输入\n");
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
	free(p);//释放p
	return head;
}
//02增加学生信息及成绩
 struct node*add(struct node*head)
 {
	 if(head->next==NULL)
	 {
		printf("还没有存储数据，请先存储数据");
		return head;
	 }
	 else
	{
		struct node*head1,*p;
		head1=(struct node*)malloc(sizeof(struct node));
		printf("正在添加学生信息及成绩\n");
		head1=input(head1);//插入的节点用链表的方式存储.
		p=head->next;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=head1->next;//因为头结点是空的所以应该链接头结点的下一个节点。
		return head;
	 }
 }
  //3.查询学生信息及成绩
 struct node*find(struct node*head)
 {
	int i;
	struct node*p;
	if(head==NULL)
	{
		printf("还没有存储数据，请先存储数据\n");
	}
	else
	{
		printf("请输入你要找查的学号:");
		scanf("%d",&i);
		p=head->next;
		while(p->date!=i&&p->next!=NULL)
		{
				p=p->next;
		}
			if(p->date==i)
			{
				printf("学号\t姓名\t班级\t科目\t语文\t\t数学\t\t英语\n");
				printf("%d\t%s\t%d\t%s\t%lf\t%lf\t%lf",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
				printf("\n");
				return p;
			}
			else
			{
			printf("没有找到你要查找的同学\n");
			return NULL;
			}
	}
	
 }
 //04删除学生信息及成绩；
 void del(struct node*head)
 {
 int key,j=0;
	struct node*p,*s;
	s=head->next;
	p=head;
	printf("请输入你要删除学生的学号");
	fflush(stdin);//删除缓存的数据。
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
		printf("删除成功\n");
	}
	else
		printf("删除失败\n");
 }
 //05修改学生信息和成绩
 struct node*change(struct node*head)
 {
	struct node*p=NULL;
	p=find(head);
	if(p==NULL)
	{
		printf("修改失败\n");
		return head;
	}
	else
	{
		printf("请输入修改的学生信息\n");
		printf("姓名 班级 科目\n");
		scanf("%s %d %s",&p->name,&p->me_class ,&p->kemu);
		fflush(stdin);
		printf("请输入修改的学生成绩\n");
		printf("语文 数学 英语\n");
		scanf("%lf %lf %lf",&p->yuwen,&p->shuxue,&p->yingyu);
		fflush(stdin);//getchar()
		printf("\n学号\t姓名\t班级\t科目\t语文\t\t数学\t\t英语\n");
		printf("%d\t%s\t%d\t%s\t%lf\t%lf\t%lf\n",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
		return head;
	}
 }
 //06浏览学生信息及成绩(测试)
 struct node* output(struct node*head)
 {
	if(head==NULL)
		printf("还没有数据请先输入数据\n");
	else
	{
		struct node *p;
		p=head->next;
		printf("学号\t姓名\t班级\t科目\t语文\t\t数学\t\t英语\n");
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
	fp=fopen("C:\\学生成绩单.txt","wt");

	fprintf(fp,"学号\t姓名\t班级\t科目\t语文\t\t   数学\t\t   英语\n");
	 while(p!=NULL) 
 {
	 fprintf(fp,"%d\t%s\t%d\t%s\t%lf\t\t%lf\t\t%lf\n",p->date,p->name,p->me_class,p->kemu,p->yuwen,p->shuxue,p->yingyu);
	 p = p->next;
	 i++;
 }
	 if(i>0)
		 printf("\t\t\t\t\t—————成功保存c盘—————\n");
	 else printf("\t\t\t\t\t—————没有数据保存失败到桌面—————\n");
	fclose(fp);
 
 }