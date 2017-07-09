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
    {
        makeEmpty();
    }
    void makeEmpty()
    {
        deleteTree(root);
	root = nullptr;
    }
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
	tNode * temp = nullptr;
	tNode * foundNodePar;
	tNode * foundNode;

        foundNode = findNode(root, key);
	foundNodePar = findParentOfNode(root, temp, key);

	if(foundNode == nullptr)
	{
	    fprintf(stderr, "node not found with key %d\n", key);
	    exit(-1);
	}
	// node has one child
	if( (foundNode->right == nullptr && foundNode->left != nullptr)
	|| ( foundNode->right != nullptr && foundNode->left == nullptr))
	    deleteSingleChildNode(foundNode, foundNodePar);
	// node has two children
	else if(foundNode->right != nullptr && foundNode->left != nullptr)
	    deleteDoubleChildNode(foundNode, foundNodePar);
	// node has no children
	else
	    deleteNoChildNode(foundNode, foundNodePar);
	--numNodes;
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
    void largestChildOfLeftTree()
    {
        cout << "the largest child of the left subtree is "
	     << getLargestChild(root->left)->key << endl;
    }
  private:
    tNode * root;
    int numNodes;
    tNode * findNode(tNode * tRoot, int key)
    {
	if(tRoot == nullptr)
	    return nullptr;
        if (tRoot->key == key)
	{
	    return tRoot;
	}
	else if(key > tRoot->key)
	    return findNode(tRoot->right, key);
	else if(key < tRoot->key)
	    return findNode(tRoot->left, key);
	return nullptr;
    }
    tNode * findParentOfNode(tNode * tRoot, tNode * & par, int key)
    {
	if(tRoot == nullptr)
	    return nullptr;
        if (tRoot->key == key)
	    return par;
	par = tRoot;
	if(key > tRoot->key)
	    return findParentOfNode(tRoot->right, par, key);
	else if(key < tRoot->key)
	    return findParentOfNode(tRoot->left, par, key);
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
    void deleteTree(tNode * tempRoot)
    {
        if( tempRoot != nullptr)
	{
	    deleteTree(tempRoot->right);
	    deleteTree(tempRoot->left);
	    deleteItem(tempRoot->key);
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
    void deleteSingleChildNode(tNode * & node, tNode * & nodePar)
    {
	tNode * grandChild;
	if(node->right != nullptr)
	    grandChild = node->right;
	else
	    grandChild = node->left;

        if(nodePar != nullptr)
	{
	    if(nodePar->right == nullptr)
		nodePar->right = grandChild;
	    else
		nodePar->left = grandChild;
	}
	else
	{
	    root = grandChild;
	    cout << "setting root to " << root << endl;
	}
	delete node;
    }
    void deleteDoubleChildNode(tNode * & node, tNode * & nodePar)
    {
	tNode * temp = nullptr;
        tNode * replacementNode = getLargestChild(node->left);
	tNode * replacementNodePar = findParentOfNode(root, temp, replacementNode->key);


	// set replamentNodePar-> replacementNode to nullptr
	
	if(replacementNodePar != nullptr)
	{
	    if(replacementNodePar->right != nullptr)
	    {
	        if(replacementNodePar->right == replacementNode)
	            replacementNodePar->right = nullptr;
	    }
	    if(replacementNodePar->left != nullptr)
	    {
	        if(replacementNodePar->right == replacementNode)
	            replacementNodePar->right = nullptr;
	    }
	}

        // set replacementNode->right and ->left to be node->right and ->left
	node->key = replacementNode->key;
	node->val = replacementNode->val;

	delete(replacementNode);

    }
    void deleteNoChildNode(tNode* & node, tNode * nodePar)
    {
	if(nodePar != nullptr)
	{
	    if( nodePar->right != nullptr )
	        nodePar->right = nullptr;
	    else
	        nodePar->left = nullptr;
	}
	delete node;
    }
    tNode * getLargestChild(tNode * tRoot)
    {
        if(tRoot->right != nullptr)
	    return getLargestChild(tRoot->right);
        else
	    return tRoot;	
    }
};
