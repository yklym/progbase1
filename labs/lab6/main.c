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
    struct color color;
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
    const int delay = 33;
    const int gravitation = 4;
    const int pointAverage = rand() % (7 - 3 + 1) + 3;
    const int ballAverage = 10000;

    struct point points[pointAverage];
    for (int i = 0; i < pointAverage; i++)
    {
        points[i].radius = 2;
        points[i].loc.x = rand() % (w - points[i].radius + 1 - 10) + 10;
        points[i].loc.y = rand() % (h - points[i].radius + 1 - 10) + 10;
        points[i].color.red = randRGB();
        points[i].color.green = randRGB();
        points[i].color.blue = randRGB();
        points[i].power = 0;
    }
    struct Ball ball[ballAverage];
    for (int i = 0; i < ballAverage; i++)
    {
        ball[i].radius = rand() % (5 + 1 - 3) + 3;
        ball[i].loc.x = w / 2;
        ball[i].loc.y = ball[i].radius + 1;
        ball[i].bColor.red = randRGB();
        ball[i].bColor.green = randRGB();
        ball[i].bColor.blue = randRGB();
        ball[i].speed.x = 0;
        ball[i].speed.y = 3;
    };
    int lich = 0;

    Canvas_setSize(w, h);
    Canvas_invertYOrientation();
    do
    {
        lich++;
        for (int i = 0; i <= lich / 10; i++)
        {
            if( i == ballAverage){
                break;
            }
            for (int j = 0; j < pointAverage; j++)
            {

                points[j].distance.x = ball[i].loc.x - points[j].loc.x;
                points[j].distance.y = ball[i].loc.y - points[j].loc.y;
                points[j].power = sqrt(pow(points[j].distance.x, 2) + pow(points[j].distance.y, 2));
                //ball[i].speed.x += points[j].distance.x  * gravitation/ pow(points[j].power, 2);
                if(points[j].loc.x > ball[i].loc.x){
                    ball[i].speed.x += points[j].distance.x  * gravitation/ pow(points[j].power, 2);
                }
                if(points[j].loc.x < ball[i].loc.x){
                    ball[i].speed.x -= points[j].distance.x * gravitation / pow(points[j].power, 2);
                }
                if(points[j].loc.y > ball[i].loc.y){
                    ball[i].speed.y += points[j].distance.y * gravitation / pow(points[j].power, 2);
                }
                if(points[j].loc.y < ball[i].loc.y){
                    ball[i].speed.y -= points[j].distance.y * gravitation / pow(points[j].power, 2);
                }
            }

            if (ball[i].loc.x + ball[i].radius >= w || ball[i].loc.x - ball[i].radius <= 0)
            {
                ball[i].speed.x = -ball[i].speed.x;
            }
            if (ball[i].loc.y + ball[i].radius >= h || ball[i].loc.y - ball[i].radius <= 0)
            {
                ball[i].speed.y = -ball[i].speed.y;
            }
            if (ball[i].speed.x == 0 || ball[i].speed.y == 0)
            {
                ball[i].speed.x += 3;
                ball[i].speed.y += 3;
            }

            ball[i].loc.x += ball[i].speed.x;
            ball[i].loc.y += ball[i].speed.y;
            
        }

        Canvas_beginDraw();
        for (int i = 0; i <= lich; i += 10)
        {
            if(i / 10 == ballAverage){
                break;
            }
            Canvas_setColorRGB(ball[(i / 10)].bColor.red, ball[i / 10].bColor.green, ball[i / 10].bColor.blue);
            Canvas_fillCircle(ball[i / 10].loc.x, ball[i / 10].loc.y, ball[i / 10].radius);
            
        }
        for (int k = 0; k < pointAverage; k++)
        {
            Canvas_setColorRGB(points[k].color.red, points[k].color.green, points[k].color.blue);
            Canvas_strokeCircle(points[k].loc.x, points[k].loc.y, 2);
        }
        
        Canvas_endDraw();

        sleepMillis(delay);
        
    } while (!Console_isKeyDown());

    return 0;
}

int randRGB()
{
    int a = (rand() % 255 + 1);
    return a;
}