//
//  connectfour.cpp
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
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
using namespace std;

#include "GameState.h"
#include "globals.h"

// Function prototypes

// The main function
int main() {
  /**********************************************************************************/
  /* Create three initialized game state objects in an array */
  /**********************************************************************************/
  const int numOfRounds = 3;
  GameState game_state[numOfRounds];
  int redWonCount = 0;
  int yellowWonCount = 0;

  // Read one integer from the user that represents the column
  // the player would like to place their piece (R or Y) in
  // You can assume there will be no formatting errors in the input

  int col;
  int round = 0;
  while(round < 3){
    cout << "Game " << round+1 << endl;
    while (!game_state[round].get_gameOver()) {
    cout << "Enter column to place piece: ";
    cin >> col;
 
    if( cin.eof() ) {
      cerr << endl << "Game ended by user." << endl ;
      exit( 0 ) ;
    }
    if( cin.fail() ) {
      cin.clear() ;
      cin.ignore( 1000, '\n' ) ;
      col = -1 ; // giving col invalid value so it will be handled as invalid input below
    }
  
    // Check validity of input and if not valid, handle accordingly
    

    //handle failing input case:
    while(col == -1){
      game_state[round].set_moveValid(false);
      cout << col;
      cout << "Invalid column!" << endl;
      cout << "Enter column to place piece: ";
      cin >> col;
      if( cin.fail() ) {
      cin.clear() ;
      cin.ignore( 1000, '\n' ) ;
      col = -1 ; // giving col invalid value so it will be handled as invalid input below
    }
    }

    //handle full column case:
    int mut_col = col;
    while(mut_col >= 0 && mut_col <= 6){
      if(game_state[round].get_gameBoard(6, col) == Empty){
        game_state[round].set_moveValid(true);
        cout << "column chosen: " << col << endl;
        mut_col = -1;
      } else {
        game_state[round].set_moveValid(false);
        cout << "Invalid column!" << endl;
        cout << "Enter column to place piece: ";
        cin >> col;
        mut_col = col;
      }
    }


    // The coordinates are valid; set the selectedRow and selectedColumn
    // members of the game state to the read values
    // Note that the corresponding mutators of GameState must be first
    // implemented before this works

    if(game_state[round].get_moveValid()){
      int row_check = 6;
      while((row_check >= 0) && (game_state[round].get_gameBoard(row_check, col) == Empty)){
        row_check--;
      }
      game_state[round].set_selectedRow(row_check+1);
      game_state[round].set_selectedColumn(col);
    }
    
    // Call playMove
    playMove(game_state[round]);

    // Print the GameState object, as prescribed in the handout
    cout << endl;
    for(int i = 6; i >= 0; i--){
      for(int j = 0; j < 7; j++){
        if(game_state[round].get_gameBoard(i,j) == Empty){
          cout << "_";
        } else if(game_state[round].get_gameBoard(i,j) == R){
          cout << "R";
        } else {
          cout << "Y";
        }
      }
      cout<< endl;
    }

    // Check if a player won this round and if so handle accordingly
    if(game_state[round].get_gameOver()){
      if(game_state[round].get_winner() == R){
        cout << "R won this round!" << endl;
        redWonCount ++;
        //cout << redWonCount <<endl;
      } else {
        cout << "Y won this round!" << endl;
        yellowWonCount ++;
        //cout << yellowWonCount << endl;
      }
    }

    // Check if a player won this match and if so handle accordingly
    
  }
    if(redWonCount == 2){
      cout << "R won the match!" << endl;
      break;
    } else if(yellowWonCount == 2) {
      cout << "Y won the match!" << endl;
      break;
    }

    round++;
  }
  
  
  return 0;
}
  

//Problems yet to solve:
//1. Exit game after the match is done?
//2. Alogorithm for checking diagonal entries? (solved???)
//3. Handling invalid (out of range inputs)?
