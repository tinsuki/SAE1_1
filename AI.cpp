#include "AI.h"
#include "functions.h"
#include "typeDef.h"

void AIRandomShoot(Player &aPlayer, Player &anAI, bool saving, ofstream &saveFile){
    char x;
    int y;
    Coordinate coordi;
    x = randomIntBetween(0, GRIDSIZE-3)+'A';
    y = randomIntBetween(1, GRIDSIZE-2);
    coordi = {x, y};
    while (alreadyShot(aPlayer.grid, coordi)){
        x = randomIntBetween(0, GRIDSIZE-3)+'A';
        y = randomIntBetween(1, GRIDSIZE-2);
        coordi = {x, y};
    }

    if (hitOrMiss(aPlayer.grid, coordi)){
        if (isBoatSank(aPlayer.grid, y, x-'A'+1)){
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship sank" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship sank" << std::endl << std::endl;
            }
            anAI.score++;
        }
        else {
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship hit" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship hit" << std::endl << std::endl;
            }
        }
    }
    else {
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anAI);
        displayGrid(aPlayer, anAI);
        std::cout << std::endl;
        std::cout << "AI shoot in " << x << y << std::endl << std::endl;
        std::cout << "Miss" << std::endl << std::endl;
        if (saving){
            saveFile << "AI shoot in " << x << y << std::endl;
            saveFile << "Miss" << std::endl << std::endl;
        }
    }
}


void AIOptimisedShoot(Player &anAI, Player &aPlayer, bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY,  bool saving, ofstream &saveFile){
    char x;
    int y;
    Coordinate coordi;
    char oriDir = dir;
    if (!found){
        x = randomIntBetween(0, GRIDSIZE-3)+'A';
        y = randomIntBetween(1, GRIDSIZE-2);
        coordi = {x, y};
        while (alreadyShot(aPlayer.grid, coordi)){
            x = randomIntBetween(0, GRIDSIZE-3)+'A';
            y = randomIntBetween(1, GRIDSIZE-2);
            coordi = {x, y};
        }
    }
    else{
        switch (dir) {
        /* N for None the dirrection is not ditermined yet
         * H for horizontal
         * h for horizontal reverse
         * V for vertical
         * v for vertical reverse
         */
        case 'N':
            do {
                int currentDir = randomIntBetween(1,4);
                switch (currentDir) {
                case 1:
                    x = previousX+1;
                    y = previousY;
                    coordi = {x, y};
                    dir = 'H';
                    break;
                case 2:
                    x = previousX-1;
                    y = previousY;
                    coordi = {x, y};
                    dir = 'h';
                    break;
                case 3:
                    x = previousX;
                    y = previousY+1;
                    coordi = {x, y};
                    dir = 'V';
                    break;
                case 4:
                    x = previousX;
                    y = previousY-1;
                    coordi = {x, y};
                    dir = 'v';
                    break;
                }
            }while (alreadyShot(aPlayer.grid, coordi) or x-'A'<0 or x-'A'+1 > GRIDSIZE-2 or y < 1 or y > GRIDSIZE-2);
            break;
        case 'H':
            x = previousX + 1;
            y = previousY;
            coordi = {x, y};
            if (x-'A'+1 > GRIDSIZE-2 or alreadyShot(aPlayer.grid, coordi)){
                x = oriX-1;
                coordi = {x, y};
                dir = 'h';
            }
            break;
        case 'h':
            x = previousX - 1;
            y = previousY;
            coordi = {x, y};
            if (x-'A'+1 < 1 or alreadyShot(aPlayer.grid, coordi)){
                x = oriX+1;
                coordi = {x, y};
                dir = 'H';
            }
            break;
        case 'V':
            x = previousX;
            y = previousY + 1;
            coordi = {x, y};
            if (y > GRIDSIZE-2 or alreadyShot(aPlayer.grid, coordi)){
                y = oriY-1;
                coordi = {x, y};
                dir = 'v';
            }
            break;
        case 'v':
            x = previousX;
            y = previousY - 1;
            coordi = {x, y};
            if (y < 1 or alreadyShot(aPlayer.grid, coordi)){
                y = oriY+1;
                coordi = {x, y};
                dir = 'V';
            }
            break;
        }
    }
    if (hitOrMiss(aPlayer.grid, coordi)){
        if (isBoatSank(aPlayer.grid, y, x-'A'+1)){
            // if boat sank reinit the values
            found = false;
            oriX = 'A'-1;
            oriY = -1;
            previousX = 'A'-1;
            previousY = -1;
            anAI.score++;
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship sank" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship sank" << std::endl << std::endl;
            }
        }
        else {
            if (!found){
                // init the values to shearch the boat
                found = true;
                dir = 'N';
                oriX = x;
                oriY = y;
                previousX = x;
                previousY = y;
            }
            else{
                previousX = x;
                previousY = y;
            }
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship Hit" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship Hit" << std::endl << std::endl;
            }

        }
    }
    else{
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anAI);
        displayGrid(aPlayer, anAI);
        std::cout << std::endl;
        std::cout << "AI shoot in " << x << y << std::endl << std::endl;
        std::cout << "Miss" << std::endl << std::endl;
        if (saving){
            saveFile << "AI shoot in " << x << y << std::endl;
            saveFile << "Miss" << std::endl << std::endl;
        }
        if (found){
            if (oriDir != 'N'){
                switch (dir) {
                case 'H':
                    dir = 'h';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'V':
                    dir = 'v';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'h':
                    dir = 'H';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'v':
                    dir = 'V';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'N':
                    break;
                }
            }
            else{
                dir = 'N';
            }

        }
    }
}

void AICrossShoot(Player &anAI, Player &aPlayer, char& currentX, int& currentY, bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY, bool saving, ofstream &saveFile){
    char x;
    int y;
    Coordinate coordi;
    char oriDir = dir;
    if (!found){
        if (currentY != -1){
            do {
                currentX += 2;
                if (currentX - 'A' +1 > GRIDSIZE-2){
                    currentX = 'A' + (('A'+(GRIDSIZE-2))-currentX)+1;
                    currentY++;
                }
                x = currentX;
                y = currentY;
                coordi = {x, y};
            }while (alreadyShot(aPlayer.grid, coordi));
        }
        else{
            currentX = 'A';
            currentY = 1;
            x = 'A';
            y = 1;
            coordi = {x, y};
        }
    }
    else{
        switch (dir) {
        /* N for None the dirrection is not ditermined yet
         * H for horizontal
         * h for horizontal reverse
         * V for vertical
         * v for vertical reverse
         */
        case 'N':
            do {
                int currentDir = randomIntBetween(1,4);
                switch (currentDir) {
                case 1:
                    x = previousX+1;
                    y = previousY;
                    coordi = {x, y};
                    dir = 'H';
                    break;
                case 2:
                    x = previousX-1;
                    y = previousY;
                    coordi = {x, y};
                    dir = 'h';
                    break;
                case 3:
                    x = previousX;
                    y = previousY+1;
                    coordi = {x, y};
                    dir = 'V';
                    break;
                case 4:
                    x = previousX;
                    y = previousY-1;
                    coordi = {x, y};
                    dir = 'v';
                    break;
                }
            }while (alreadyShot(aPlayer.grid, coordi) or x-'A'<0 or x-'A'+1 > GRIDSIZE-2 or y < 1 or y > GRIDSIZE-2);
            break;
        case 'H':
            x = previousX + 1;
            y = previousY;
            coordi = {x, y};
            if (x-'A'+1 > GRIDSIZE-2 or alreadyShot(aPlayer.grid, coordi)){
                x = oriX-1;
                coordi = {x, y};
                dir = 'h';
            }
            break;
        case 'h':
            x = previousX - 1;
            y = previousY;
            coordi = {x, y};
            if (x-'A'+1 < 1 or alreadyShot(aPlayer.grid, coordi)){
                x = oriX+1;
                coordi = {x, y};
                dir = 'H';
            }
            break;
        case 'V':
            x = previousX;
            y = previousY + 1;
            coordi = {x, y};
            if (y > GRIDSIZE-2 or alreadyShot(aPlayer.grid, coordi)){
                y = oriY-1;
                coordi = {x, y};
                dir = 'v';
            }
            break;
        case 'v':
            x = previousX;
            y = previousY - 1;
            coordi = {x, y};
            if (y < 1 or alreadyShot(aPlayer.grid, coordi)){
                y = oriY+1;
                coordi = {x, y};
                dir = 'V';
            }
            break;
        }
    }
    if (hitOrMiss(aPlayer.grid, coordi)){
        if (isBoatSank(aPlayer.grid, y, x-'A'+1)){
            // if boat sank reinit the values
            found = false;
            oriX = 'A'-1;
            oriY = -1;
            previousX = 'A'-1;
            previousY = -1;
            anAI.score++;
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship Sank" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship Sank" << std::endl << std::endl;
            }
        }
        else {
            if (!found){
                // init the values to shearch the boat
                found = true;
                dir = 'N';
                oriX = x;
                oriY = y;
                previousX = x;
                previousY = y;
            }
            else{
                previousX = x;
                previousY = y;
            }
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anAI);
            displayGrid(aPlayer, anAI);
            std::cout << std::endl;
            std::cout << "AI shoot in " << x << y << std::endl << std::endl;
            std::cout << "Ship Hit" << std::endl << std::endl;
            if (saving){
                saveFile << "AI shoot in " << x << y << std::endl;
                saveFile << "Ship Hit" << std::endl << std::endl;
            }

        }
    }
    else{
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anAI);
        displayGrid(aPlayer, anAI);
        std::cout << std::endl;
        std::cout << "AI shoot in " << x << y << std::endl << std::endl;
        std::cout << "Miss" << std::endl << std::endl;
        if (saving){
            saveFile << "AI shoot in " << x << y << std::endl;
            saveFile << "Miss" << std::endl << std::endl;
        }
        if (found){
            if (oriDir != 'N'){
                switch (dir) {
                case 'H':
                    dir = 'h';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'V':
                    dir = 'v';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'h':
                    dir = 'H';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'v':
                    dir = 'V';
                    previousX = oriX;
                    previousY = oriY;
                    break;
                case 'N':
                    break;
                }
            }
            else{
                dir = 'N';
            }

        }
    }
}
