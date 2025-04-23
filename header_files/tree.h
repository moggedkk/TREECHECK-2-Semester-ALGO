#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};
class tree
{
    public:
        tree();
        tree(vector<int> values);
        node* CreateNode(int value);
        void Insert(int value);
        void Deletion(tree n);
        void FillTree();
    private:
        node* head;
        int fillIndex = 0;
        vector<int> values;
        node* Insertion(int value, node* node);
};
#endif //NODE_H
