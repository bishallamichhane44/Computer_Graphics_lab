#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to calculate the new value of the decision parameter
int calculateP(int p0, int dx, int dy) {
    if (p0 < 0)
        return p0 + 2 * dy;
    else
        return p0 + 2 * dy - 2 * dx;
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy;
    float m;
    int p0;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Path for BGI driver

    // Coordinates of the line
    x1 = 100;
    y1 = 100;
    x2 = 200;
    y2 = 150;
    
    dx = x2 - x1;
    dy = y2 - y1;
    m = (float) dy / dx;  // Slope of the line

    // If the slope is less than 1
    if (abs(m) < 1) {
        p0 = 2 * dy - dx;  // Initial decision parameter
        while (x1 <= x2) {
            putpixel(x1, y1, WHITE);  // Draw pixel
            if (p0 < 0) {
                p0 = p0 + 2 * dy;
            } else {
                p0 = p0 + 2 * dy - 2 * dx;
                y1++;
            }
            x1++;
        }
    } 
    // If the slope is greater than or equal to 1
    else {
        p0 = 2 * dx - dy;  // Initial decision parameter
        while (y1 <= y2) {
            putpixel(x1, y1, WHITE);  // Draw pixel
            if (p0 < 0) {
                p0 = p0 + 2 * dx;
            } else {
                p0 = p0 + 2 * dx - 2 * dy;
                x1++;
            }
            y1++;
        }
    }

    getch();  // Wait for user input
    closegraph();  // Close the graphics mode

    return 0;
}
