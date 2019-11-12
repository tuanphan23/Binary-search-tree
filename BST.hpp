// Tuan Phan
// main.cpp

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
    //pre: none
    //post: root is set to nullptr
    
    node* copy(node* Ptr);
    //helper function for copy constructor and assignment operator
    //pre: none
    //ppst: return new root has the same values of old root
    
    void Insert(node*& Ptr, int key);
    //Inserts value into tree
    //pre: root must be set to nullptr before first call
    //post: value is inserted into tree
    
    bool Search(node* Ptr, int key);
    //Searchs node in tree
    //pre: none
    //post: return the status if value is in tree or not
    
    int Height(node* Ptr);
    //gets the height of tree
    //pre: none
    //post: return the height of tree
    
    void PrintPreOrder(node* Ptr);
    //prints the tree in pre oreder
    //pre: none
    //post: none
    
    int findMin(node* Ptr);
    //helper function for delete node in tree
    //pre: none
    //post: return minimum value in tree
    
    node* DeleteNode(node*& Ptr, int value);
    //deletes node in tree
    //pre: none
    //post: return root without deleted node
    
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
    //Inserts value into tree
    
    bool Search(int key);
    //Searchs node in tree
    
    int Height();
    //gets the height of tree
    
    void PrintPreOrder();
    //prints the tree in pre oreder
    
    void PrintInOrderIteratively();
    //prints nodes in order
    //pre: none
    //post: none
    
    node* DeleteNode(int value);
    //deletes node in tree
    
};

#endif /* BST_hpp */
