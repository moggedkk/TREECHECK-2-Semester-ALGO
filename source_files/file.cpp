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
            this->numbers.push_back(stoi(number));
            cout << number[0] << endl;
        }
        DeleteDuplicates();
    }
}

void file::DeleteDuplicates()
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); )
        {
            if (numbers[i] == numbers[j])
            {
                int duplicate = numbers[j];
                numbers.erase(numbers.begin() + j);
                cout << "Delete duplicate number: " << duplicate << endl;
            }
            else
            {
                ++j;
            }
        }
    }
}