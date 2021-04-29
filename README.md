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

## Technologies
1. **Ncurses Library**: displaying Snake Map on the game screen . Ncurses functions included in this game: <br>
                        •	Start and exit Ncurses mode <br>
                        •	Color attribute settings <br>
                        •	Screen update <br>
                        •	Create a new window (window data type) <br>
                        •	Window string output <br>
                        •	New window disappears <br>
2. **unistd header**: delaying time when necessary

## Code 

**Main.cpp**: main file that contains codes of building a game menu.<br>
**Game.h**: header file for Game.cpp<br>
**Game.cpp**: file that contains codes of initializing and drawing the game window, drawing of snake’s body, printing a score at the bottom of the window, positioning a new fruit in the game window, positioning of the poison, setting game over situations.<br>
**Screen.h**: file that contains codes of additions to Screen.cpp file with the code of exception.<br>
**Screen.cpp**: file that contains codes of screen exception for each situation. Helps to change color.<br>
**Makefile**<br>

## Functions and classes used 
**main.cpp**<br>
•	_IsUserReady()_: waits for confirmation from the user whether they want to play the game or not. If ‘y’ calls the playGame() function to start the game.<br>
•	_AskUserToPlay_(): after the game is over, it asks the user whether to continue the game or not and returns the answer.<br>
•	_ClearCentere_(): clears the page and writes the message in the center<br>
•	_UserInput_(): takes input from the user.<br>
**Game.cpp**<br>
•	_PlayGame_():where the game is played and decides if it is game over.<br>
•	_GetRandom_(): produces random numbers. <br>
•	_InitGameWindow_():initializes the game window<br>
•	_DrawWindow_(): draws the wall and gates.<br>
•	_DrawSnake_(): draws the body of snake<br>
•	_PrintScore_(): updates the value of score<br>
•	_PositionFruit_(): position the fruit item in random places inside the wall<br>
•	_PositionPoison_():position the poison item in random places inside the wall<br>
•	_FatalCollision_(): handles collision of the snake with the wall or its self<br>
•	_GetsFruit_(): checks if snake ate the fruit item<br>
•	_GetsPoison_(): checks if snake ate poison item<br>
•	_MoveSnake_(): moves the body of the snake in the desired direction<br>
**Screen.cpp**<br>
•	_text_attr_(short attr):in charge of changing the color of the characters.<br>


## User Manual
1.	open terminal and go to the directory where the code is saved at.<br>
2.	In that directory run the command make. <br>
3.	It then will print out an executable command. Copy and run that command.<br>
4.	Enjoy playing the game. <br>
<img width="464" alt="Screenshot 2021-04-30 005853" src="https://user-images.githubusercontent.com/54922683/116581444-4b8d6400-a94f-11eb-8f57-fdcdb54abd09.png">



## How to compile program and run
1.Installing ncurses on Debian/Ubuntu Linux<br>
   sudo apt-get install libncurses5-dev libncursesw5-dev
