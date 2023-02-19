#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void read_data()
{
    int programmerArray[5][5];
    int departmentArray[5][5];

    ofstream inputFile;
    inputFile.open("inputFile.txt");
    if(inputFile.is_open())
    {
        for(int i=0; i<=4; i++)
        {
            for(int j=0; j<=4; j++)
            {
                cin >> departmentArray[j][i];
            }
        }

        for(int i=0; i<=4; i++)
        {
            for(int j=0; j<=4; j++)
            {
                cin >> programmerArray[j+5][i];
            }
        }

//----------------------------------------
        for(int a = 0; a < 3; a++)
        {
            for(int b = 0; b < 3; b++)
            {
                cout << departmentArray[a][b] << " ";
            }
            cout << endl;
        }
//--------------------------------------
        inputFile.close();
    }
    else
    {   
        cout << "Unable to open file" << endl;
    }
}

int main()
{
    read_data();
    return 0;
}