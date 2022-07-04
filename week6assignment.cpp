#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

//declare constants for the number of rows and number of columns
const int numrows = 10;
const int numcol = 5;
const int numcolbig = 6;

//function to read and store data into arrays
void GetBowlingData(string txtfile, string names[numrows], int scores[numrows][numcol])
{
    //declare and open file
    ifstream inFile;
    inFile.open(txtfile);
    //decalare new array to pool all data initially into
    string totalarray[numrows][numcolbig];
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < numcolbig; c++)
        {
             inFile >> totalarray[r][c];   
        }
    }
    //transfer the first column of data from the data pool array so that it only takes the names
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 1; c++)
        {
            names[r] = totalarray[r][c];   
        }
    }
    //transfer the everything except the first column of data (only the scores)
    for (int r = 0; r < numrows; r++)
    {
        for (int c = 1; c < numcolbig; c++)
        {
            scores[r][c-1] = stoi(totalarray[r][c]);   
        }
    }
}

//function to calculate the average for each player
void GetAverageScore(int scores[numrows][numcol], int avg[numrows])
{
    //double loop to parse and add scores for each row (player) together
    for (int r = 0; r < numrows; r++)
    {
        int total = 0;
        for (int c = 0; c < numcol; c++)
        {
            total = total + scores[r][c];  
        }
        avg[r] = total / numcol;
    }
}

//function to print arrays/data to screen
void PrettyPrintResults(string names[numrows], int scores[numrows][numcol], int avg[numrows])
{
    //loop to print each players data in mini segments together
    for (int r = 0; r < numrows; r++)
    {
        cout << "Player name: " << names[r] << endl;
        cout << "Scores: ";
        for (int c = 0; c < numcol; c++)
        {
            cout << scores[r][c] << " ";
        }
        cout << endl;
        cout << "Average score: " << avg[r] << endl;
        cout << " " << endl;
    }
}


int main()
{
    //declare arrays
    string n_array[numrows];
    int s_array[numrows][numcol];
    int averg[numrows];
    //call functions
    GetBowlingData("BowlingScores.txt", n_array, s_array);
    GetAverageScore(s_array, averg);
    PrettyPrintResults(n_array, s_array, averg);
    return 0;
}