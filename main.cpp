// Tuan Phan
// main.cpp


#include <iostream>
#include <cstdlib>
#include "BST.hpp"

using namespace std;

const int SIZE = 20;

int main() {
    int input = 0;
    int arr[SIZE] = {20, 15, 25, 13, 23, 18, 28, 4, 30, 16,
                    19, 17, 18, 14, 12, 11, 24, 26, 25, 29};
    
    cout << "Creating myTree1" << endl;
    BST myTree1;
    
    cout << "Adding 20 random values into myTree1, no duplicate value allowed" << endl;
    for(int i = 0; i < SIZE; i++){
        myTree1.Insert(arr[i]);
    }
    
    cout << "Printing myTree1 in pre order" << endl;
    myTree1.PrintPreOrder();
    cout << endl;
    
    cout << "The height of myTree is: " << myTree1.Height() << endl;
    
    cout << "Enter a key value to search: ";
    cin >> input;
    if(myTree1.Search(input))
        cout << input << " is in myTree" << endl;
    else
        cout << input << " is not in myTree" << endl;
    
    cout << "Creating myTree2 has the same elements with myTree1" << endl;
    BST myTree2 = myTree1;
    
    cout << "Printing myTree1 in order" << endl;
    myTree1.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Printing myTree2 in order (values in myTree2 will the same with myTree1)" << endl;
    myTree2.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Creating myTree3" << endl;
    BST myTree3;
    
    cout << "Adding random values to myTree2" << endl;
    myTree3.Insert(100);
    myTree3.Insert(90);
    myTree3.Insert(110);
    myTree3.Insert(67);
    myTree3.Insert(123);
    myTree3.Insert(5);
    
    cout << "Printing myTree3 in pre order" << endl;
    myTree3.PrintPreOrder();
    cout << endl;
    
    cout << "Assign myTree1 into myTree3" << endl;
    myTree3 = myTree1;
    
    cout << "Printing myTree1 in order" << endl;
    myTree1.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Printing myTree3 in order (values in myTree2 will the same with myTree1)" << endl;
    myTree2.PrintInOrderIteratively();
    cout << endl;
    
    cout << "Enter a value to delete in myTree1. Enter -1 to stop the process\n";
    while(input != -1) {
        cout << "Delete value: ";
        cin >> input;
        {
            if(input != -1){
                myTree1.DeleteNode(input);
                cout << "myTree1: ";
                myTree1.PrintInOrderIteratively();
                cout<<endl;
            }
        }
    }
    
    return 0;
}
