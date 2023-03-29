#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <string>  

typedef struct node {
	char name[20];
	struct node* prior, * next;
}stud;          

stud* create(int n) {
	stud* p, * h, * s;
	int i;
	h = (stud*)malloc(sizeof(stud)); 
	h->name[0] = '\0';
	h->prior = NULL;
	h->next = NULL;
	p = h;
	for (i = 0; i < n; i++) {
		s = (stud*)malloc(sizeof(stud));
		p->next = s;                 
		printf("输入第%d个学生的姓名：", i + 1);
		scanf("%s", s->name);
		s->prior = p;              
		s->next = NULL;
		p = s;
	}
	p->next = NULL;
	return(h);
}

stud* search(stud* h, char* x) {
	stud* p;             
	char* y;
	p = h->next;
	while (p) {
		y = p->name;
		if (strcmp(y, x) == 0)
			return(p);
		else
			p = p->next;

	}
	printf("没有找到数据！\n");
}

void del(stud* p) {
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
}

int main() {
	int number;
	char sname[20];
	stud* head, * sp;
	puts("请输入链表的大小：");
	scanf("%d", &number);
	head = create(number);
	sp = head->next;
	printf("\n现在这个双链表是：\n");
	while (sp) {
		printf("%s ", &*(sp->name));
		sp = sp->next;
	}
	printf("\n请输入你想查找的姓名：\n");
	scanf("%s", sname);
	sp = search(head, sname);
	printf("你想查找的姓名是：%s\n", *&sp->name);
	del(sp);
	sp = head->next;
	printf("\n现在这个双链表是:\n");
	while (sp) {
		printf("%s ", &*(sp->name));
		sp = sp->next;
	}
	printf("\n");
	puts("\n 按任意键退出...");
}
