#include <iostream>

using namespace std;
int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char playerX = 'X';
    const char playerO = 'O';
    char currentPlayer = playerX;
    int row = -1;
    int column = -1;
    char Winner = ' ';


    for (int i = 0; i < 9; i++)
    {
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (Winner != ' ')
            break;

        cout << " The current player is: " << currentPlayer << endl;
        while (true)
        {
            cout << " Enter the number of Row and Column for you shot (0-2)(0-2): \n";
            cin >> row >> column;

            if ((row < 0 || row>2) || (column < 0 || column>2))
            {
                cout << "\n\t!!Invalid Input!!" << endl;
            }
            else if (board[row][column] != ' ')
            {
                cout << "\n\t!!Tile is full!!" << endl;
            }
            else
            {
                break;
            }
            row = -1;
            column = -1;

            cin.clear();
            cin.ignore(10000, '\n');

        }


        board[row][column] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;


        //Winners
        //Winner in a row
        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] != ' ' && (board[r][0] == board[r][1]) && (board[r][1] == board[r][2]))
            {
                Winner = board[r][0];
                break;
            }
        }
        //Winner in a column
        for (int c = 0; c < 3; c++)
        {
            if (board[0][c] != ' ' && (board[0][c] == board[1][c]) && (board[1][c] == board[2][c]))
            {
                Winner = board[0][c];
                break;
            }
        }
        //Winner in diagonal
        if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        {
            Winner = board[0][0];
        }
        else if (board[0][2] != ' ' && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
        {
            Winner = board[0][2];
        }
    }

    if (Winner != ' ')
    {
        cout << "\n\tThe " << Winner << " is the Winner" << endl;
    }
    else
    {
        cout << "\n\t!!It's a Draw!!";
    }
    return 0;
}