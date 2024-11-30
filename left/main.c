#include <stdio.h>
#include "API.h"

// Function to log messages for debugging
void log1(char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
    log1("Running...");

    // Starting position (assume the robot starts at (0, 0))
    int x = 0, y = 0;
    int facing = 0; // 0: North, 1: East, 2: South, 3: West

    // Color the starting position
    API_setColor(x, y, 'G');
    API_setText(x, y, "Start");

    while (1) {
        if (!API_wallLeft()) {
            API_turnLeft();
            facing = (facing + 3) % 4; // Update facing direction (left turn)
        }
        while (API_wallFront()) {
            API_turnRight();
            facing = (facing + 1) % 4; // Update facing direction (right turn)
        }
        API_moveForward();

        // Update current position based on facing direction
        switch (facing) {
            case 0: y++; break; // Moving North
            case 1: x++; break; // Moving East
            case 2: y--; break; // Moving South
            case 3: x--; break; // Moving West
        }

        // Color the visited spot and add a label
        API_setColor(x, y, 'R'); // Green for visited


        // Log the current position
        char logMessage[50];

        log1(logMessage);
    }
}
