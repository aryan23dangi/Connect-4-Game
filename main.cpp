
#include <iostream>
#include <ctime>

using namespace std;

void initialMessage() {
    cout << "          Welcome to Connect4          " << endl;
    cout << "  The goal of Connect4 is to be the first  " << endl;
    cout << "player to place four checks in a row, either" << endl;
    cout << "    horizontally, vertically or diagonally    " << endl;
    cout << endl;
    cout << endl;
}

void print_grid(char gameBoard[6][7]) {
    for (int i = 0; i < 7; i++) {
        cout << "  " << (i + 1) << " ";
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cout << "| " << gameBoard[i][j] << " ";
        }
        cout << "|" << endl;
        for (int j = 0; j < 7; j++) {
            cout << "+---";
        }
        cout << "+" << endl;
    }
}

void empty_board(char gameBoard[6][7]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}

void put_value_in_grid(char gameBoard[6][7], int current_col, int current_player) {
    bool check = false;
    for (int i = 5; i >= 0; i--) {
        if (gameBoard[i][current_col] == ' ') {
            if (current_player == 1) {
                gameBoard[i][current_col] = 'X';
                check = true;
                break;
            } else {
                gameBoard[i][current_col] = 'O';
                check = true;
                break;
            }
        }
    }
    if (!check) {
        cout << "Move Not Available, You Lost Your Turn" << endl;
        cout << endl;
    }
}


bool check_game_status(char gameBoard[6][7], int random_player) {
    char check_value;
    if (random_player == 1) {
        check_value = 'X';
    } else {
        check_value = 'O';
    }
    bool win = false;
    for (int i = 5; i >= 0; --i) {
        for (int j = 6; j >= 0; --j) {
            if (!((i - 1) < 0) && !((i - 2) < 0) && !((i - 3) < 0)) {
                if (!((j - 1) < 0) && !((j - 2) < 0) && !((j - 3) < 0)) {
                    if (gameBoard[i][j] == check_value &&
                        gameBoard[i - 1][j - 1] == check_value &&
                        gameBoard[i - 2][j - 2] == check_value &&
                        gameBoard[i - 3][j - 3] == check_value) {
                        win = true;
                    }
                }
            }
            if (!((j - 1) < 0) && !((j - 2) < 0) && !((j - 3) < 0)) {
                if (gameBoard[i][j] == check_value &&
                    gameBoard[i][j - 1] == check_value &&
                    gameBoard[i][j - 2] == check_value &&
                    gameBoard[i][j - 3] == check_value) {
                    win = true;
                }
            }
            if (!((i - 1) < 0) && !((i - 2) < 0) && !((i - 3) < 0)) {
                if (gameBoard[i][j] == check_value &&
                    gameBoard[i - 1][j] == check_value &&
                    gameBoard[i - 2][j] == check_value &&
                    gameBoard[i - 3][j] == check_value) {
                    win = true;
                }
            }
            if (!((i - 1) < 0) && !((i - 2) < 0) && !((i - 3) < 0)) {
                if (!((j + 1) > 6) && !((j + 2) > 6) && !((j + 3) > 6)) {
                    if (gameBoard[i][j] == check_value &&
                        gameBoard[i - 1][j + 1] == check_value &&
                        gameBoard[i - 2][j + 2] == check_value &&
                        gameBoard[i - 3][j + 3] == check_value) {
                        win = true;
                    }
                }
            }
            if (!((j + 1) > 6) && !((j + 2) > 6) && !((j + 3) > 6)) {
                if (gameBoard[i][j] == check_value &&
                    gameBoard[i][j + 1] == check_value &&
                    gameBoard[i][j + 2] == check_value &&
                    gameBoard[i][j + 3] == check_value) {
                    win = true;
                }
            }
        }
    }
    if (random_player == 1 && win) {
        cout << "Player #1 was a winner." << endl;
    }
    if (random_player == 2 && win) {
        cout << "Player #2 was a winner." << endl;
    }
    return win;

}

bool game_over_check(char gameBoard[6][7]) {
    bool game_over = true;
    for (int j = 0; j <= 6; j++) {
        if (gameBoard[0][j] == ' ') {
            game_over = false;
        }
    }
    if (game_over) {
        cout << "The Game Ended In A Tie" << endl;
        cout << endl;
    }
    return game_over;
}


int main() {
    char gameBoard[6][7] = {" ", " "};
    int current_col;

    initialMessage();

    //select random player logic
    srand(time(0));
    int random_player = (rand() % 2) + 1;
    cout << " Player #" << random_player << " was selected to go first" << endl;
    cout << endl;
    //empty board (delete garbage values)
    empty_board(gameBoard);
    print_grid(gameBoard);

    //this flag will tell while loop when to stop
    //flag is 0 means game is over
    char restart = 'Y';
    bool flag = true;
    int count_player1 = 0;
    int count_player2 = 0;
    int count_tie = 0;
    while (restart == 'Y') {
        empty_board(gameBoard);
        while (flag) {
            if (random_player == 1) {
                cout << "Player #1's Turn (X) : Enter your Move :";
            } else {
                cout << "Player #2's Turn (O) : Enter your Move :";
            }
            cin >> current_col;
            while (current_col > 7 || current_col < 1) {
                if (current_col > 7 || current_col < 1) {
                    cout << "Illegal Position,Please Reenter" << endl;
                    if (random_player == 1) {
                        cout << "Player #2's Turn (O) : Enter your Move :";
                        random_player = 2;
                    } else {
                        cout << "Player #1's Turn (X) : Enter your Move :";
                        random_player = 1;
                    }
                    cin >> current_col;
                }
            }

            current_col = current_col - 1;
            put_value_in_grid(gameBoard, current_col, random_player);
            print_grid(gameBoard);
            bool game_status = check_game_status(gameBoard, random_player);
            bool game_over = game_over_check(gameBoard);

            if (game_status == 1 || game_over == 1) {
                if (game_over == 0) {
                    if (random_player == 1) {
                        count_player1++;
                    } else {
                        count_player2++;
                    }
                } else {
                    count_tie++;
                }
                break;
            }
            //change the player
            if (random_player == 1) {
                random_player = 2;
            } else {
                random_player = 1;
            }
        }

        cout << "Would you like to play again [Y/N]" << endl;
        cin >> restart;
        restart = toupper(restart);
    }
    cout << "player 1 win :" << count_player1 << endl;
    cout << "player 2 win :" << count_player2 << endl;
    cout << "tie :" << count_tie << endl;
}
