#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
float xbv;  //Velocity of ball in X axis.
float ybv;  //Velocity of ball in Y axis.
int vb_x;
int toss;
int ballxpos = 400;
int t;
using namespace sf;
int main()
{
    //Random Generator
    srand ( time(NULL) );
    //Window features
    RenderWindow window(VideoMode(800, 400), "Pong!");
    window.setFramerateLimit(60);
    //Models
    CircleShape ballz(8.f);
    ballz.setFillColor(Color::White);
    RectangleShape palette1(Vector2f(20,80));
    palette1.setFillColor(Color::White);
    RectangleShape palette2(Vector2f(20,80));
    palette2.setFillColor(Color::White);
    //Line in between
    VertexArray lines(LinesStrip, 2);
    lines[0].position = Vector2f(400,0);
    lines[0].color = Color::White;
    lines[1].position = Vector2f(400,400);
    lines[1].color = Color::White;
    //Setting Origins and positions
    palette1.setOrigin(10,40);
    palette2.setOrigin(10,40);
    ballz.setOrigin(8,8);
    palette1.setPosition(40, 200);
    palette2.setPosition(760, 200);
    ballz.setPosition(400, 200);
    //Setting Start Values
    xbv = 7;
    // Window Loop
    while (window.isOpen())
    {
        //Ball Collision mechanics in X axis
        if (ballz.getPosition().x>=800)
        {
            ballz.setPosition(400,200);
            toss = rand() % 100;
            if  (toss < 50 )
                {
                    xbv = 7;
                }
            if (toss > 50 )
                {
                    xbv = -7;
                }

        }

        if (ballz.getPosition().x<=0)
        {
            toss = rand() % 100;
            ballz.setPosition(400,200);
            if  (toss < 50 )
                {
                    xbv = 7;
                }
            if (toss > 50 )
                {
                    xbv = -7;
                }

        }
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }


        ballz.move(xbv, ybv);
    // Display of Sprites etc
        window.clear(Color::Black);
        window.draw(ballz);
        window.draw(palette1);
        window.draw(palette2);
        window.draw(lines);
        window.display();
    }

    return 0;
}
