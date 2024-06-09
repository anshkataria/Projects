#include <iostream>
using namespace std;
char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string name1;
string name2;
int row;
int column;
char symbol = 'X';
void getPlayerNames()
{
    cout << "Enter the name of First Player: ";
    getline(cin, name1);
    cout << endl;
    cout << "Enter the name of Second Player: ";
    getline(cin, name2);
    cout << endl;
    cout << name1 << " is First Player so he/she will play first." << endl;
    cout << name2 << " is Second Player so he/she will play second." << endl;
    cout << endl;
}
void printGrid()
{
    cout << "     |     |     " << endl;
    cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;
    cout << "     |     |     " << endl;
}
int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] || grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
        {
            return 1;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] || grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != 'X' && grid[i][j] != 'O')
            {
                return 0;
            }
        }
    }
    return -1;
}
void working()
{
    int digit;
    if (symbol == 'X')
    {
        cout << name1 << " Please Enter the Number where you want to put your symbol  (X): ";
        cin >> digit;
    }
    else if (symbol == 'O')
    {
        cout << name2 << " Please Enter the Number where you want to put your symbol  (O): ";
        cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else
    {
        cout << "Invalid!!" << endl;
        return;
    }

    if (symbol == 'X' && grid[row][column] != 'X' && grid[row][column] != 'O')
    {
        grid[row][column] = 'X';
        symbol = 'O';
    }
    else if (symbol == 'O' && grid[row][column] != 'X' && grid[row][column] != 'O')
    {
        grid[row][column] = 'O';
        symbol = 'X';
    }
    else
    {
        cout << "There is no empty space." << endl;
        working();
    }
}
int main()

{
    getPlayerNames();
    bool gameOver = false;
    int result;

    while (!gameOver)
    {
        printGrid();
        working();
        result = checkWin();
        if (result == 1)
        {
            gameOver = true;
        }
        else if (result == -1)
        {
            gameOver = false;
        }
    }
    printGrid();
    if (symbol == 'O')
    {
        cout << name1 << " Wins!!" << endl;
    }
    else if (symbol == 'X')
    {
        cout << name2 << " Wins!!" << endl;
    }
    else
    {
        cout << "The game is a Draw." << endl;
    }
    return 0;
}