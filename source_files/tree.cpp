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
