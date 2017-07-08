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
    myTree.putItem(2,"two");
    myTree.putItem(1,"one");
    myTree.putItem(3,"three");
    cout << "test print\n";
    myTree.print();
}

void test_getItem()
{
    string result = "";
    BinaryTree myTree;
    myTree.putItem(2,"two");
    myTree.putItem(1,"one");
    myTree.putItem(3,"three");
    cout << "calling getItem on 2 (present) result: " << myTree.getItem(2) << endl;
    cout << "calling getItem on 4 (not present) result: " << myTree.getItem(4) << endl;
}

int main()
{
//    test_constr();
//    test_insert();
    test_getItem();
    return 0;
}
