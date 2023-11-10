//
//  GameState.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//

#include "GameState.h"
#include "globals.h"

// ECE244 Student: add you code below
GameState:: GameState(){
    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    turn = true; // Red's turn is true, Yellow's turn is false;
    winner = Empty;
    for(int x = 0; x < (boardSize); x++){
        for(int y = 0; y < (boardSize); y++){
            gameBoard[x][y] = Empty;
        }
    }
}

int GameState::get_selectedRow() {
    return selectedRow;
}

int GameState::get_selectedColumn() {
    return selectedColumn;
}

void GameState::set_selectedRow(int value){
    if(value>= 0 && value<=(boardSize-1)){
        selectedRow = value;
    } else {
        return;
    }
}

void GameState::set_selectedColumn(int value){
    if(value>= 0 && value<=(boardSize-1)){
        selectedColumn = value;
    } else {
        return;
    }
}

bool GameState::get_moveValid(){
    return moveValid;
}

void GameState::set_moveValid(bool value){
    moveValid = value;
}

bool GameState::get_gameOver(){
    return gameOver;
}

void GameState::set_gameOver(bool value){
    gameOver = value;
}

bool GameState::get_turn(){
    return turn;
}

void GameState::set_turn(bool value){
    turn = value;
}

int GameState::get_winner(){
    return winner;
}

void GameState::set_winner(int value){
    winner = value;
}

int GameState::get_gameBoard(int row, int col){
  // Get the game board value at the board location at row and col
  // This method checks that row, col and value are in range/valid
  // and if not it returns Empty
  if((row>=0 && row<=(boardSize-1)) && (col>=0 && col<=(boardSize-1))){
    if((gameBoard[6-row][col] == R) || (gameBoard[6-row][col] == Y) || (gameBoard[6-row][col] == Empty)){
        return gameBoard[6-row][col];
    }
  }
  return Empty;
}

void GameState::set_gameBoard(int row, int col, int value){
  // Set the game board value at the board location at row and col to value
  // This method checks that row, col and value are in range/valid and if not it
  // just returns
  if((row>=0 && row<=(boardSize-1)) && (col>=0 && col<=(boardSize-1))){
    if((value == R) || (value == Y) || (value == Empty)){
        gameBoard[6-row][col]= value;
    }
  } else {
    return;
  }
}


