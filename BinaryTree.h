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
    : root (nullptr), numNodes (0)
    {}
    ~BinaryTree()
    {}
    void makeEmpty();
    bool isEmpty()
    {
        return root == nullptr;
    }
    bool isFull();
    int getLength()
    {
        return numNodes;
    }
    string getItem(int key)
    {
	tNode * temp = findNode(root,key);
	return (temp == nullptr) ? "not found" : temp->val;
    }
    void putItem(int key, string val)
    {
	tNode * newNode = new tNode(key,val);
	insert(root,newNode);
	++numNodes;
    }
    void deleteItem(int key)
    {
        tNode * foundNode = findNode(root,key);
	cout << "return val of findNode: " << foundNode << endl;
	if(foundNode == nullptr)
	{
	    fprintf(stderr, "node not found with key %d\n", key);
	    exit(-1);
	}
	// node has one child
	if( (foundNode->right == nullptr && foundNode->left != nullptr)
	|| ( foundNode->right != nullptr && foundNode->left == nullptr))
	    deleteSingleChildNode(foundNode);
	// node has two children
	else if(foundNode->right != nullptr && foundNode->left != nullptr)
	    deleteDoubleChildNode(foundNode);
	// node has no children
	else
	    deleteNoChildNode(foundNode);
    }
    void print()
    {
	if(isEmpty())
	    cout << "the list is empty\n";
	else
	{
	    int level = 0;
	    visual_rep(root, level);
	}
    }
  private:
    tNode * root;
    int numNodes;
    tNode * findNode(tNode * tRoot, int key)
    {
	if(tRoot != nullptr)
	    cout << "comp key " << key << " with node key " << tRoot->key << endl;
	if(tRoot == nullptr)
	    return nullptr;
        if (tRoot->key == key)
	{
	    cout << key << " == " << tRoot->key << " key found" << endl;
	    return tRoot;
	}
	else if(key > tRoot->key)
	    return findNode(tRoot->right, key);
	else if(key < tRoot->key)
	    return findNode(tRoot->left, key);
	return nullptr;
    }
    void visual_rep(tNode * tRoot, int level)
    {
	if(tRoot != nullptr)
	{
	    visual_rep(tRoot->right, ++level);
	    cout << setw(10 * level) << "key: " << tRoot->key << " val: " << tRoot->val << endl;
	    visual_rep(tRoot->left, level++);
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
        else if ( newNode->key < tempRoot->key )
	    insert(tempRoot->left, newNode);
        else
            insert(tempRoot->right, newNode);	   
    }
    void deleteSingleChildNode(tNode * & node)
    {
        perror("deleteSingleChildNode not implemented\n");
    }
    void deleteDoubleChildNode(tNode * & node)
    {
        perror("deleteDoubleChildNode not implemented\n");
    }
    void deleteNoChildNode(tNode* & node)
    {
        perror("deleteNoChildNode not implemented\n");
    }
};
