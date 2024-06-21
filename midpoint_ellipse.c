#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// Function to plot the symmetric points of the ellipse
void drawPixel(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, RED);
    putpixel(xc - x, yc + y, RED);
    putpixel(xc + x, yc - y, RED);
    putpixel(xc - x, yc - y, RED);
}

// Function to draw an ellipse using Mid-point Algorithm
void mid_point_ellipse(int xc, int yc, int a, int b) {
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int p = b2 - a2 * b + 0.25 * a2;
    int dx = 2 * b2 * x, dy = 2 * a2 * y;

    while (dx < dy) {
        drawPixel(xc, yc, x, y);
        if (p < 0) {
            p += dx + b2;
        } else {
            y--;
            dy -= 2 * a2;
            p += dx - dy + b2;
        }
        x++;
        dx += 2 * b2;
    }

    p = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;
    while (y >= 0) {
        drawPixel(xc, yc, x, y);
        if (p > 0) {
            p -= dy - a2;
        } else {
            x++;
            dx += 2 * b2;
            p += dx - dy + a2;
        }
        y--;
        dy -= 2 * a2;
    }
}

int main() {
    int gd = DETECT, gm;
    int xc,yc,a,b;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Path for BGI driver

    xc = 200, yc = 200, a = 20, b = 30;
    mid_point_ellipse(xc, yc, a, b);

    getch();
    closegraph();
    return 0;
}
