//
//  BST.hpp
//  BST
//
//  Created by Tuan Phan on 11/2/19.
//  Copyright © 2019 Tuan Phan. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>

class BST
{
    
private:
    
    struct node
    {
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    
    void DeleteAll(node* Ptr);
    //helper function for destructor
    node* copy(node* Ptr);
    //helper function for copy constructor and assignment operator
    void InsertPrivate(node*& Ptr, int key);
    //Inserts value into tree
    bool SearchPrivate(node* Ptr, int key);
    //Searchs node in tree
    int HeightPrivate(node* Ptr);
    //gets the height of tree
    void PrintPreOrderPrivate(node* Ptr);
    //prints the tree in pre oreder
    int leftMostValue(node* Ptr);
    //helper function for delete node in tree
    node* DeleteNodePrivate(node*& Ptr, int value);
    //deletes node in tree
    node* findNode(node* Ptr, int value);
    node* findParent(node* Ptr, int value);
    void makeDelection(node* Ptr);
    
public:
    
    BST();
    //constructor
    
    BST(const BST& t);
    //copy constructor
    
    BST& operator=(const BST& rhs);
    //assignment operator overload
    
    ~BST();
    //destructor
    
    void Insert(int key);
    //insert node into tree
    
    bool Search(int key);
    
    int Height();
    
    void PrintPreOrder();
    
    void PrintInOrderIteratively();
    //prints nodes in order
    
    node* DeleteNode(int value);
    
    void remove(int value);
};

#endif /* BST_hpp */
