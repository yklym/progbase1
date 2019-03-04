// Компілювати за допомогою:
// gcc main.c -lprogbase -lm

#include <stdio.h>  // Для друку в термінал
#include <math.h>   // Для математичних функцій
#include <stdlib.h> // Деякі додаткові функції
#include <progbase.h>
#include <time.h>
#include <progbase/console.h>
#include <progbase/canvas.h> // Спрощений ввід і вивід даних у консоль

struct cords
{
    float x;
    float y;
};
struct vect
{
    float x;
    float y;
};
struct color
{
    int red;
    int green;
    int blue;
};
struct Ball
{
    struct cords loc;
    struct color bColor;
    int radius;
    struct vect speed;
};
struct point
{
    struct cords loc;
    struct color bcolor;
    int radius;
    float power;
    struct vect distance;
};

int randRGB();

int main()
{
    Console_clear();
    srand(time(0));
    struct ConsoleSize cs = Console_size();
    const int w = cs.columns;
    const int h = cs.rows * 2;
    const int delay = 100;
    const int gravitation = 4;
    const int pointAverage = rand() % (5) + 1;
    // const int ballAverage = 10;
    char key = '\0';


    struct point points[pointAverage];   
    for (int i = 0; i < pointAverage; i++)
    {
        points[i].radius = 2;
        points[i].loc.x = rand() % (w - points[i].radius + 1 - 10) + 10;
        points[i].loc.y = rand() % (h - points[i].radius + 1 - 10) + 10;
        points[i].bcolor.red = randRGB();
        points[i].bcolor.green = randRGB();
        points[i].bcolor.blue = randRGB();
        points[i].power = 0;
    }
    struct Ball ball;
    ball.radius = 3;
    ball.loc.x = w / 2;
    ball.loc.y = 0 + ball.radius + 3;
    ball.bColor.red = randRGB();
    ball.bColor.green = randRGB();
    ball.bColor.blue = randRGB();
    ball.speed.x = 0;
    ball.speed.y = 4;

    int lich = 0;
    
    Canvas_setSize(w, h);
    Canvas_invertYOrientation();
    while (1)
    {
        for(int j = 0; j < pointAverage; j++){
            
                points[j].distance.x = ball.loc.x - points[j].loc.x;
                points[j].distance.y = ball.loc.y - points[j].loc.y;
                points[j].power = sqrt(pow(points[j].distance.x, 2) + pow(points[j].distance.y, 2));
                //ball.speed.x += points[j].distance.x  * gravitation/ pow(points[j].power, 2);
                //points[].power = sqrt(points[].loc.x * points[].loc.x + points[].loc.y * points[].loc.y);
                if(points[j].loc.x > ball.loc.x){
                    ball.speed.x += points[j].distance.x  * gravitation/ pow(points[j].power, 2);
                }
                if(points[j].loc.x < ball.loc.x){
                    ball.speed.x -= points[j].distance.x * gravitation / pow(points[j].power, 2);
                }
                if(points[j].loc.y > ball.loc.y){
                    ball.speed.y += points[j].distance.y * gravitation / pow(points[j].power, 2);
                }
                if(points[j].loc.y < ball.loc.y){
                    ball.speed.y -= points[j].distance.y * gravitation / pow(points[j].power, 2);
                }
            }
        ball.loc.x += ball.speed.x;
        ball.loc.y += ball.speed.y;


        
        if(ball.loc.x + ball.radius >= w - 1 || ball.loc.x - ball.radius <= 1){
             ball.speed.x = -ball.speed.x;
        }
        if(ball.loc.y + ball.radius >= h - 1 || ball.loc.y - ball.radius <= 1 ){
             ball.speed.y = -ball.speed.y;
        }
        if(ball.loc.x == 0 && ball.loc.y == 0){
            ball.speed.x += 3;
            ball.speed.y += 3;
        }
        Canvas_beginDraw();
        Canvas_setColorRGB(ball.bColor.red, ball.bColor.green, ball.bColor.blue);
        Canvas_fillCircle(ball.loc.x, ball.loc.y, ball.radius );

        for(int i =0;i < pointAverage; i++){
            Canvas_strokeCircle(points[i].loc.x, points[i].loc.y, points[i].radius);
        }



        Canvas_endDraw();

        sleepMillis(delay);
    }

    return 0;
}

int randRGB()
{
    int a = (rand() % 255 + 1);
    return a;
}