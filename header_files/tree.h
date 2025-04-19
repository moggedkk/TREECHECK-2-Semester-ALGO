#ifndef NODE_H
#define NODE_H
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
        void Insertion(int value);
        void Deletion(tree n);

        node* head;
};
#endif //NODE_H
