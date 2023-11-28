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

int main()
{
    cout << "-- Chuong trinh ve danh sach lien ket don --\n";
    cout << "Nhap mot gia tri: ";
    int num;
    cin >> num;
    list l;
    initList(l);
    addFirst(l, createNode(num));
    return 0;
}