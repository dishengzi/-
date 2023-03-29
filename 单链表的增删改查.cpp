#include<iostream>
using namespace std;

typedef struct node
{
	int age;
	string name;
	struct node* next;  
}student;

student* createlist(int n)
{
	
	student* head = new student;
	student* pre = head; 
	for (int i = 0; i < n; i++)
	{
		student* p = new student;
		cout << "请输入第" << i + 1 << "个数据" << endl;
		p->next = NULL;
		cin >> p->name >> p->age;
		pre->next = p;
		pre = p;
	}

	return head;
}

void printlist(student* head, int n)
{
	student* p = head->next;

	for (int i = 0; i < n; i++)
	{
		cout << p->name << p->age << endl;;
		p = p->next; 
	}
}

int main()
{
	int n = 3;
	student* head = createlist(n);
	printlist(head, n);

	system("pause");
	return 0;
}
