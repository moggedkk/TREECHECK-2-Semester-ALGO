#include <iostream>
#include <memory>
#include "header_files/tree.h"
#include "header_files/file.h"
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "#################################" << endl;
    cout << "########## Binary TREE ##########" << endl;
    cout << "#################################\n" << endl;
    int input;
    unique_ptr<tree> binaryTree = nullptr;
    do
    {
        cout << "1 Read Tree | 2 Search Tree | 3 Exit" << endl;
        cin >> input;
        switch (input)
        {
        case 1 :{
                file f;
                binaryTree = make_unique<tree>(f.numbers);
                binaryTree->FillTree();
                cout<<binaryTree->getHead()->key <<endl;

                cout<< binaryTree->getHeight(binaryTree->getHead()) <<endl;
                binaryTree->isAVL();
                binaryTree->findMax();
                binaryTree->findMin();
                binaryTree->findAvgPublic();
            break;
        }
        case 2:
            if (!binaryTree) {
                cout << "No Tree" << endl;
                break;
            }
            cout<<"1 Search Value | 2 Search Subtree" << endl;
            int valueOrTree;
            cin >> valueOrTree;
            switch (valueOrTree) {

                case 1 : {
                    int value;
                    cin >> value;
                    binaryTree->searchValue(value);
                    break;
                case 2:

                        cout << "Enter Subtree" << endl;
                        vector<int> subtree;
                        string line;
                        cin.ignore(); // Flush newline from previous cin
                        getline(cin, line);
                        istringstream iss(line);
                        int num;
                        while (iss >> num) {
                            subtree.push_back(num);
                        }
                        binaryTree->searchSubTree(subtree);
                        break;

                    }
            }
            break;
        case 3:
            input = 0;
            break;
        default:
            break;
        }
    }while (input != 0);
    return 0;
}


