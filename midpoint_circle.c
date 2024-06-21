#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void draw_circle(int x1,int y1,int r){
    int p0,x0,y0;
    p0=1-r;
    x0=0;
    y0=r;
    while((x0<=y0)&(y0>=y1))
    {
        if(p0<0)
        {
            x0=x0+1;
            y0=y0;
            p0=p0+2*x0+1;
        }
        else
        {
            x0=x0+1;
            y0=y0-1;
            p0=p0+2*x0-2*y0+1;
        }
        putpixel(x0+x1,y0+y1,15);
        putpixel(y0+x1,x0+y1,15);
        putpixel(-x0+x1,y0+y1,15);
        putpixel(-y0+x1,x0+y1,15);
        putpixel(-x0+x1,-y0+y1,15);
        putpixel(-y0+x1,-x0+y1,15);
        putpixel(x0+x1,-y0+y1,15);
        putpixel(y0+x1,-x0+y1,15);
        
    }

    getch();
   


}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy;
    float m;
    int p0;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Path for BGI driver
    draw_circle(200,100,20);

    return 0;
    }