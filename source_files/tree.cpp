//
// Created by adrian on 4/19/25.
//
#include <iostream>
#include <vector>
#include "../header_files/tree.h"


using namespace std;

tree::tree(vector<int> values)
{
    this->head = nullptr;
    this->values = values;

}

void tree::Insert(int value) {
    head = Insertion(value, head);
}

node* tree::Insertion(int value, node* node)
{
    if (node == nullptr)
    {
       return CreateNode(value);
    }
    if (value < node->key )
    {
        node->left = Insertion(value, node->left);

    }else if (value > node->key)
    {
        node->right = Insertion(value, node->right);
    }
    return node;

}

node* tree::CreateNode(int value)
{
    node* newNode = new node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void tree::FillTree()
{
    if (fillIndex == values.size())
    {
        return;
    }
    Insert(values[fillIndex]);
    fillIndex++;
    FillTree();
}
int tree::getBalanceFactor(node *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->right)-getHeight(node->left);
}

int tree::getHeight(node* node) {
    if (node == nullptr) {
        return -1;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;

}
bool tree::isAVL() {
    if (head == nullptr) {
        return true;
    }

    bool isAVL = true;
    printBalanceFactors(isAVL);
    return isAVL;
}

// Print the balance factor of each node and check AVL condition
void tree::printBalanceFactors(bool& isAVL) {
    printBalanceFactorsHelper(head, isAVL);
}

// Helper method for printing balance factors
void tree::printBalanceFactorsHelper(node* node, bool& isAVL)  {
    if (node == nullptr) {
        return;
    }

    // Process right subtree first, then left subtree, then root
    // This gives the same order as the reference output
    printBalanceFactorsHelper(node->right, isAVL);
    printBalanceFactorsHelper(node->left, isAVL);

    int balanceFactor = getBalanceFactor(node);

    std::cout << "bal(" << node->key << ") = " << balanceFactor;

    if (balanceFactor < -1 || balanceFactor > 1) {
        std::cout << " (AVL violation!)";
        isAVL = false;
    }

    std::cout << std::endl;
}
void tree::findMax() {
    node* current = head;
    if (current == nullptr) {
        return;
    }
    while (current->right != nullptr) {
        current = current->right;
    }
    std::cout << "Max: " << current->key << std::endl;
}
void tree::findMin() {
    node* current = head;
    if (current == nullptr) {
        return;
    }
    while (current->left != nullptr) {
        current = current->left;
    }
    std::cout << "Min: " << current->key << std::endl;
}
void tree::findAvgPublic() {

    double sum = 0;
    double count = 0;
    findAvgPrivate(sum, count, head);
    cout << "Average: " << sum/count << endl;
}

void tree::findAvgPrivate(double &sum, double &count, node* node) {
    if (node == nullptr) {
        return;
    }
    sum += node->key;
    count++;
    findAvgPrivate(sum, count, node->left);
    findAvgPrivate(sum, count, node->right);
}
void tree::searchValue(int value) {

    searchValuePrivate(value, head, path);
}
void tree::searchValuePrivate(int value, node* node, vector<int>path) {
    if (node == nullptr) {
        cout << value<<" not found "  << endl;
        return;
    }
    path.push_back(node->key);
    if (node->key == value) {
        cout <<value <<" found  " << endl;
        for (auto value: path) {
            cout << value << ", ";
        }
        cout << endl;
        return;
    }
    if (value < node->key) {
        searchValuePrivate(value, node->left, path);
    }else {
        searchValuePrivate(value, node->right, path);
    }
    //entfernt element beim rekursiven aufrufe die den value nicht finden
    path.pop_back();
}

void tree::searchSubTree(vector<int>subtree) {
    this->subtree = subtree;
    int index = 0;
    if (searchSubTreePrivate(index, head)) {
        cout <<"Subtree found! "<<endl;
    }else {
        cout <<"Subtree not found! "<<endl;
    }
    this->subtree.clear();
}
bool tree::searchSubTreePrivate(int &index, node* node) {
    cout << "At index: " << index << ", value: " << subtree[index] << endl;
    if (node == nullptr && index >= subtree.size()) {
        return true;
    }
    if (node == nullptr && index < subtree.size()) {
        return false;
    }
    if (node &&node->key == this->subtree[index]) {
        if (index + 1 >= subtree.size()) {
            return true; // done matching all elements
        }
        index++;
        if (this->subtree[index] < node->key ) {
            cout<<"going left and we found"<<this->subtree[index-1] <<endl;
            return searchSubTreePrivate(index, node->left);
        }else {
            cout<<"going right and we found"<<this->subtree[index-1] <<endl;
            return searchSubTreePrivate(index, node->right);
        }
        ;
    }else if (node->key > this->subtree[index]) {
        cout<<"going left"<<endl;
        cout<<node->key<<" is smaller than "<<this->subtree[index]<<endl;
        return searchSubTreePrivate(index, node->left);
    }else if (node->key < this->subtree[index]) {
        cout<<"going right"<<endl;
        return searchSubTreePrivate(index, node->right);
    }

}






