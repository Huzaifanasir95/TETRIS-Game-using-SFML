/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;


using namespace sf;
void fallingPiece(float& timer, float& delay,int& colorNum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
           for(int i=0;i<4;i++)
            gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
            colorNum=1+rand()%7;
            int n=rand()%7;
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        timer=0;
    }
delay=0.4;
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
 //Function to display the menu window

void display_menu() {
    sf::RenderWindow window(sf::VideoMode(700, 1000), "Menu");

    sf::Texture background_texture;
    if (!background_texture.loadFromFile("img/background_1.png")) {
        cout << "Error loading background image" << endl;
        return;
    }
    sf::Sprite background_sprite(background_texture);
    background_sprite.setPosition(0, 0);

    sf::Font font;
    if (!font.loadFromFile("Pacifico.ttf")) {
        cout << "Error loading font" << endl;
        return;
    }

    sf::Text start_opt;
    start_opt.setFont(font);
    start_opt.setString("Start Game");
    start_opt.setCharacterSize(100);
    start_opt.setFillColor(sf::Color::White);
    start_opt.setPosition(80, 200);

    sf::Text inst_opt;
    inst_opt.setFont(font);
    inst_opt.setString("Instructions");
    inst_opt.setCharacterSize(100);
    inst_opt.setFillColor(sf::Color::White);
    inst_opt.setPosition(80, 400);

    sf::Text high_opt;
    high_opt.setFont(font);
    high_opt.setString("High Score");
    high_opt.setCharacterSize(100);
    high_opt.setFillColor(sf::Color::White);
    high_opt.setPosition(80, 600);

    sf::Text quit_opt;
    quit_opt.setFont(font);
    quit_opt.setString("Quit");
    quit_opt.setCharacterSize(100);
    quit_opt.setFillColor(sf::Color::White);
    quit_opt.setPosition(80, 800);

    bool start_select = true;
    bool inst_select = false;
    bool high_select = false;
    bool quit_select = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (start_select) {
                        quit_select = true;
                        start_select = false;
                    } else if (inst_select) {
                        start_select = true;
                        inst_select = false;
                    } else if (high_select) {
                        inst_select = true;
                        high_select = false;
                    } else {
                        high_select = true;
                        quit_select = false;
                    }
                } else if (event.key.code == sf::Keyboard::Down) {
                    if (start_select) {
                        inst_select = true;
                        start_select = false;
                    } else if (inst_select) {
                        high_select = true;
                        inst_select = false;
                    } else if (high_select) {
                        quit_select = true;
                        high_select = false;
                    } else {
                        start_select = true;
                        quit_select = false;
                    }
                } else if (event.key.code == sf::Keyboard::Enter) {
                    if (start_select) {
                        // Start the game
                        cout << "Starting the game..." << endl;
                        return;
                    } else if (inst_select) {
                        // Show instructions
                        sf::RenderWindow instructionwindow(sf::VideoMode(800, 600), "Instructions");
                        bool instwindowopen = true;
                        sf::Texture backgroundTexture1;
                        if (!backgroundTexture1.loadFromFile("img/instback.jpg")) {
                            cout << "Error loading instruction background image" << endl;
                            return;
                        }
                        sf::Sprite backgroundSprite(backgroundTexture1);
                        sf::Text instruction;
                        instruction.setFont(font);
                        instruction.setCharacterSize(24);
                        instruction.setString("\n     Game Instructions:\n  - Use the arrow keys (left, right, down) to move the \n falling tetromino horizontally and downwards.\n  - Press the up arrow key to rotate the tetromino \nclockwise.\n  - Press the spacebar to instantly drop the tetromino \n to the bottom of the playing field.\n\n  Press Escape to exit this window.");
                        instruction.setPosition(100, 100);

                        while (instwindowopen) {
                            sf::Event instructionEvent;
                            while (instructionwindow.pollEvent(instructionEvent)) {
                                if (instructionEvent.type == sf::Event::Closed) {
                                    instructionwindow.close();
                                    instwindowopen = false;
                                } else if (instructionEvent.type == sf::Event::KeyPressed) {
                                    if (instructionEvent.key.code == sf::Keyboard::Escape) {
                                        instructionwindow.close();
                                        instwindowopen = false;
                                    }
                                }
                            }

                            instructionwindow.clear();
                            instructionwindow.draw(backgroundSprite);
                            instructionwindow.draw(instruction);
                            instructionwindow.display();
                        }
                    } else if (high_select) {
                        // Show high scores
                        sf::RenderWindow highwindow(sf::VideoMode(800, 600), "High Score");
                        bool highwindowopen = true;
                        sf::Texture backgroundTexture;
                        if (!backgroundTexture.loadFromFile("img/highback.jpg")) {
                            cout << "Error loading high score background image" << endl;
                            return;
                        }
                        sf::Sprite backgroundSprite(backgroundTexture);
                        sf::Text highscore;
                        highscore.setFont(font);
                        highscore.setCharacterSize(24);
                        highscore.setString(" \n\n");

                        ifstream file("score.txt");
                        if (file.is_open()) {
                            struct Score {
                                string name;
                                int score;
                            };

                            Score topScores[3];
                            for (int i = 0; i < 3; i++) {
                                topScores[i].score = -1;
                            }

                            string name;
                            int score;
                            while (file >> name >> score) {
                                for (int i = 0; i < 3; i++) {
                                    if (score > topScores[i].score) {
                                        for (int b = 2; b > i; b--) {
                                            topScores[b] = topScores[b - 1];
                                        }
                                        topScores[i].name = name;
                                        topScores[i].score = score;
                                        break;
                                    }
                                }
                            }
                            file.close();

                            for (int i = 0; i < 3; i++) {
                                if (topScores[i].score != -1) {
                                    highscore.setString(highscore.getString() +"\t"+ topScores[i].name + "\t" + to_string(topScores[i].score) + "\n\n\n\n\n");
                                }
                            }
                        } else {
                            cout << "Error opening score file" << endl;
                        }

                        while (highwindowopen) {
                            sf::Event highEvent;
                            while (highwindow.pollEvent(highEvent)) {
                                if (highEvent.type == sf::Event::Closed) {
                                    highwindow.close();
                                    highwindowopen = false;
                                } else if (highEvent.type == sf::Event::KeyPressed) {
                                    if (highEvent.key.code == sf::Keyboard::Escape) {
                                        highwindow.close();
                                        highwindowopen = false;
                                    }
                                }
                            }

                            highwindow.clear();
                            highwindow.draw(backgroundSprite);
                            highwindow.draw(highscore);
                            highwindow.display();
                        }
                    } else {
                        window.close();
                        exit(0);
                    }
                }
            }
        }

        if (start_select) {
            start_opt.setFillColor(sf::Color::Red);
            inst_opt.setFillColor(sf::Color::White);
            high_opt.setFillColor(sf::Color::White);
            quit_opt.setFillColor(sf::Color::White);
        } else if (inst_select) {
            start_opt.setFillColor(sf::Color::White);
            inst_opt.setFillColor(sf::Color::Red);
            high_opt.setFillColor(sf::Color::White);
            quit_opt.setFillColor(sf::Color::White);
        } else if (high_select) {
            start_opt.setFillColor(sf::Color::White);
            inst_opt.setFillColor(sf::Color::White);
            high_opt.setFillColor(sf::Color::Red);
            quit_opt.setFillColor(sf::Color::White);
        } else if (quit_select) {
            start_opt.setFillColor(sf::Color::White);
            inst_opt.setFillColor(sf::Color::White);
            high_opt.setFillColor(sf::Color::White);
            quit_opt.setFillColor(sf::Color::Red);
        }

        window.clear();
        window.draw(background_sprite);
        window.draw(start_opt);
        window.draw(inst_opt);
        window.draw(quit_opt);
        window.draw(high_opt);
        window.display();
    }
}

void move(int delta_x)
{

for(int i=0;i<4;i++)
{
	point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][0]+=delta_x;

}


	if(!anamoly())
       	{
        
        	for(int i=0;i<4;i++)
        	{
        	point_1[i][0]=point_2[i][0];
        
        	}
        }

}
void disappear()
{


int temp=M-1;
for(int i=M-1 ; i>0 ; i--)
{
int count=0;
	for(int j=0 ; j<N ;j++)  
	{
        if(gameGrid[i][j] != 0)
        count++;
        gameGrid[temp][j]=gameGrid[i][j];
        }
     		if(count<N)
       		temp--;
}

}



void rotation(bool rotate)
{
if(rotate)
{
for(int i=0 ;i<4;i++)
{
int y=point_1[i][0]-point_1[1][0];
int x=point_1[i][1]-point_1[1][1];
point_1[i][0]=point_1[1][0]-x;
point_1[i][1]=point_1[1][1]+y;
}
}
if(!anamoly())
       	{
        
        	for(int i=0;i<4;i++)
        	{
        	point_2[i][0]=point_1[i][0];
        	point_2[i][1]=point_1[i][1];
       	
        
      	
        }

}
}










///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
