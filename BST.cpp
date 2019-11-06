//
//  BST.cpp
//  BST
//
//  Created by Tuan Phan on 11/2/19.
//  Copyright © 2019 Tuan Phan. All rights reserved.
//

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
    InsertPrivate(root, key);
}

void BST::InsertPrivate(node*& Ptr, int key)
{
    if(Ptr == nullptr){
        Ptr = new node;
        Ptr->key = key;
        Ptr->left = nullptr;
        Ptr->right = nullptr;
    }
    else if(Ptr->key == key){
        return;
    }
    else if(Ptr->key > key){
        InsertPrivate(Ptr->left, key);
    }
    else{
        InsertPrivate(Ptr->right, key);
    }
}

void BST::PrintPreOrder()
{
    PrintPreOrderPrivate(root);
}

void BST::PrintPreOrderPrivate(node* Ptr)
{
    if(Ptr != nullptr) {
        cout << Ptr->key << " ";
        PrintPreOrderPrivate(Ptr->left);
        PrintPreOrderPrivate(Ptr->right);
    }
}

bool BST::Search(int key)
{
    return SearchPrivate(root, key);
}

bool BST::SearchPrivate(node* Ptr, int key)
{
    if(Ptr==nullptr)
        return false;
    else if(Ptr->key == key)
        return true;
    else if(Ptr->key < key)
        return SearchPrivate(Ptr->right, key);
    else
        return SearchPrivate(Ptr->left, key);
}

int BST::Height()
{
    return HeightPrivate(root);
}

int BST::HeightPrivate(node* Ptr)
{
    if(Ptr == nullptr){
        return 0;
    }
    else {
        int leftHeight = HeightPrivate(Ptr->left);
        int rightHeight = HeightPrivate(Ptr->right);
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

int BST::leftMostValue(node* Ptr)
{
    while (Ptr->left != NULL )
        Ptr = Ptr->left;
    return Ptr->key;
}

BST::node* BST::DeleteNode(int value)
{
    return DeleteNodePrivate(root, value);
}


BST::node* BST::DeleteNodePrivate(node*& Ptr, int value)
{
    //root is empty
    if (Ptr == nullptr)
        return Ptr;
    //traverse the node
    if (value < Ptr->key)
        Ptr->left = DeleteNodePrivate(Ptr->left, value);
    else if (value > Ptr->key)
        Ptr->right = DeleteNodePrivate(Ptr->right, value);
    else
    {
        // root->key == value, delete this node
        // case 1: leaf node
        if(Ptr->left == nullptr && Ptr->right == nullptr){
            delete Ptr;
            Ptr = nullptr;
            return Ptr;
        }
        // case 2: one child
        else if (Ptr->left == nullptr)
        {
            node* newRoot = Ptr->right;
            delete(Ptr);
            return newRoot;
        }
        else if (Ptr->right == nullptr)
        {
            node* newRoot = Ptr->left;
            delete(Ptr);
            return newRoot;
        }
        //case 3: 2 child
        else{
            Ptr->key = leftMostValue(Ptr->right);
            Ptr->right = DeleteNodePrivate(Ptr->right, Ptr->key);
        }
    }
    return Ptr;
}

BST::node* BST::findNode(node* Ptr, int value)
{
    if(Ptr!=nullptr){
        if(Ptr->key == value){
            return Ptr;
        }
        else {
            if(value < Ptr->key){
                return findNode(Ptr->left, value);
            }
            else {
                return findNode(Ptr->right, value);
            }
        }
    }
    else {
        return nullptr;
    }
}

//BST::node* BST::findParent(node* Ptr, int value)
//{
//    if (Ptr == nullptr)
//       return nullptr;
//
//    if(Ptr->left == nullptr && Ptr->right == nullptr)
//       return nullptr;
//
//    if( (Ptr->left != NULL && Ptr->left->key == value)
//        || (Ptr->right != NULL && Ptr->right->key == value))
//       return Ptr;
//
//    if(Ptr->key > value)
//       return findParent(Ptr->left,value);
//
//    if(Ptr->key < value)
//       return findParent(Ptr->right,value);
//}

//void BST::makeDelection(node* Ptr)
//{
//    node* tmp;
//    if(Ptr->right == nullptr) {
//        tmp = Ptr->left;
//        delete(Ptr);
//    }
//    else if(Ptr->left == nullptr) {
//        tmp = Ptr->left;
//        delete(Ptr);
//    }
//    else {
//        tmp->key = leftMostValue(Ptr->right);
//        Ptr->key = tmp->key;
//        makeDelection(Ptr->right);
//    }
//}
//
//void BST::remove(int value)
//{
//    node* parent;
//    node* removeNode;
//    if(root == nullptr)
//        return;
//    if(root->key == value)
//        makeDelection(root);
//    else {
//        removeNode = findNode(root, value);
//        if(removeNode != nullptr){
//            parent = findParent(root, value);
//            if(parent->left->key == value)
//                makeDelection(parent->left);
//            else
//                makeDelection(parent->right);
//        }        
//    }
//}
