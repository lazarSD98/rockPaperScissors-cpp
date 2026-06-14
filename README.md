# rockPaperScissors

Rock Paper Scissors
A simple and interactive Rock Paper Scissors game for 2 players, built in C++.
About
Two players compete against each other in a classic game of Rock Paper Scissors. The game tracks wins and draws throughout the session and announces the final winner at the end. To keep things interesting, neither player can see what the other is typing on screen.
Requirements

Windows OS
Visual Studio with the C++ development workload installed

How to Play

Download or clone the project
Open rockPaperScissors.sln in Visual Studio
Build the project (Ctrl + Shift + B)
Run the project (F5)
Find a friend to play against

Controls
Each player types one of the following options when it is their turn:

rock
paper
scissors
exit — quits the game and shows the final result immediately

Input is hidden while typing, so neither player can see what the other has entered.
Game Flow

Players take turns entering their choice
The winner of each round is announced immediately
After each round the game asks if you want to play again
Once the session ends the overall winner is announced based on total wins

Notes

This project uses conio.h which is a Windows only library, so it will not compile on Linux or Mac without modifications


