#include <iostream>
#include <stack>
using namespace std;
typedef struct BigNum {
	int n;
	struct BigNum *next;
}ans;
ans **head = new ans*();//创建一个指向链表头指针的指针
void Func(int num) {//使用链表计算大数的阶乘
	int flag = 2;//从2开始累乘
	while (flag <= num) {
		ans *tmp = *head;//把指向头结点的指针指向的地址赋值给结构体指针
		int last = 0;//记录余数
		while (tmp) {
			int sum = (tmp->n)*flag + last;
			tmp->n = sum % 10;//个位先更新入链表
			last = sum / 10;
			if (last > 0 && !tmp->next) {
				tmp->next = new ans();//发生进位接上新结点
				tmp->next->n = 0;//新结点的n初始化设为0，这样可以在新的循环中刚好被赋值为last的个位
			}
			tmp = tmp->next;
		}
		flag++;
	}
}
void PrintNode(int num) {//倒序输出节点
	stack<int> NodeList;//定义一个Nodelist的栈存放节点
	ans *p = *head;
	while (p) {
		NodeList.push(p->n);//进栈
		p = p->next;
	}
	cout << num << "!=";
	while (!NodeList.empty())
	{
		cout << NodeList.top();//输出栈顶的n
		NodeList.pop();//去掉栈顶存放的值
	}
	cout << endl;
}
int main() {
	int num;
	cout << "请输入需要计算阶乘的数：";
	cin >> num;
	cout << endl;
	if (!(*head)) {
		*head = new ans();
		(*head)->n = 1;
	}//头节点的n初始化为1
	Func(num);
	PrintNode(num);
	delete(*head);
	cout << endl;
	cout << "计算结束" << endl;
	cout << "作者： 白思议" << endl;
	system("pause");
	return 0;
}
