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

void init(list &l)
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

void reverse(list &l)
{
    if (l.head == NULL)
        return;
    node* cur = l.head;
    node* tmp = NULL;
    while (cur != NULL)
    {
        node* next = cur->next;
        cur->next = tmp;
        tmp = cur;
        cur = next;
    }
    tmp = l.head;
    l.head = l.tail;
    l.tail = tmp;
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
    init(l);
    cout << "-- Khoi ta linked list --\n";
    input(l);
    output(l);
    cout << "-- Dao chieu list --\n";
    reverse(l);
    output(l);
    return 0;
}