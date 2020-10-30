// TikTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<string.h>

//global vars
bool game = true;
char player1Input;
char Player2Input;
std::string board[3][3];
int playerTurn = 1;
int cord;

//blank board with cords

void cordBoard()
{
    std::cout << " 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 ";
    std::cout << '\n';
}

//sets board to blanks before the game
void setBoard()
{
    for (int r = 0; r < 3;r++)
        for (int c = 0; c < 3; c++)
        {
            board[r][c] = '---';
        }
    std::cout << '\n';
}

//prints the current state of the board
void printBoard()
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
        {
            std::cout << board[r][c];
            if (c < 2)
                std::cout << '|';
            else
                std::cout << '\n';
        }
        std::cout << '\n';
}

//sets the marker on board
void setMarker(int index, std::string str)
{
    if (index - 1 <= 2)
        board[0][index - 1] = str;
    else if (index - 1 <= 5)
            board[1][index - 4] = str;
    else
        board[2][index - 7] = str;
    
}

//determines if player is 'O'
bool isO(std::string input)
{
    if (input == "O")
        return true;
    return false;
}

void switchTurn(int num)
{
    if (num == 1)
        playerTurn = 2;
    else
        playerTurn = 1;
}

bool checkWin(std::string input)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[1][i] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[2][i] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][1] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][2] == input)
        {
            count++;
            if (count == 3)
                return true;
        }
    }
    count = 0;
    if (board[0][0] == input)
        count++;
    if (board[1][1] == input)
        count++;
    if (board[2][2] == input)
        count++;
    if (count == 3)
        return true;
    count = 0;
    if (board[2][0] == input)
        count++;
    if (board[1][1] == input)
        count++;
    if (board[0][2] == input)
        count++;
    if (count == 3)
        return true;
    
    return false;
}

int main()
{
    bool game = true;
    std::string player1Input;
    std::string Player2Input;
    std::cout << "TIK TAC TOE \n";
    std::cout << "Player 1 select X or O\n";
    std::cin >> player1Input;
    if (isO(player1Input))
    {
        Player2Input = 'X';
    }
    else
    {
        player1Input = 'X';
        Player2Input = 'O';
    }

    std::cout << "To play enter a number according to the board\n";
    cordBoard();
    setBoard();
    while (game)
    {
        if (playerTurn == 1)
        {
            std::cout << "Player 1 enter a cordinate\n";
            std::cin >> cord;
            setMarker(cord, player1Input);
            printBoard();
            switchTurn(1);
            if (checkWin(player1Input))
            {
                std::cout << "Player " << playerTurn << " wins!";
                game = false;
            }
        }
        else
        {
            std::cout << "Player 2 enter a cordinate\n";
            std::cin >> cord;
            setMarker(cord, Player2Input);
            printBoard();
            switchTurn(2);
            if (checkWin(Player2Input))
            {
                std::cout << "Player " << playerTurn << " wins!";
                game = false;
            }
        }
    }
}