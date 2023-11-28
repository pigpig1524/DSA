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

void insertOrder(list &l, node* p)
{
    /* 
        Gia su list dc sap xep tang dan;
        chen p vao list sao cho van giu dc thu tu
    */
   if (l.head == NULL)
   {
        addFirst(l, p);
        return;
   }
   if (l.head->key >= p->key)
   {
        addFirst(l, p);
        return;
   }
   node* cur = l.head;
   while (cur->next != NULL)
   {
        if (p->key <= cur->next->key)
        {
            p->next = cur->next;
            cur->next = p;
            return;
        }
        cur = cur->next;
   }
   addLast(l, p);
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
    int num;
    init(l);
    cout << "-- Khoi ta linked list --\n";
    input(l);
    output(l);
    cout << "-- Dao chieu list --\n";
    reverse(l);
    output(l);
    cout << "-- Them giu thu tu --\n";
    cout << "Nhap gia tri chen: ";
    cin >> num;
    insertOrder(l, createNode(num));
    output(l);
    return 0;
}