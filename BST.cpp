// Tuan Phan
// main.cpp

#include <iostream>
#include <cstdlib>
#include <stack>
#include "BST.hpp"

using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::BST(const BST& t)
{
    if(t.root == nullptr)
        root = nullptr;
    else
        root = copy(t.root);
}

BST::node* BST::copy(node* Ptr)
{
     if(Ptr==nullptr)
         return nullptr;
     else{
         node* temp = new node;
         temp->key = Ptr->key;
         temp->left = copy(Ptr->left);
         temp->right = copy(Ptr->right);
         return temp;
     }
}

BST& BST::operator=(const BST& rhs)
{
    if(this != &rhs)
    {
        DeleteAll(root);
        root = copy(rhs.root);
    }
    return *this;
}

void BST::DeleteAll(node* Ptr)
{
     if(Ptr)
     {
         DeleteAll(Ptr->left);
         DeleteAll(Ptr->right);
         delete Ptr;
     }
}

BST::~BST()
{
    DeleteAll(root);
}

void BST::Insert(int key)
{
    Insert(root, key);
}

void BST::Insert(node*& Ptr, int key)
{
    if(Ptr == nullptr){
        Ptr = new node;
        Ptr->key = key;
        Ptr->left = nullptr;
        Ptr->right = nullptr;
    }
    //no duplicate value
    else if(Ptr->key == key){
        return;
    }
    else if(Ptr->key > key){
        Insert(Ptr->left, key);
    }
    else{
        Insert(Ptr->right, key);
    }
}

void BST::PrintPreOrder()
{
    PrintPreOrder(root);
}

void BST::PrintPreOrder(node* Ptr)
{
    if(Ptr != nullptr) {
        cout << Ptr->key << " ";
        PrintPreOrder(Ptr->left);
        PrintPreOrder(Ptr->right);
    }
}

bool BST::Search(int key)
{
    return Search(root, key);
}

bool BST::Search(node* Ptr, int key)
{
    if(Ptr==nullptr)
        return false;
    else if(Ptr->key == key)
        return true;
    else if(Ptr->key < key)
        return Search(Ptr->right, key);
    else
        return Search(Ptr->left, key);
}

int BST::Height()
{
    return Height(root);
}

int BST::Height(node* Ptr)
{
    if(Ptr == nullptr){
        return 0;
    }
    else {
        int leftHeight = Height(Ptr->left);
        int rightHeight = Height(Ptr->right);
        if(leftHeight > rightHeight)
            return 1 + leftHeight;
        else
            return 1 + rightHeight;
    }
}

void BST::PrintInOrderIteratively()
{
    stack<node*> stack;
    node* current = root;
    while (current != nullptr || !stack.empty()){
        if (current != nullptr){
            stack.push(current);
            current = current->left;
        }else{
            current = stack.top();
            stack.pop();
            cout << current->key << " ";
            current = current->right;
        }
    }
}

int BST::findMin(node* Ptr)
{
    while (Ptr->left != NULL )
        Ptr = Ptr->left;
    return Ptr->key;
}

BST::node* BST::DeleteNode(int value)
{
    return DeleteNode(root, value);
}


BST::node* BST::DeleteNode(node*& Ptr, int value)
{
    //root is empty
    if (Ptr == nullptr)
        return Ptr;
    //traverse the node
    else if (value < Ptr->key)
        Ptr->left = DeleteNode(Ptr->left, value);
    else if (value > Ptr->key)
        Ptr->right = DeleteNode(Ptr->right, value);
    // root->key == value, delete this node
    else
    {
        // case 1: no child
        if(Ptr->left == nullptr && Ptr->right == nullptr){
            delete Ptr;
            Ptr = nullptr;
            return Ptr;
        }
        // case 2: one child
        else if (Ptr->left == nullptr)
        {
            node* temp = Ptr;
            Ptr = Ptr->right;
            delete temp;
        }
        else if (Ptr->right == nullptr)
        {
            node* temp = Ptr;
            Ptr = Ptr->left;
            delete temp;
        }
        //case 3: 2 child
        else{
            Ptr->key = findMin(Ptr->right);
            Ptr->right = DeleteNode(Ptr->right, Ptr->key);
        }
    }
    return Ptr;
}

