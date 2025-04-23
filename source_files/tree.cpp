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




