//
// Created by adrian on 4/19/25.
//
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "../header_files/file.h"


using namespace std;

file::file()
{
    cout << "Filename" << endl;
    string filename;
    cin >> filename;
    ifstream openedFile("../input/"+filename);
    string number;

    if (!openedFile.is_open())
    {
        cerr << "Error opening file " << filename << endl;
    }else
    {
        while (getline(openedFile, number))
        {
            this->numbers.push_back(int(number[0]));
            cout << number[0] << endl;
        }
    }
}