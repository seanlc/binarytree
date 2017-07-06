#include <string>

using namespace std;

class BinaryTree
{
  public:
    BinaryTree();
    ~BinaryTree();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    int getLength();
    int getItem(int key);
    void putItem(int key);
    void deleteItem(int key);
    void print();
  private:
    struct tNode
    {
        int key;
	string val;
	tNode * right;
	tNode * left;
    };
    tNode * root;
};
