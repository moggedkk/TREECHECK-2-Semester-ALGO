//
// Created by adrian on 4/19/25.
//
#include <stdio.h>
#include <iostream>
#include "../header_files/tree.h"

using namespace std;

tree::tree()
{
    this->head = NULL;
}


void tree::Insertion(int value)
{
    node* newNode = new node();
    newNode->key = value;
    newNode->left = head;
    newNode->right = NULL;
}
