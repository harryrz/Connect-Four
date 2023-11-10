//
//  playMove.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "GameState.h"
#include "globals.h"
#include <iostream>
using namespace std;
void check_4_diag_upward(GameState& game_state, int row, int col);
void check_4_diag_downward(GameState& game_state, int row, int col);
void check_row(GameState& game_state, int row, int col);
void check_col(GameState& game_state, int row, int col);

// Function prototypes (if you need)

void playMove(GameState& game_state) {
  // Change turn if move is valid
  // Change gameOver
  // Change winner
  
  if(game_state.get_moveValid()){
    //Sets the gameboard
    if(game_state.get_turn()){
      game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), R);
    } else {
      game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), Y);
    }
    
    //Toggles the turn of game:
    game_state.set_turn(!game_state.get_turn()); //toggles the turn of the game
    //Check if game is over:


    //Row Check (Trying new):

    // Set a row to constant and check each column (from 0 to 5):
    // if game_state.getGameBoard(row, col) != game_state.getGameBoard(row, col+1)
    // which means the second one is disconnected with the first one,
    // set tot1 back to 0,
    // when encountering 0, also set to zero



    //Row Check:
    
    /*int tot1 = 0;
    for(int r = 0; r<boardSize; r++){
      tot1 = 0;
      for(int c = 0; c<boardSize; c++){
        if(game_state.get_gameBoard(r,c)!= 0){
          tot1 += game_state.get_gameBoard(r,c);
          //cout << "Tot1 is " << tot1;
          if (tot1 == 4){
            game_state.set_gameOver(true);
            game_state.set_winner(R);
          } else if (tot1 == -4){
            game_state.set_gameOver(true);
            game_state.set_winner(Y);
          }
        } else {
          tot1 = 0;
        }
      }
    }*/

    for(int rowrow = 0; rowrow < boardSize; rowrow++){
      check_row(game_state, rowrow, 0);
      check_row(game_state, rowrow, 1);
      check_row(game_state, rowrow, 2);
      check_row(game_state, rowrow, 3);
    }

    for(int colcol = 0; colcol < boardSize; colcol++){
      check_col(game_state, 0, colcol);
      check_col(game_state, 1, colcol);
      check_col(game_state, 2, colcol);
      check_col(game_state, 3, colcol);
    }
    

    //Column Check:

    /*int tot2 = 0;
    for(int s = 0; s<boardSize; s++){
      tot2 = 0;
      for(int t = 0; t<boardSize; t++){
        if(game_state.get_gameBoard(t,s)!= 0){
          tot2 += game_state.get_gameBoard(t,s);
          if (tot2 == 4){
            game_state.set_gameOver(true);
            game_state.set_winner(R);
          } else if (tot2 == -4){
            game_state.set_gameOver(true);
            game_state.set_winner(Y);
          }
        } else {
          tot2 = 0;
        }
      }
    }*/


    //Diagonal Check:

    /*for(int a = 0; int b = 0; a<boardSize; b<boardSize; a++; b++){
      int tot3 = 0;
        if(game_state.get_gameBoard(a,b)!= Empty){
          tot3 += game_state.get_gameBoard(a,b);
          if(tot3 == 4){
            game_state.set_gameOver(true);
            game_state.set_winner(R);
          } else if (tot3 == -4){
            game_state.set_gameOver(true);
            game_state.set_winner(Y);
          }
          }
          else {
            tot3 = 0;
          }
        }
    }*/

    int row = 0;
    while(row < 4){
      check_4_diag_upward(game_state, row, 0);
      check_4_diag_upward(game_state, row, 1);
      check_4_diag_upward(game_state, row, 2);
      check_4_diag_upward(game_state, row, 3);
      row++;
    }
    
    row = 6;
    while(row > 2){
      check_4_diag_downward(game_state, row, 0);
      check_4_diag_downward(game_state, row, 1);
      check_4_diag_downward(game_state, row, 2);
      check_4_diag_downward(game_state, row, 3);
      row--;
    }

  }
}

/*if((game_state.get_gameBoard(row, col)) == (game_state.get_gameBoard(row+1, col+1)) == (game_state.get_gameBoard(row+2, col+2)) == (game_state.get_gameBoard(row+3, col+3))){
        if(game_state.get_gameBoard(row, col) == R){
          game_state.set_gameOver(true);
          game_state.set_winner(R);
        } else {
          game_state.set_gameOver(true);
          game_state.set_winner(Y);
          }}*/

 void check_4_diag_upward(GameState& game_state, int row, int col){
    if (game_state.get_gameBoard(row, col) != 0){
      if(game_state.get_gameBoard(row, col) == (game_state.get_gameBoard(row+1, col+1))){
        if(game_state.get_gameBoard(row+1, col+1) == (game_state.get_gameBoard(row+2, col+2))){
          if(game_state.get_gameBoard(row+2, col+2) == (game_state.get_gameBoard(row+3, col+3))){
            if(game_state.get_gameBoard(row, col) == R){
          game_state.set_gameOver(true);
          game_state.set_winner(R);
        } else {
          game_state.set_gameOver(true);
          game_state.set_winner(Y);
          }
          }
        }
      }
    }
  }

  void check_4_diag_downward(GameState& game_state, int row, int col){
    if (game_state.get_gameBoard(row, col) != 0){
      if(game_state.get_gameBoard(row, col) == (game_state.get_gameBoard(row-1, col+1))){
        if(game_state.get_gameBoard(row-1, col+1) == (game_state.get_gameBoard(row-2, col+2))){
          if(game_state.get_gameBoard(row-2, col+2) == (game_state.get_gameBoard(row-3, col+3))){
            if(game_state.get_gameBoard(row, col) == R){
          game_state.set_gameOver(true);
          game_state.set_winner(R);
        } else {
          game_state.set_gameOver(true);
          game_state.set_winner(Y);
          }
          }
        }
      }
    }
  }

  void check_row(GameState& game_state, int row, int col){
    if (game_state.get_gameBoard(row, col) != 0){
      if(game_state.get_gameBoard(row, col) == (game_state.get_gameBoard(row, col+1))){
        if(game_state.get_gameBoard(row, col+1) == (game_state.get_gameBoard(row, col+2))){
          if(game_state.get_gameBoard(row, col+2) == (game_state.get_gameBoard(row, col+3))){
            if(game_state.get_gameBoard(row, col) == R){
          game_state.set_gameOver(true);
          game_state.set_winner(R);
        } else {
          game_state.set_gameOver(true);
          game_state.set_winner(Y);
          }
          }
        }
      }
    }
  }

  void check_col(GameState& game_state, int row, int col){
    if (game_state.get_gameBoard(row, col) != 0){
      if(game_state.get_gameBoard(row, col) == (game_state.get_gameBoard(row+1, col))){
        if(game_state.get_gameBoard(row+1, col) == (game_state.get_gameBoard(row+2, col))){
          if(game_state.get_gameBoard(row+2, col) == (game_state.get_gameBoard(row+3, col))){
            if(game_state.get_gameBoard(row, col) == R){
          game_state.set_gameOver(true);
          game_state.set_winner(R);
        } else {
          game_state.set_gameOver(true);
          game_state.set_winner(Y);
          }
          }
        }
      }
    }
  }