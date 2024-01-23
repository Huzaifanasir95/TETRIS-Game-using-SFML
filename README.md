# TETRIS-Game
I implemeted tetris game using C++ and using concepts of PF
Tetris has very simple rules:  
● The blocks can be moved only in specific ways (left, right, rotate, drop). 
● The blocks can only be removed from the screen by filling all the blank spaces in a line and clearing that line. 
● The game is over if the blocks stack up in such a way that the lines are not cleared and reach the top of the 
screen. 
● Each time a line is cleared in Tetris, you are awarded points. 
● Each time the blocks reach the top of the screen, the game is over. 
GAME INTERFACE: 
The game consists of a matrix i.e., the playing field. All the blocks and lines are to be enclosed within the matrix. 
Initial code of the game interface is provided. You are required to build upon that interface. 
GENERATION OF RANDOM SHAPE: 
The shapes are composed of 4 squares arranged in 7 different patterns – you can use your creativity for implementing 
the logic of creating different shapes. There are seven different types of blocks: I, O, L, J, S, Z, and T. You are required 
to generate these blocks by defining separate array for each block or a single array for the all the shapes. The colors 
of the blocks are varied. This means that block J can be in all the given possible colors. At each step blocks are to be 
randomly introduced in the game, analyze the attached figure. 
NOTE: The image for these pieces your will be using in the game is already in the provided folder. 
MOVEMENT, ROTATION AND DROPPING OF SHAPES: 
The user can move the blocks around and rotate them. The movement of the block is either left or right. The movement 
of blocks is to be done using the arrow keys of the keyboard. The blocks are supposed to be dropped in the matrix 
automatically. Conventionally, the blocks fall at a certain rate, but you can make them fall faster by using the 
downward movement. 
SHADOW OF THE DROPPING SHAPES: 
Before the shape is dropped a shadow of it should appear in the matrix. This feature will help the user in deciding if 
the block can be placed at that particular spot in the matrix of not. 
DROPPING THE BOMB: 
1. Bomb will fall randomly on a random spot and would not be a controlling piece like the others. 
2. If the bomb color matches the block, then all blocks will be destroyed. 
3. If the bomb drop does not match the block color; only 4 blocks will be destroyed 
4. If the bomb is dropped in vacant areas, then nothing will happen. 
NOTE: More than 10 blocks matching the same color should be destroyed 
POINT SCORING: 
a. 
Line completion: 
If the user can completely fill one horizontal line with colored squares, that line disappears and any filled squares 
above move down. If the player is unable to fill lines completely, the blocks will stack up and eventually reach 
the top of the playing field. Following are the scores given in line completion: 
LINES COMPLETED 
1 line 
SCORE 
2 lines simultaneously 
10 points * level 
30 points * level 
3 lines simultaneously 
4 lines simultaneously 
60 points * level 
100 points * level 
b. Same colored block matching: 
GAME OVER: 
Each time you clear a line in Tetris, you are awarded more points. Each time your pieces reach the top of the screen, 
your game is over. 
GAME LEVEL: 
The game is based on 2 levels. In the beginner’s level the user is provided with the option of only 4 different blocks. 
In the advanced level all blocks are unlocked and the pace of dropping down is increased. 
LEVELING UP THE DIFFICULTY: 
The user spending more than five competing/struggling in filling game rows, the difficulty level should increase. 
When the specified interval runs short, the last row should become non-interactive for the game anymore. Continue 
the process each time five minutes are spent. 
HIGH SCORES: 
When the game starts, the high-scores are read from a file (named highscores.txt) and stored in an array of size 10. If 
the score of the current game makes it to the list of high-scores, the lowest score is removed from the array and the 
new contents of the array overwrite the file. 
MENU: 
The game should be menu-driven and the following options should be available to the user: 
1. Start a new game 
2. See high-scores 
3. Help 
4. Exit 
During the execution of the game, the player can press the ‘P’ key to pause the game and see the following menu: 
1. Start a new game 
2. See high-scores 
3. Help 
4. Exit 
5. Continue 
The names of the menu items are self-explanatory and should perform the relevant function upon pressing the 
respective number key. In the Help menu, you can show the rules/keys to play the game. 
