#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* CreateNode(int n)  
{
    Node* head = NULL, * pnew = NULL, * ptail = NULL;  
    int num, i = 1;
    while (i <= n)
    {
        pnew = new Node;
        cout << "�����" << i << "�����:" << endl;
        cin >> num;
        pnew->data = num;
        pnew->next = NULL;
        if (head == NULL)
            head = pnew;
        else
        {
            ptail->next = pnew;
        }
        ptail = pnew;
        i++;
    }
    pnew = NULL;
    delete pnew;
    return head;
}

void PrintNode(Node* head, int n)
{
    Node* p;
    p = head;
    for (int i = 0; i < n; i++)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    int n; //������
    cout << "�����������" << endl;
    cin >> n;
    Node* head;
    head = CreateNode(n);
    PrintNode(head, n);
    return 0;
}
