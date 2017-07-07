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

int main()
{
//    test_constr();
    test_insert();
    return 0;
}
