#include <iostream>
#include "BinaryTree.h"

using namespace std;

void test_constr()
{
    BinaryTree myTree;
}

void test_insert()
{
    BinaryTree myTree;
    myTree.putItem(50,"test");
    myTree.putItem(75,"test");
    myTree.putItem(25,"test");
    myTree.putItem(85,"test");
    myTree.putItem(65,"test");
    myTree.putItem(15,"test");
    myTree.putItem(35,"test");
    cout << "test print\n";
    myTree.print();
}

void test_getItem()
{
    BinaryTree myTree;
    myTree.putItem(2,"two");
    myTree.putItem(1,"one");
    myTree.putItem(3,"three");
    for(int i = 0; i < 3; ++i)
        cout << "calling getItem on " << i <<  " (present) result: " << myTree.getItem(i) << endl;
    cout << "calling getItem on 4 (not present) result: " << myTree.getItem(4) << endl;
}

void test_getLength()
{
    BinaryTree myTree;
    myTree.putItem(2,"two");
    myTree.putItem(1,"one");
    myTree.putItem(3,"three");
    myTree.putItem(4,"four");
    myTree.putItem(5,"five");
    cout << "test of getLength() on tree with 5 elements: " << myTree.getLength() << endl;
}
void test_deleteItem()
{
    BinaryTree myTree;
    myTree.putItem(2,"two");
    myTree.putItem(1,"one");
    myTree.putItem(3,"three");
    myTree.putItem(4,"four");
    myTree.putItem(0,"zero");
    myTree.print();
    for(int i = 2; i < 5; ++i)
        myTree.deleteItem(i);
}

int main()
{
//    test_constr();
//    test_insert();
//    test_getItem();
//    test_getLength();
    test_deleteItem();
    return 0;
}
