#include <iostream>
#include "header_files/tree.h"
#include "header_files/file.h"

using namespace std;
int main() {
    cout << "#################################" << endl;
    cout << "########## Binary TREE ##########" << endl;
    cout << "#################################\n" << endl;
    tree binarytree;
    int input;
    do
    {
        cout << "1 Read Tree | 2 Search Tree | 3 Exit" << endl;
        cin >> input;
        switch (input)
        {
        case 1 :{
            file f;
            break;
        }
        case 2:
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
