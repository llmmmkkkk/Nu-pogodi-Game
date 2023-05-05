// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>

using namespace std;
using namespace sf;



class Volk {
public:
    Sprite player, arms;
    bool pravo, armsUp;
    int armsY = 0, armsAlign = 0;

    Volk(Texture& t, Texture& armsTexture) {
        player.setTexture(t);
        arms.setTexture(armsTexture);
        arms.setOrigin(54, 47);
    }

    void update(Texture& facingRight, Texture& facingLeft, Texture& armsRight, Texture& armsLeft) {
        if (pravo) {
            player.setTexture(facingRight);
            player.setPosition(490, 200);
            if (armsUp) {
                arms.setRotation(0);
                armsY = 0;
            }
            else {
                arms.setRotation(30);
                armsY = 50;
            }
            arms.setTexture(armsRight);
            arms.setPosition(600 + 54, 200 + 57 + armsY);
        }
        else {
            player.setTexture(facingLeft);
            player.setPosition(360, 200);
            if (armsUp) {
                arms.setRotation(0);
                armsY = 0;
            }
            else {
                arms.setRotation(-30);
                armsY = 50;
            }
            arms.setTexture(armsLeft);
            arms.setPosition(310 + 54, 200 + 47 + armsY);
        }

        if (!pravo && armsUp) {
            armsAlign = 0; 
        }
        else if (!pravo && !armsUp) {
            armsAlign = 1;
        }
        else if (pravo && armsUp) {
            armsAlign = 2;
        }
        else if (pravo && !armsUp) {
            armsAlign = 3;
        }
    }
};



class Egg {
public:
    Sprite sprites[5];
    FloatRect rect[5];
    bool vid[5];
    int tmr = 1000, next = 0;
    bool nextEgg = false;
    int whichEgg = rand() % 4;

    void set(Texture& eggImg, int& num) {
        vid[0] = true;
        for (int i = 1; i < 5; i++) {
            vid[i] = false;
        }
        for (int i = 0; i < 5; i++) {
            if (num == 1) {
                rect[i].left = 191 + 10 + i * 25;
                rect[i].top = 181 - 10 + i * 13;
            }
            else if (num == 2) {
                rect[i].left = 181 + 10 + i * 25;
                rect[i].top = 271 - 10 + i * 13;
            }
            else if (num == 3) {
                rect[i].left = 811 - (10 + i * 25);
                rect[i].top = 185 - 10 + i * 13;
            }
            else if (num == 4) {
                rect[i].left = 811 - (10 + i * 25);
                rect[i].top = 275 - 10 + i * 13;
            }
        }
        for (int i = 0; i < 5; i++) {
            sprites[i].setTexture(eggImg);
            sprites[i].setOrigin(11, 9);

            if (num < 3) {
                sprites[i].setRotation(30 * i);

            }
            else {
                sprites[i].setRotation(-30 * i);
            }
            sprites[i].setPosition(rect[i].left, rect[i].top);
        }
    }

    void updateEgg() {
        tmr = tmr - 1;
        if (tmr == 0) {
            vid[next] = false;
            next++;
            if (next < 5) {
                vid[next] = true;
            }
            else {
                this->nextEgg = true;
            }
            tmr = 1000;
        }
    }

    void updateEggM() {
        tmr = tmr - 1;
        if (tmr == 0) {
            vid[next] = false;
            next++;
            if (next < 5) {
                vid[next] = true;
            }
            else {
                this->nextEgg = true;
            }
            tmr = 500;
        }
    }

    void updateEggH() {
        tmr = tmr - 1;
        if (tmr == 0) {
            vid[next] = false;
            next++;
            if (next < 5) {
                vid[next] = true;
            }
            else {
                this->nextEgg = true;
            }
            tmr = 200;
        }
    }
    
};

class Score {
public:
    Sprite sprite[2];
    int frame;
    int s[2];

    Score(Texture& img) {
        for (int i = 0; i < 2; i++) {
            sprite[i].setTexture(img);
            sprite[i].setPosition(670 + 30 * i, 70);

            s[i] = 0;
        }
        frame = 0;
    }
    
    void update() {
        if (frame < 10) {
            s[1] = frame;
        }
        else {
            s[0] = frame / 10;
            s[1] = frame % 10;
        }
        for (int i = 0; i < 2; i++) {
            sprite[i].setTextureRect(IntRect(25 * s[i], 0, 25, 46));
        }
    }
};

class EggFall {
public:
    Sprite sprite;
    bool move;
    int animation = 1, time = 500;

    void setTexture(Texture& t) {
        sprite.setTexture(t);
        move = false;
    }

    void update(bool pravo) {
        time --;
        if (time == 0) {
            animation++;
            time = 500;
        }

        if (animation == 1) {
            if (pravo) {
                sprite.setTextureRect(IntRect(0, 0, 52, 66));
                sprite.setPosition(650, 350);
            }
            else {
                sprite.setTextureRect(IntRect(52, 0, -52, 66));
                sprite.setPosition(300, 350);
            }
        }
        if (animation == 2) {
            if (pravo) {
                sprite.setTextureRect(IntRect(0, 0, 87, 66));
                sprite.setPosition(650, 350);
            }
            else {
                sprite.setTextureRect(IntRect(87, 0, -87, 66));
                sprite.setPosition(265, 350);
            }
        }
        if (animation == 3) {
            if (pravo) {
                sprite.setTextureRect(IntRect(87, 0, 22, 66));
                sprite.setPosition(750, 350);
            }
            else {
                sprite.setTextureRect(IntRect(109, 0, -22, 66));
                sprite.setPosition(230, 350);
            }
        }
        if (animation == 4) {
            if (pravo) {
                sprite.setTextureRect(IntRect(109, 0, 22, 66));
                sprite.setPosition(780, 350);
            }
            else {
                sprite.setTextureRect(IntRect(131, 0, -22, 66));
                sprite.setPosition(195, 350);
            }
        }
        if (animation == 5) {
            if (pravo) {
                sprite.setTextureRect(IntRect(131, 0, 22, 66));
                sprite.setPosition(802, 350);
            }
            else {
                sprite.setTextureRect(IntRect(153, 0, -22, 66));
                sprite.setPosition(160, 350);
            }
        }
    }
};

int main()
{
    srand(time(0));
    /*RenderWindow optionsWindow(VideoMode(1000, 500), "Glavnaya");
    while (optionsWindow.isOpen()) {
        Vector2i pos = Mouse::getPosition(optionsWindow);
        Event optionsevent;
        while (optionsWindow.pollEvent(optionsevent)) {
            if (optionsevent.type == Event::Closed) {
                optionsWindow.close();
            }
            if (optionsevent.MouseButtonPressed && optionsevent.mouseButton.x > 500 && optionsevent.mouseButton.y > 250) {
                RenderWindow window(VideoMode(1000, 500), "Nu pogodi");
            }
            optionsWindow.display();
        }
        */
    Egg e[4];
    Egg e2[4]
        int num[4];
    for (int i = 0; i < 4; i++) {
        num[i] = i + 1;
        e[i].set(eggImg, num[i]);
        e2[i].set(eggImg, num[i]);
    }
    std::cout << e->whichEgg<<"\n";
    std::cout << "Game levels\n";
    std::cout << "Enter "<<"E"<<", for easy level\n";
    std::cout << "Enter "<<"M"<<", for medium level\n";
    std::cout << "Enter "<<"H"<<", for hard level\n";
    std::cout << "Enter "<<"SH"<<", for super hard level\n";
    string input;
    cin >> input;

    if (input == "E" || input == "e") {
        RenderWindow window(VideoMode(1000, 500), "Nu pogodi");


        Texture background;
        background.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/back.png");
        Sprite back(background);

        Texture v, r;
        v.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/volk.png");
        r.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/armsLeft.png");
        Volk volk(v, r);

        Texture right, armsRight;
        Texture left, armsLeft;
        right.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/volkPravo.png");
        left.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/volk.png");
        armsRight.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/armsRight.png");
        armsLeft.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/armsLeft.png");

        Texture eggImg;
        eggImg.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/eggs.png");
        Egg eggs[4];
        Egg eggs2[4]
        int num[4];
        for (int i = 0; i < 4; i++) {
            num[i] = i + 1;
            eggs[i].set(eggImg, num[i]);
            eggs2[i].set(eggImg, num[i]);
        }
        //int whichEgg = rand() % 4;

        Texture scoreTexture;
        scoreTexture.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/score.png");
        Score score(scoreTexture);

        Texture fallTexture;
        fallTexture.loadFromFile("C:/Users/user/source/repos/ConsoleApplication2/fall.png");
        EggFall eggfall;
        eggfall.setTexture(fallTexture);
        bool game = true, rightSide = true;


        while (window.isOpen()) {
            Vector2i pos = Mouse::getPosition(window);
            Event event1;
            while (window.pollEvent(event1)) {
                if (event1.type == Event::Closed) {
                    window.close();
                }
            }
            if (pos.x < 500) {
                volk.pravo = false;
            }
            else {
                volk.pravo = true;
            }
            if (pos.y > 250) {
                volk.armsUp = false;
            }
            else {
                volk.armsUp = true;
            }


            if (eggs->nextEgg == true) {
                if (eggs->whichEgg == volk.armsAlign) {
                    score.frame++;
                }
                else {
                    eggfall.move = true;
                    game = false;
                    if (eggs->whichEgg > 1) {
                        rightSide = true;
                    }
                    else {
                        rightSide = false;
                    }
                }
                eggs->whichEgg = rand() % 4;
                for (int i = 0; i < 4; i++) {
                    eggs[i].next = 0;
                }
                eggs->nextEgg = false;
            }
            //
            eggs2->whichEgg = rand() % 4;
            cout << eggs->whichEgg <<" "<< '/n';
            
                if (eggs2->nextEgg == true) {
                    if (eggs2->whichEgg == volk.armsAlign) {
                        score.frame++;
                    }
                    else {
                        eggfall.move = true;
                        game = false;
                        if (eggs2->whichEgg > 1) {
                            rightSide = true;
                        }
                        else {
                            rightSide = false;
                        }
                    }
                    eggs2->whichEgg = rand() % 4;
                    for (int i = 0; i < 4; i++) {
                        eggs2[i].next = 0;
                    }
                    eggs2->nextEgg = false;
                }
            

            if (!game && eggfall.animation == 6) {
                game = true;
                eggfall.animation = 1;
            }
            if (game) {
                volk.update(right, left, armsRight, armsLeft);
                for (int i = 0; i < 4; i++) {
                   if (eggs->whichEgg == i) {
                        eggs[i].updateEgg();
                    }
                    if (eggs2->whichEgg == i) {
                        eggs2[i].updateEgg();
                    }
                }
            }
            else {
                eggfall.update(rightSide);
            }


            score.update();
            window.clear(Color::White);
            window.draw(back);
            window.draw(volk.player);
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) {
                    if (eggs[j].vid[i] && eggs->whichEgg == j) {
                        window.draw(eggs[j].sprites[i]);
                    }
                    if (eggs2[j].vid[i] && eggs2->whichEgg == j) {
                        window.draw(eggs2[j].sprites[i]);
                    }
                }
            }
            window.draw(volk.arms);
            for (int i = 0; i < 2; i++) {
                window.draw(score.sprite[i]);
            }
            if (eggfall.move && !game) {
                window.draw(eggfall.sprite);
            }
            window.display();
        }
    }
    
}