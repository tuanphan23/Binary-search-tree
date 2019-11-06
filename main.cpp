//
//  main.cpp
//  BST
//
//  Created by Tuan Phan on 11/2/19.
//  Copyright © 2019 Tuan Phan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "BST.hpp"

using namespace std;

const int SIZE = 20;

int main() {
    
    int arr[SIZE] = {20, 15, 25, 13, 23, 18, 28, 4, 30, 16,
                    19, 17, 18, 14, 12, 11, 24, 26, 25, 29};
    BST myTree;
    BST myTree2;
    int input = 0;
    
    for(int i = 0; i < SIZE; i++){
        myTree.Insert(arr[i]);
    }
    
    cout << "Printing myTree in order" << endl;
    myTree.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Printing myTree in pre order" << endl;
    myTree.PrintPreOrder();
    cout << endl;
    
    cout << "The height of myTree is: " << myTree.Height() << endl;
    
    cout << "Enter a key value to search: ";
    cin >> input;
    if(myTree.Search(input))
        cout << input << " is in myTree" << endl;
    else
        cout << input << " is not in myTree" << endl;
    
    cout << "Creating myTree1 has the same elements with myTree" << endl;
    BST myTree1 = myTree;
    
    cout << "Printing myTree1 in order" << endl;
    myTree1.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Adding value to myTree2" << endl;
    myTree2.Insert(100);
    myTree2.Insert(90);
    myTree2.Insert(110);
    myTree2.Insert(67);
    myTree2.Insert(123);
    myTree2.Insert(5);
    
    cout << "Printing myTree2 in order" << endl;
    myTree2.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Assign myTree into myTree2" << endl;
    myTree2 = myTree;
    
    cout << "Printing myTree2 in order" << endl;
    myTree2.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Enter a key value to delete in myTree. Enter -1 to stop the process\n";
    while(input != -1) {
        cout << "Delete Node: ";
        cin >> input;
        {
            if(input != -1){
                myTree.DeleteNode(input);
                myTree.PrintInOrderIteratively();
                cout<<endl;
            }
        }
    }
    
    return 0;
}
