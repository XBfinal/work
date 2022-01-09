//#include<iostream>
//#include<cstdlib>
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//typedef struct {//栈元素类型
//	int x;//坐标
//	int y;//坐标
//	int di;//方向
//}position;
//using namespace std;
//
//typedef struct {//栈
//	position *base;
//	position *top;
//	int stacksize;
//}Stack;
///*************************迷宫**********************************/
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
//class boos {//创建了一个角色类
//private:
//	Stack sq_stack;//栈
//	position temp;
//public:
//	/******************************栈的基本方法*******************/
//	void InitStack() {//创建空的栈
//		sq_stack.base = (position *)malloc(sizeof(Stack)*STACK_INIT_SIZE);
//		if (!sq_stack.base) exit(-1);
//		sq_stack.top = sq_stack.base;
//		sq_stack.stacksize = STACK_INIT_SIZE;
//		cout << "栈创建成功" << endl;
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
//	bool Push(position &temp) {//入栈
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
//	bool Pop(position &temp) {//出栈
//		if (StackEmpty())  return 0;
//		sq_stack.top--;
//		temp = *sq_stack.top;
//		return 1;
//	}
//	void free_Stack() {
//		free(sq_stack.base);
//	}
//	/***************************迷宫方法 dfs算法*************************************/
//	bool findMaze(int star_x, int star_y, int end_x, int end_y) {//迷宫的入口和出口坐标
//		int i, j, k = 0;//ij表示目前的坐标
//		int tep_di, next_x, next_y;//下一步的坐标
//		bool flag;
//		position fan_maze[200];
//		InitStack();//先创建空栈
//		temp.x = star_x, temp.y = star_y, temp.di - 1;//开始位置
//		Push(temp);//入栈操作。
//		Maze[star_x][star_y] = -1;//-1表示走过；
//		while (!StackEmpty()) {//栈不为空
//			GetTop(temp);
//			i = temp.x, j = temp.y, tep_di = temp.di;
//			if (i == end_x && j == end_y) {
//				cout << "找到走出迷宫的路" << endl;
//				k = 0;
//				while (!StackEmpty()) {
//					Pop(temp);
//					fan_maze[k] = temp;
//					k++;//k指向下一个被插入的位置；
//				}
//				cout << "起点：" << "(" << fan_maze[k - 1].x << ',' << fan_maze[k - 1].y << ")->" << endl;
//				int count = 1;
//				for (k -= 2; k > 0; k--) {
//					cout << "(" << fan_maze[k].x << ',' << fan_maze[k].y << ")->";
//					if (count % 3 == 0) cout << endl;
//					count++;
//				}
//				cout << "(" << fan_maze[0].x << ',' << fan_maze[0].y << ")" << "终点" << endl;//出口的位置
//				free_Stack();//释放申请的堆空间
//				输出图像 
//				cout << "\n" << "*表示路线" << endl;
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
//				(sq_stack.top - 1)->di = tep_di;//记录上次坐标走的方向。
//				temp.x = next_x, temp.y = next_y, temp.di = -1;
//				Push(temp);//这次坐标入栈
//				Maze[next_x][next_y] = -1;//当前坐标标记为走过。
//			}
//			else {
//				Pop(temp);
//				Maze[temp.x][temp.y] = 0;
//			}
//
//		}
//		cout << "没有找到对应的出口" << endl;
//
//		free_Stack();//释放申请的堆空间
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