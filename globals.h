//
//  globals.h
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
//  ECE244 Student: Do NOT modify this file

#ifndef globals_h
#define globals_h

// Some basic definitions for the game
#define R 1
#define Y -1
#define Empty 0

#define boardSize 7

// Forward declaration of the class GameState (defined in GameState.h)
class GameState;

// The prototype of the playMove function
void playMove(GameState&);

#endif /* globals_h */
