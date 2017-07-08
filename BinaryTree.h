#include <string>
#include <iostream>
#include <iomanip>

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
    string getItem(int key)
    {
	tNode * temp = findNode(root,key);
	return (temp == nullptr) ? "not found" : temp->val;
    }
    void putItem(int key, string val)
    {
	tNode * newNode = new tNode(key,val);
	insert(root,newNode);
    }
    void deleteItem(int key);
    void print()
    {
	if(isEmpty())
	    cout << "the list is empty\n";
	else
	{
	    int level = 0;
	    visual_rep(root, level);
	    inOrderTrav(root);
	}
    }
  private:
    tNode * root;
    tNode * findNode(tNode * tRoot, int key)
    {
	if(tRoot == nullptr)
	    return nullptr;
        if (tRoot->key == key)
	    return tRoot;
	else if(key > tRoot->key)
	    findNode(tRoot->right, key);
	else if(key < tRoot->key)
	    findNode(tRoot->left, key);
	return nullptr;
    }
    void visual_rep(tNode * tRoot, int level)
    {
	if(tRoot != nullptr)
	{
	    visual_rep(tRoot->right, ++level);
	    cout << setw(10 * level) << "key: " << tRoot->key << " val: " << tRoot->val << endl;
	    level = 0;
	    visual_rep(tRoot->left, ++level);
	}
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
    void insert(tNode * & tempRoot, tNode * newNode)
    {
        if(tempRoot == nullptr)
	    tempRoot = newNode;
        else if ( newNode->key > tempRoot->key )
	    insert(tempRoot->right, newNode);
        else
            insert(tempRoot->left, newNode);	   
    }
};
