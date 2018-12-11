#include <iostream>
#include <stack>
using namespace std;
typedef struct BigNum {
	int n;
	struct BigNum *next;
}ans;
ans **head = new ans*();//����һ��ָ������ͷָ���ָ��
void Func(int num) {//ʹ�������������Ľ׳�
	int flag = 2;//��2��ʼ�۳�
	while (flag <= num) {
		ans *tmp = *head;//��ָ��ͷ����ָ��ָ��ĵ�ַ��ֵ���ṹ��ָ��
		int last = 0;//��¼����
		while (tmp) {
			int sum = (tmp->n)*flag + last;
			tmp->n = sum % 10;//��λ�ȸ���������
			last = sum / 10;
			if (last > 0 && !tmp->next) {
				tmp->next = new ans();//������λ�����½��
				tmp->next->n = 0;//�½���n��ʼ����Ϊ0�������������µ�ѭ���иպñ���ֵΪlast�ĸ�λ
			}
			tmp = tmp->next;
		}
		flag++;
	}
}
void PrintNode(int num) {//��������ڵ�
	stack<int> NodeList;//����һ��Nodelist��ջ��Žڵ�
	ans *p = *head;
	while (p) {
		NodeList.push(p->n);//��ջ
		p = p->next;
	}
	cout << num << "!=";
	while (!NodeList.empty())
	{
		cout << NodeList.top();//���ջ����n
		NodeList.pop();//ȥ��ջ����ŵ�ֵ
	}
	cout << endl;
}
int main() {
	int num;
	cout << "��������Ҫ����׳˵�����";
	cin >> num;
	cout << endl;
	if (!(*head)) {
		*head = new ans();
		(*head)->n = 1;
	}//ͷ�ڵ��n��ʼ��Ϊ1
	Func(num);
	PrintNode(num);
	delete(*head);
	cout << endl;
	cout << "�������" << endl;
	cout << "���ߣ� ��˼��" << endl;
	system("pause");
	return 0;
}
