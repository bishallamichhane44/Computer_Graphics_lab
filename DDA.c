#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main(){
    int gd = DETECT, gm;
    float m;
    float x1 = 100, y1 = 100, x2 = 200, y2 = 300;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Calculate the slope
    m = (y2 - y1) / (x2 - x1);

    // Draw the line using DDA algorithm
    if (fabs(m) < 1) {
        while (x1 <= x2) {
            putpixel(fabs(x1), fabs(y1), WHITE);
            x1 = x1 + 1;
            y1 = y1 + m;
        }
    } else {
        while (y1 <= y2) {
            putpixel(fabs(x1), fabs(y1), WHITE);
            y1 = y1 + 1;
            x1 = x1 + (1 / m);
        }
    }

    getch();
    closegraph();
    return 0;
}
