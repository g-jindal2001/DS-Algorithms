#include <iostream>
#include <vector>

using namespace std;

char player = 'x', opponent = 'o';

bool isMoveLeft(char board[3][3]) // function to check if there are remaining moves on the board
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '_')
            {
                return true;
            }
        }
    }

    return false;
}

int evaluate(char board[3][3]) // function to return the score of current board at the time
{
    for (int row = 0; row < 3; row++) // checking all the rows
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
        {
            if (board[row][0] == player)
            {
                return +10;
            }

            if (board[row][0] == opponent)
            {
                return -10;
            }
        }
    }

    for (int column = 0; column < 3; column++) // checking all the columns
    {
        if (board[0][column] == board[1][column] && board[1][column] == board[2][column])
        {
            if (board[0][column] == player)
            {
                return +10;
            }

            if (board[0][column] == opponent)
            {
                return -10;
            }
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) // checking for diagonals
    {
        if (board[0][0] == player)
        {
            return +10;
        }

        if (board[0][0] == opponent)
        {
            return -10;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) // checking for diagonals
    {
        if (board[0][2] == player)
        {
            return +10;
        }

        if (board[0][2] == opponent)
        {
            return -10;
        }
    }

    return 0;
}

int minimax(char board[3][3], int depth, bool isMax) // considers all possible ways the ai can play and returns the score
{
    int score = evaluate(board);

    // cout << "Score: " << score << " Depth: " << depth << "\n";

    if (score == 10 || score == -10) // if either players has won
    {
        return score;
    }

    if (!isMoveLeft(board)) // if no more moves left on board
    {
        return 0;
    }

    if (isMax) // if it is the maximizer's move (i.e the player)
    {
        int best = -INT_MAX;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = player; // make the move of player

                    int current_score = minimax(board, depth + 1, !isMax); // get the score for that move;

                    best = max(best, current_score); // take the max out of it

                    board[i][j] = '_'; // undo the move to restore the board to its previous state
                }
            }
        }

        // cout << "Score: " << best << " Depth: " << depth << "\n";

        return best;
    }

    else // if it is the minimizer's move (i.e the opponent)
    {
        int best = INT_MAX;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = opponent; // make the move

                    int current_score = minimax(board, depth + 1, !isMax); // get the score for that move;

                    best = min(best, current_score); // take the max out of it

                    board[i][j] = '_'; // undo the move to restore the board to its previous state
                }
            }
        }

        // cout << "Score: " << score << " Depth: " << depth << "\n";

        return best;
    }
}

vector<int> bestMove(char board[3][3]) // will return a vector containing 2 elements (with i and jth position of the move)
{
    vector<int> nextMove;
    int best_score = -INT_MAX;
    int bestRow = -1;
    int bestColumn = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '_')
            {
                board[i][j] == player; // make the move

                int score = minimax(board, 0, false);

                cout << score;

                board[i][j] == '_'; // undo the move

                if (score > best_score)
                {
                    best_score = score;
                    bestRow = i;
                    bestColumn = j;
                }
            }
        }
    }

    nextMove.push_back(bestRow);
    nextMove.push_back(bestColumn);

    return nextMove;
}

int main()
{
    char board[3][3] = {
        {'x', 'o', 'x'},
        {'o', 'o', 'x'},
        {'_', '_', '_'},
    };

    vector<int> nextMove = bestMove(board);

    cout << "The optimal move is at " << nextMove[0] << "th row and " << nextMove[1] << "th column";

    // cout << evaluate(board);

    return 0;
}