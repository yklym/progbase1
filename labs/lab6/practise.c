// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>    // Для друку в термінал
#include <math.h>     // Для математичних функцій
#include <stdlib.h>   // Деякі додаткові функції
#include <progbase.h> // Спрощений ввід і вивід даних у консоль
#include <progbase/console.h>
#include <progbase/canvas.h>

struct vec2D {
    float x;
    float y;
};
struct Color {
    int red;
    int green;
    int blue;
};

struct Ball {
    struct vec2D loc;
    // struct vec2D vel;
    float radius;
    struct Color:
    float rotRadius;
    float rotSpeed;
};
int main()
{
    // Початок програми
    Console_clear();
    struct ConsoleSize cs = Console_size();
    int w = cs.columns;
    int h = cs.rows * 2;
    struct vec2D loc = {w/2, h/2};
    struct vec2D vel = {40, -25};

    const int delay = 33;
    // Canvas_setOrigin(5, 10);
    float dx = 10;
    float dy = 5;
    struct Ball balls[3]= {
        {
            {w/2, h/2},
            {40, -25},
            5,
        }, 
        
        {
            {w/2, h/2},
            {40, -25},
            5,
        },
        {
            {w/2, h/2},
            {40, -25},
            5,
        },
    }
    struct Ball ball = {
        {w/2, h/2},
        {40, -25},
        5,
    };
    Canvas_setSize(w, h);
    Canvas_invertYOrientation();
    while (1)
    {
        float dt = delay / 100.0;
        //update
        ball.loc.x += dt * dx;
        ball.loc.y += dy * dt;
        if (ball.loc.x - 10<0 || ball.loc.x + 10 > w){
            dx = -dx;
        }
        if (ball.loc.y + 10 > h || ball.loc.y - 10 < 0){
            dy = - dy;
        }
        //draw

        Canvas_beginDraw();
        
        Canvas_setColorRGB(0, 255, 0);
        Canvas_strokeCircle(ball.loc.x, ball.loc.y, 10);
        // Canvas_fillCircle(ball.loc.x, ball.loc.y, 5);
        struct vec2D velvec = vel;
        float VelvecLen= sqrt(velvec.x*velvec.x + velvec.y*velvec.y);
        float newLen = 10;
        velvec.x = velvec.x/VelvecLen * newLen;
        velvec.y = velvec.y/ VelvecLen * newLen;
        Canvas_setColorRGB(0, 0, 125);
        Canvas_strokeLine(ball.loc.x, ball.loc.y, ball.loc.x + vel.x, ball.loc.y + vel.y );
        Canvas_endDraw();


        sleepMillis(delay);
    }

    

    // Кінець програми
    return 0;
}