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

        tree(vector<int> values);
        node* CreateNode(int value);
        void Insert(int value);
        void FillTree();
        bool isAVL();
        int getHeight(node* node);
        int getBalanceFactor(node* node);
        node* getHead(){return head;};
        void findMax();
        void findMin();
        void findAvgPublic();
        void searchValue(int value);
        void searchSubTree(vector<int> subtree);
        ~tree() = default;
        


    private:
        void findAvgPrivate(double &sum, double &count, node* node);
        void printBalanceFactorsHelper(node* node, bool &isAVL);
        void printBalanceFactors(bool &isAVL);
        void searchValuePrivate(int value, node* node, vector<int> path);
        bool searchSubTreePrivate(int &index, node* node);

        node* head;
        int fillIndex = 0;
        vector<int> values;
        vector<int> path;
        vector<int> subtree;
        node* Insertion(int value, node* node);
};
#endif //NODE_H
