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
    for(int i = 0; i < 3; ++i)
        myTree.putItem(i,"test");
    cout << "test print\n";
    myTree.print();
}

int main()
{
//    test_constr();
    test_insert();
    return 0;
}
