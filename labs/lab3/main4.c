#include <stdio.h>
#include <progbase/console.h>
#include <math.h>
#include <stdlib.h>
void drawLine(int x0, int y0, int x1, int y1, char ch);


int main(void)
{
    char key = 0;
    // VARS FOR LINE A
    int Ax0 = 30;
    int Ay0 = -1 * Ax0 + 34;//4
    int Ax1 = 17;
    int Ay1 = -1 * Ax1 + 34;;//0
    //VARS FOR LINE B
    int Bx0 = 5;
    int By0 = Bx0 - 5;//0
    int Bx1 = 22;
    int By1 = Bx1 - 5; // 0

    
    do { 
        // FRAME
        int zwidth = 0;
        int zheight = 0;//18

        const int x0 = 1;
        const int width = 30;
        const int y0 = 1;
        const int height = 16;

        int Ay = 0;
        int Ax = 0;

        Console_clear();

        // horizontal lines
        for (zwidth = x0; zwidth <= x0 + width; zwidth++)
        {
            zheight = y0;
            Console_setCursorPosition(zheight, zwidth);
            printf("=");
            zheight = y0 + height;
            Console_setCursorPosition(zheight, zwidth);
            printf("=");
        }

        // vertical lines
        for (zheight = y0; zheight <= y0 + height; zheight++)
        {
            zwidth = x0;
            Console_setCursorPosition(zheight, zwidth);
            printf("|");
            zwidth = x0 + width;
            Console_setCursorPosition(zheight, zwidth);
            printf("|");
        }
        

        int ax = 0;
        int ay = 0;

        const int ax0 = x0 + 1;
        const int ay0 = y0 + 1;
        const int awidth = width;
        const int aheight = height ;

        // ADD SOME COLORS
        Console_setCursorPosition(ay0, ax0);
        
        for (ay = ay0; ay <= aheight; ay++)
        {
            for (ax = ax0; ax <= awidth; ax++)
            {
                Console_setCursorPosition(ay, ax);
                
                if ((ax >= Bx0 + ay) && ax <= Ax0 - ay + Ay0) {
                    Console_setCursorAttribute(BG_GREEN);
                } else if (ax >= Ax0 - ay + Ay0  && ax >= Bx0 + ay) {
                    Console_setCursorAttribute(BG_RED);
                } else if (ax <= Bx0 + ay && ax <= Ax0 - ay + Ay0){
                    Console_setCursorAttribute(BG_MAGENTA);
                } else 
                Console_setCursorAttribute(BG_BLUE);   
                

                putchar(' ');
                Console_reset();
            }
        }
       


        //LINE 1
        Console_setCursorAttribute(BG_BLACK);
       
        
        for (int Ax += width ; Ax <= width && Ay <= height; Ax--){
            Ay = -1 * Ax + 34;
            Console_setCursorPosition(Ay, Ax);
            printf(" ");
        }
        
        
        //drawLine(Ax0, Ay0, Ax1, Ay1, ' ' );
        //LINE 2
        drawLine(Bx0, By0, Bx1, By1, ' ' );
        
        //INPUT
        Console_reset();
        key = Console_getChar();
        
        switch(key){
            case 'w':
            case 'a': 
            {
                if (Ax1 > x0 + 1) {
                // Ax0 -= 1;
                // Ax1 -= 1;
                    Ay0 -= 1;
                    Ax1 -= 1;
                        
                }
                
            }
            break;
            
            case 's':
            case 'd': 
            {
                if (Ay0 < 0.4 * zwidth ){
                    Ay0 += 1;
                    Ax1 += 1;
                }
            } 
            break;
            
            case 'i':
            case 'j': 
            {
                if (Bx0 >= x0 + 1) {
                Bx0 -= 1;
                Bx1 -= 1;
                }    
            }     
            break;
            
            case 'k':
            case 'l':
            {
                if (Bx1 < zwidth - 1){
                    Bx0 += 1;
                    Bx1 += 1;
                }
            }
            break;
            
            default: ;
        }
        Console_reset();
        Console_setCursorPosition(25, 1);
    
    }
    while (key != ' ');
    
    return 0;
}



void drawLine(int x0, int y0, int x1, int y1, char ch)
{    
  int dy = abs(y1 - y0);
  int dx = abs(x1 - x0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;

  if (x0 > 0 && y0 > 0)
  {
      Console_setCursorPosition(y0, x0);
      putchar(ch);
  }

  if (dy <= dx)
  {
      int d = (dy << 1) - dx;
      int d1 = dy << 1;
      int d2 = (dy - dx) << 1;
      for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
      {
          if ( d >0)
          {
              d += d2;
              y += sy;
          }
          else
          {
              d += d1;
          }
          // draw point
          if (y > 0 && x > 0)
          {
              Console_setCursorPosition(y, x);
              putchar(ch);
          }
      }
  }
  else
  {
      int d = (dx << 1) - dy;
      int d1 = dx << 1;
      int d2 = (dx - dy) << 1;
      for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
      {
          if ( d >0)
          {
              d += d2;
              x += sx;
          }
          else
          {
              d += d1;
          }
          // draw point
          if (x > 0 && y > 0)
          {
              Console_setCursorPosition(y, x);
              putchar(ch);
          }
      }
  }
}

