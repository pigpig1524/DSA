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

void addFirst(list &l, int data)
{
    node* p = createNode(data);
    p->next = l.head;
    l.head = p;
    if (l.tail == NULL)
        l.tail = l.head;
}

int main()
{
    cout << "-- Chuong trinh ve danh sach lien ket don --\n";
    cout << "Nhap mot gia tri: ";
    int num;
    cin >> num;
    list l;
    initList(l);
    addFirst(l, num);
    return 0;
}