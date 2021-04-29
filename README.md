# Snake-Game
## Game specifications

1.	This Game has regular wall and the Immune Wall(Gate).<br>
2.	Snake moves with the input direction key, but cannot move in the opposite direction of the moving direction. <br>
3.  If snake moves to tail direction game ends. Other failure condition is if snake touches its body or collides into the wall instead of gate.<br>
4.	Growth Item and Poison Item appear randomly in the map where there is no Snake Body or Wall. <br>
5.  If snake gets Growth Item the body length increases. Body length increases in heading direction. <br>
6.  If snake gets Poison Item the tail is reduced by 1 body length. If snake's length becomes 1, the game is over.<br>
7.  After some time passes, Growth Item and Poison Item disappear and appear at other location of the map.<br>
8.  Two pair of gates appears at a time. When Snake enters one gate, it comes out from another gate.<br>
9.  Once the snake passes through the gates, the position of the gates are changed.<br>
10. Score Board is displayed on the screen. <br>


**Main.cpp**: main file that contains codes of building a game menu.<br>
**Game.h**: header file for Game.cpp<br>
**Game.cpp**: file that contains codes of initializing and drawing the game window, drawing of snake’s body, printing a score at the bottom of the window, positioning a new fruit in the game window, positioning of the poison, setting game over situations.<br>
**Screen.h**: file that contains codes of additions to Screen.cpp file with the code of exception.<br>
**Screen.cpp**: file that contains codes of screen exception for each situation. Helps to change color.<br>
**Makefile**<br>

## Technologies
 Ncurses Library functions to complete a program that displays a two-dimensional array of Snake Map as a Game screen. Ncurses functions included in this game: <br>
•	Start and exit Ncurses mode <br>
•	Color attribute settings <br>
•	Screen update <br>
•	Create a new window (window data type) <br>
•	Window string output <br>
•	New window disappears <br>


## User Manual
1.	open terminal and go to the directory where the code is saved at.<br>
2.	In that directory run the command make. <br>
3.	It then will print out an executable command. Copy and run that command.<br>
4.	Enjoy playing the game. <br>


## How to compile program and run
1.Installing ncurses on Debian/Ubuntu Linux<br>
   sudo apt-get install libncurses5-dev libncursesw5-dev
