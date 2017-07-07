#include <string>
#include <iostream>

using namespace std;

struct tNode
{
    int key;
    string val;
    tNode * right;
    tNode * left;
    tNode(int k, string v)
    : key (k), val (v), right (nullptr), left(nullptr) 
    {}
};

class BinaryTree
{
  public:
    BinaryTree()
    : root (nullptr)
    {}
    ~BinaryTree()
    {}
    void makeEmpty();
    bool isEmpty()
    {
        return root == nullptr;
    }
    bool isFull();
    int getLength();
    int getItem(int key);
    void putItem(int key, string val)
    {
	tNode * newNode = new tNode(key,val);
	insert(root,newNode);
    }
    void insert(tNode * & tempRoot, tNode * newNode)
    {
        if(tempRoot == nullptr)
	    tempRoot = newNode;
        else if ( newNode->key > tempRoot->key )
	    insert(tempRoot->right, newNode);
        else
            insert(tempRoot->left, newNode);	   
    }
    void deleteItem(int key);
    void print()
    {
	if(isEmpty())
	    cout << "the list is empty\n";
	else
	    inOrderTrav(root);
    }
    void inOrderTrav(tNode * tempRoot)
    {
        if( tempRoot != nullptr)
	{
	    inOrderTrav(tempRoot->left);
	    cout << "key: " << tempRoot->key  << " value: " << tempRoot->val << endl;
	    inOrderTrav(tempRoot->right);
	}
    }
  private:
    tNode * root;
};
