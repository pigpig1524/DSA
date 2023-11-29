#include <iostream>

using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};

node* createNode(int key)
{
    node* p = new node;
    p->key = key;
    p->left = p->right = NULL;
    return p;
}

void insertNode(node* &root, int key)
{
    if (root == NULL)
        root = createNode(key);
    else if (key < root->key)
        insertNode(root->left, key);
    else if (key > root->key)
        insertNode(root->right, key);
}

void preorder(node* root)
{
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node* root = NULL;
    insertNode(root, 1);
    preorder(root);
    return 0;
}