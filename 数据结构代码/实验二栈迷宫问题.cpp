//#include<iostream>
//#include<cstdlib>
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//typedef struct {//ջԪ������
//	int x;//����
//	int y;//����
//	int di;//����
//}position;
//using namespace std;
//
//typedef struct {//ջ
//	position *base;
//	position *top;
//	int stacksize;
//}Stack;
///*************************�Թ�**********************************/
//int Maze[10][10] = {
//	   0 1 2 3 4 5 6 7 8 9 
//		{1,1,1,1,1,1,1,1,1,1},//0
//		{1,0,0,1,0,0,0,1,0,1},//1
//		{1,0,0,1,0,0,0,1,0,1},//2
//		{1,0,0,0,0,1,1,0,0,1},//3
//		{1,0,1,1,1,0,0,0,0,1},//4
//		{1,0,0,0,1,0,0,0,0,1},//5
//		{1,0,1,0,0,0,1,0,0,1},//6
//		{1,0,1,1,1,0,1,1,0,1},//7
//		{1,1,0,0,0,0,0,0,0,1},//8
//		{1,1,1,1,1,1,1,1,1,1} //9
//};
//class boos {//������һ����ɫ��
//private:
//	Stack sq_stack;//ջ
//	position temp;
//public:
//	/******************************ջ�Ļ�������*******************/
//	void InitStack() {//�����յ�ջ
//		sq_stack.base = (position *)malloc(sizeof(Stack)*STACK_INIT_SIZE);
//		if (!sq_stack.base) exit(-1);
//		sq_stack.top = sq_stack.base;
//		sq_stack.stacksize = STACK_INIT_SIZE;
//		cout << "ջ�����ɹ�" << endl;
//	}
//	bool StackEmpty() {
//		if (sq_stack.top == sq_stack.base)return 1;
//		else
//			return 0;
//	}
//	bool GetTop(position &temp) {
//		if (StackEmpty())return false;
//		temp = *(sq_stack.top - 1);
//		return true;
//	}
//	bool Push(position &temp) {//��ջ
//		if (sq_stack.top - sq_stack.base >= sq_stack.stacksize) {
//			sq_stack.base = (position*)realloc(sq_stack.base, sizeof(position)*(sq_stack.stacksize + STACKINCREMENT));
//			if (!sq_stack.base) exit(-1);
//			sq_stack.top = sq_stack.base + sq_stack.stacksize;
//			sq_stack.stacksize += STACKINCREMENT;
//		}
//
//		*sq_stack.top = temp;
//		sq_stack.top++;
//		return true;
//	}
//	bool Pop(position &temp) {//��ջ
//		if (StackEmpty())  return 0;
//		sq_stack.top--;
//		temp = *sq_stack.top;
//		return 1;
//	}
//	void free_Stack() {
//		free(sq_stack.base);
//	}
//	/***************************�Թ����� dfs�㷨*************************************/
//	bool findMaze(int star_x, int star_y, int end_x, int end_y) {//�Թ�����ںͳ�������
//		int i, j, k = 0;//ij��ʾĿǰ������
//		int tep_di, next_x, next_y;//��һ��������
//		bool flag;
//		position fan_maze[200];
//		InitStack();//�ȴ�����ջ
//		temp.x = star_x, temp.y = star_y, temp.di - 1;//��ʼλ��
//		Push(temp);//��ջ������
//		Maze[star_x][star_y] = -1;//-1��ʾ�߹���
//		while (!StackEmpty()) {//ջ��Ϊ��
//			GetTop(temp);
//			i = temp.x, j = temp.y, tep_di = temp.di;
//			if (i == end_x && j == end_y) {
//				cout << "�ҵ��߳��Թ���·" << endl;
//				k = 0;
//				while (!StackEmpty()) {
//					Pop(temp);
//					fan_maze[k] = temp;
//					k++;//kָ����һ���������λ�ã�
//				}
//				cout << "��㣺" << "(" << fan_maze[k - 1].x << ',' << fan_maze[k - 1].y << ")->" << endl;
//				int count = 1;
//				for (k -= 2; k > 0; k--) {
//					cout << "(" << fan_maze[k].x << ',' << fan_maze[k].y << ")->";
//					if (count % 3 == 0) cout << endl;
//					count++;
//				}
//				cout << "(" << fan_maze[0].x << ',' << fan_maze[0].y << ")" << "�յ�" << endl;//���ڵ�λ��
//				free_Stack();//�ͷ�����Ķѿռ�
//				���ͼ�� 
//				cout << "\n" << "*��ʾ·��" << endl;
//				for (int a = 0; a < 10; a++) {
//					for (int b = 0; b < 10; b++) {
//						if (Maze[a][b] == -1) { cout << '*' << "\t"; }
//						else cout << Maze[a][b] << "\t";
//						if (b == 9)cout << endl;
//					}
//				}
//				return true;
//			}
//			flag = 1;
//			while (tep_di < 4 && flag) {
//				tep_di++;
//				if (tep_di == 0) { next_x = i;	next_y = j + 1; }
//				else if (tep_di == 1) { next_x = i + 1; next_y = j; }
//				else if (tep_di == 2) { next_x = i; next_y = j - 1; }
//				else { next_x = i - 1; next_y = j; }
//
//				if (Maze[next_x][next_y] == 0) flag = 0;
//			}
//			if (!flag) {
//				(sq_stack.top - 1)->di = tep_di;//��¼�ϴ������ߵķ���
//				temp.x = next_x, temp.y = next_y, temp.di = -1;
//				Push(temp);//���������ջ
//				Maze[next_x][next_y] = -1;//��ǰ������Ϊ�߹���
//			}
//			else {
//				Pop(temp);
//				Maze[temp.x][temp.y] = 0;
//			}
//
//		}
//		cout << "û���ҵ���Ӧ�ĳ���" << endl;
//
//		free_Stack();//�ͷ�����Ķѿռ�
//		return false;
//	}
//
//};
//int main() {
//	boos L1;
//	L1.findMaze(1, 1, 8, 8);
//	system("pause");
//	return 0;
//}