#include <iostream>

using namespace std;

struct node
{
    int key;
    node* next;
};

node* createNode(int key)
{
    node* p = new node;
    p->key = key;
    p->next = NULL;
    return p;
}

struct list
{
    node* head;
    node* tail;
};

void initList(list &l)
{
    l.head = l.tail = NULL;
}

void addFirst(list &l, node* p)
{
    p->next = l.head;
    l.head = p;
    if (l.tail == NULL)
        l.tail = l.head;
}

void addLast(list &l, node* p)
{
    if (l.head == NULL)
        addFirst(l, p);
    else
    {
        l.tail->next = p;
        l.tail = p;
    }
}

void input(list &l)
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cout << "Nhap gia tri: ";
        cin >> num;
        addLast(l, createNode(num));
    }
}

void output(list l)
{
    cout << "Current list: ";
    if (l.head == NULL)
    {
        cout << "!empty\n";
        return;
    }
    node* cur = l.head;
    while (cur != NULL)
    {
        cout << cur->key << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    list l;
    input(l);
    output(l);
    return 0;
}