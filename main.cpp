/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;

int main(){

display_menu();



    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3;
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
     obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    Sprite sprite(obj1), background(obj2), frame(obj3);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    bool rotate=0;
    Clock clock;
     bool pausegame = false;
       Font font;
    font.loadFromFile("Pencil Child.otf");
    RectangleShape pauseScreen(Vector2f(200, 100));
    pauseScreen.setFillColor(Color(0, 0, 0, 128));
    pauseScreen.setPosition(90, 150);

    Text pausedText("Game Paused", font, 32);
    pausedText.setPosition(90, 150);
    
    Text resumeText("Resume Game", font, 24);
    resumeText.setPosition(110, 190);
    resumeText.setFillColor(sf::Color::Red);

    Text quitText("Quit Game", font, 24);
    quitText.setPosition(120, 240);

   while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
rotate=false;

  Event e;
       /* while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
            else if (e.type == Event::KeyPressed) {
                if (e.key.code == Keyboard::Escape) {
                    pausegame = true;
                }
            }
        }*/ 
if (!pausegame){
        //---Event Listening Part---//
    
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive  
                    
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        
         move(delta_x);   
       fallingPiece(timer, delay , colorNum); 
     rotation(rotate);
       disappear();             //Example: fallingPiece() function is called here
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

delta_x=0;
        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    else {
            // Game is paused
            window.draw(pauseScreen);
            window.draw(pausedText);
            window.draw(resumeText);
            window.draw(quitText);
            window.display();

            bool resumeselected = true;
            while (pausegame) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                        pausegame = false;
                    }
                    else if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
                            resumeselected = !resumeselected;
                            if (resumeselected) {
                                resumeText.setFillColor(sf::Color::Red);
                                quitText.setFillColor(sf::Color::White);
                            }
                            else {
                                resumeText.setFillColor(sf::Color::White);
                                quitText.setFillColor(sf::Color::Red);
                            }
                        }
                        else if (event.key.code == sf::Keyboard::Enter) {
                            if (resumeselected) {
                                pausegame = false;
                            }
                            else {
                                window.close();
                                pausegame = false;
                            }
                        }
                    }
                }
            
    }
    }
    }
    return 0;
}


