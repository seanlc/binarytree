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
    ~BinaryTree();
    void makeEmpty();
    bool isEmpty()
    {
        return root == nullptr;
    }
    bool isFull();
    int getLength();
    int getItem(int key);
    void putItem(int key, int val);
    void deleteItem(int key);
    void inOrderTrav(tNode * root)
    {
        if( root != nullptr)
	{
	    inOrderTrav(root->right);
	    cout << "key: " << root->key  << " value: " << root->val << endl;
	    inOrderTrav(root->left);
	}
    }
  private:
    tNode * root;
};
