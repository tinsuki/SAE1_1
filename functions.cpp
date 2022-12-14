#ifdef __WIN32
// if the os is windows include a library to change the color of the text in console
#include <windows.h>
// create the variable to change the color of text in the console
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
#include "functions.h"

void displayTitle(){
    // change the color system when compile depending on the os
    #ifdef __WIN32
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "          __                  ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    std::cout << "~~~~~~~~~~~~~~~~~~~~                  ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "__" << std::endl;
    std::cout << "        _|  |_______          ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    std::cout << "~~  BATTLE  SHIP  ~~          ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout<<  "_______|  |_" << std::endl;
    std::cout << "        \\          /          ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    std::cout << "~~~   By Kevin   ~~~          ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "\\          /" << std::endl;
    std::cout << "     ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
    std::cout << "~~~~~~~~~~~~~~~~~~~~     ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
    std::cout << "~~~~~~~~~~~~~~~~~~~~     ";
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
    std::cout << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << std::endl;
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    #endif
    #ifndef __WIN32
    std::cout << "          __                  \033[31m~~~~~~~~~~~~~~~~~~~~                  \033[0m__" << std::endl;
    std::cout << "        _|  |_______          \033[31m~~  BATTLE  SHIP  ~~          \033[0m_______|  |_" << std::endl;
    std::cout << "        \\          /          \033[31m~~~   By Kevin   ~~~          \033[0m\\          /" << std::endl;
    std::cout << "     \033[34m~~~~~~~~~~~~~~~~~~~~     \033[31m~~~~~~~~~~~~~~~~~~~~     \033[34m~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "\033[0m"<< std::endl;
    #endif
}

void titleScreen(){
    std::cout << "  888               888    888    888                   888      d8b" << std::endl;
    std::cout << "  888               888    888    888                   888      Y8P" << std::endl;
    std::cout << "  888               888    888    888                   888" << std::endl;
    std::cout << "  88888b.   8888b.  888888 888888 888  .d88b.  .d8888b  88888b.  888 888888b." << std::endl;
    std::cout << "  888 \"88b     \"88b 888    888    888 d8P  Y8b 88K      888 \"88b 888 8888 \"88b" << std::endl;
    std::cout << "  888  888. d888888 888    888    888 88888888 \"Y8888b. 888  888 888 8888  888" << std::endl;
    std::cout << "  888 d88P8 88  888 Y88b.  Y88b.  888 Y8b.          X88 888  888 888 8888 d88P" << std::endl;
    std::cout << "  88888P\"\"  Y888888  \"Y888  \"Y888 888  \"Y8888  d88888P' 888  888 888 888888P\"" << std::endl;
    std::cout << "                                                                     888" << std::endl;
    std::cout << "                                                 _.                  888" << std::endl;
    std::cout << "                                             _.-' |                  888" << std::endl;
    std::cout << "                                         _.-'     |" << std::endl;
    std::cout << "                                     _.-'         |" << std::endl;
    std::cout << "                                 _.-'           __|_________" << std::endl;
    std::cout << "                             _.-'              |           _|" << std::endl;
    std::cout << "                         _.-'                  |          |     " << std::endl;
    std::cout << "                     _.-'                      L|         |    .----._____   /|" << std::endl;
    std::cout << "  ;  ____.---.      |                           |         |   /|    ;\"\"     //|" << std::endl;
    std::cout << "  :\\   \"\":   |\\     |                         __|_________|__/_|____:______//_o" << std::endl;
    std::cout << "  : \\____;___|_\\____|________________________/                                ;" << std::endl;
    std::cout << "  |                                                                          ;" << std::endl;
    std::cout << "  |  by Kevin           press enter to start                     * * * *    ;" << std::endl;
    std::cout << "  |________________________________________________________________________'" << std::endl;
}

void displayBattleShip(){
    // change the color system when compile depending on the os
    #ifdef __WIN32
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
    #endif
    #ifndef __WIN32
    std::cout << "\033[34m";
    #endif
    std::cout << "  888               888    888    888                   888      d8b" << std::endl;
    std::cout << "  888               888    888    888                   888      Y8P" << std::endl;
    std::cout << "  888               888    888    888                   888" << std::endl;
    std::cout << "  88888b.   8888b.  888888 888888 888  .d88b.  .d8888b  88888b.  888 888888b." << std::endl;
    std::cout << "  888 \"88b     \"88b 888    888    888 d8P  Y8b 88K      888 \"88b 888 8888 \"88b" << std::endl;
    std::cout << "  888  888. d888888 888    888    888 88888888 \"Y8888b. 888  888 888 8888  888" << std::endl;
    std::cout << "  888 d88P8 88  888 Y88b.  Y88b.  888 Y8b.          X88 888  888 888 8888 d88P" << std::endl;
    std::cout << "  88888P\"\"  Y888888  \"Y888  \"Y888 888  \"Y8888  d88888P' 888  888 888 888888P\"" << std::endl;
    std::cout << "                                                                     888" << std::endl;
    std::cout << "                                                                     888" << std::endl;
    std::cout << "                                                                     888" << std::endl;
    std::cout << std::endl;
    #ifdef __WIN32
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    #endif
    #ifndef __WIN32
    std::cout << "\033[0m";
    #endif
}

void displayPlayerNames(Player& player1, Player& player2){
    // calculate the number of space to display to center the players names
    int nbSpaceP1 = 31 - player1.name.length();
    int nbSpaceP2 = 31 - player2.name.length();
    std::string toDisplay = "";
    for (int i = 0; i < nbSpaceP1/2; i++){
        toDisplay += " ";
    }
    toDisplay += player1.name;
    if (nbSpaceP1%2 != 0){
        toDisplay += " ";
    }
    for (int i = 0; i < 9+nbSpaceP1/2; i++){
        toDisplay += " ";
    }
    for (int i = 0; i < 9+nbSpaceP2/2; i++){
        toDisplay += " ";
    }
    toDisplay +=  player2.name;
    std::cout << toDisplay << std::endl << std::endl;
}

void askPlayerName(Player& aPlayer){
    // ask for player name while the input is not good
    std::string name;
    std::cout << "Entrez le nom du joueur (40 char max) : ";
    while(!(std::cin >> name) || name.length() > 40){
        std::cin.ignore();
        std::cin.clear();
        std::cout << "Entree invalide, entrez le nom du joueur (40 char max) : ";
    }
    aPlayer.name = name;
}

void askPlayersNames(Player& aPlayer, Player& anOpponent){
    // ask for players names using askPLayerName function
    clearScreen();
    displayTitle();
    std::cout << "Joueur n 1 :" << std::endl;
    askPlayerName(aPlayer);
    clearScreen();
    displayTitle();
    std::cout << "Joueur n 2 :" << std::endl;
    askPlayerName(anOpponent);
}

void initializeGrid(Cell aGrid[][GRIDSIZE]){
    // travel the 2d grid
    for (int iRow = 0; iRow < GRIDSIZE; iRow++){
        for (int iCol = 0; iCol < GRIDSIZE; iCol++){
            // set the cell at ship = none and state = unshot
            aGrid[iRow][iCol] = {NONE, UNSHOT};
        }
    }
}

void displayGrid(Player& aPlayer, Player& anOpponent) {
    // display the letters for the two players
    std::cout << "   ";
    for (int i = 65; i < 75; i++) {
        std::cout << char(i) << "  ";
    }
    for (int i = 0; i < 14; i++) {
        std::cout << " ";
    }
    std::cout << "   ";
    for (int i = 65; i < 75; i++) {
        std::cout << char(i) << "  ";
    }
    std::cout << std::endl;
    // display the grids and the index (1, 2, 3, ...) for the two players by concatenating players lines
    for (int iRow = 1; iRow < GRIDSIZE-1; iRow++){
        if (iRow < 10){
            std::cout << " " << iRow << " ";
        }
        else {
            std::cout << iRow << " ";
        }
        for (int iCol = 1; iCol < GRIDSIZE-1; iCol++){
            Ship playerShip = aPlayer.grid[iRow][iCol].ship;
            State state = aPlayer.grid[iRow][iCol].state;
            if (playerShip != NONE){
                // if there is a ship display the number of the ship with color depending of the state
                switch (state) {
                case UNSHOT:
                    #ifdef __WIN32
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
                    std::cout << playerShip << "  ";
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                    #endif
                    #ifndef __WIN32
                    std::cout << "\033[32m" << playerShip << "  \033[0m";
                    #endif
                    break;
                case MISS:
                    #ifdef __WIN32
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
                    std::cout << playerShip << "  ";
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                    #endif
                    #ifndef __WIN32
                    std::cout << "\033[32m" << playerShip << "  \033[0m";
                    #endif
                    break;
                case HIT:
                    #ifdef __WIN32
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED);
                    std::cout << playerShip << "  ";
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                    #endif
                    #ifndef __WIN32
                    std::cout << "\033[33m" << playerShip << "  \033[0m";
                    #endif
                    break;
                case SINK:
                    #ifdef __WIN32
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    std::cout << playerShip << "  ";
                    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                    #endif
                    #ifndef __WIN32
                    std::cout << "\033[31m" << playerShip << "  \033[0m";
                    #endif
                    break;
                default:
                    break;
                }
            }
            else{
                // if there is no ship, display the state in blue color
                #ifdef __WIN32
                SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                std::cout << char(state) << "  ";
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                #endif
                #ifndef __WIN32
                std::cout << "\033[34m" << playerShip << "  \033[0m";
                #endif
            }
        }
        for (int i = 0; i < 14; i++){
            std::cout << " ";
        }
        if (iRow < 10){
            std::cout << " " << iRow << " ";
        }
        else {
            std::cout << iRow << " ";
        }
        for (int iCol = 1; iCol < GRIDSIZE-1; iCol++){
            State state = anOpponent.grid[iRow][iCol].state;
            // display the state of the current cell with color depending on the state
            switch (state) {
            case UNSHOT:
                #ifdef __WIN32
                SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
                std::cout << char(state) << "  ";
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                #endif
                #ifndef __WIN32
                std::cout << "\033[34m" << char(state) << "  \033[0m";
                #endif
                break;
            case MISS:
                #ifdef __WIN32
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
                std::cout <<char(state) << "  ";
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                #endif
                #ifndef __WIN32
                std::cout << "\033[32m" << char(state) << "  \033[0m";
                #endif
                break;
            case HIT:
                #ifdef __WIN32
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED);
                std::cout << char(state) << "  ";
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                #endif
                #ifndef __WIN32
                std::cout << "\033[33m" << char(state) << "  \033[0m";
                #endif
                break;
            case SINK:
                #ifdef __WIN32
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                std::cout << char(state) << "  ";
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                #endif
                #ifndef __WIN32
                std::cout << "\033[31m" << char(state) << "  \033[0m";
                #endif
                break;
            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}



bool isGoodLetter(char aLetter){
    // verrify if the letter entered by the player is good for coordinates
    if ((aLetter >= 'a' and aLetter < 'a'+GRIDSIZE-2) or (aLetter >= 'A' and aLetter < 'A'+GRIDSIZE-2)){
        return true;
    }
    else{
        return false;
    }
}

bool isNumber(char aLetter){
    // verify if the player has entered a number for the coordinates
    if ((aLetter < '0') or (aLetter > '9')){
        return false;
    }
    return true;
}

void toUpper(char& aLetter){
    // change a char in uppercase if it is possible
    if (aLetter >= 'a' and aLetter <= 'z'){
        aLetter += 'A' - 'a';
    }
}

bool checkCoordinate(std::string aPlace, Coordinate& sommeCoordi){
    // coordinates have to be LetterNumber (B5 for example)
    if (aPlace.length() != 2 and aPlace.length() != 3){
        return false;
    }
    char letter = aPlace[0];
    if (!isGoodLetter(letter)){
        return false;
    }
    toUpper(letter); // set letter to uppercase if needed
    int number;
    if (aPlace.length() == 3){
        if (!isNumber(aPlace[1]) or !isNumber(aPlace[2])){
            return false;
        }
        number = (aPlace[1]-48)*10 + (aPlace[2]-48);
    }
    else{
        if (!isNumber(aPlace[1])){
            return false;
        }
        number = (aPlace[1]-48);
    }
    if (number < 1 or number > GRIDSIZE-2){

        return false;
    }
    sommeCoordi = {letter, number};
    return true;
}

void clearScreen(){
    // change the function depending on the os
    switch (OS) {
    case 1:
        system("cls");
        break;
    case 2:
        system("clear");
        system("clear");
        break;
    case 3:
        system("clear");
        break;
    default:
        std::cout << "systeme d'exploitation non pris en charge, ce jeu fonctionne sous:" << std::endl;
        std::cout << "    - windows 32 et 64 bits" << std::endl;
        std::cout << "    - mac" << std::endl;
        std::cout << "    - linux" << std::endl;
        std::cout << "Vous pourriez rencontrer plussieurs bugs." << std::endl;
        break;
    }
}

int randomIntBetween(int min, int max){
    // generate a random number between min and max
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);
    int number = distr(eng);
    return number;
}

bool checkDirection(Cell grid[][GRIDSIZE], Ship ship, Coordinate coord, char dir){
    // check if a ship can be place in a direction by checking if there isno ship next to it
    int row = coord.row;
    int col = coord.col+1 - 'A';
    if (row < 0 or row > GRIDSIZE-2 or col < 0 or col > GRIDSIZE-2){
        return false;
    }
    if (dir == 'h' or dir == 'H'){
        for (int decalX = -1; decalX < ship+2; decalX++){
            for (int decalY = -1; decalY < 2; decalY++){
                if (col+decalX < 0 or col+decalX > GRIDSIZE-1){
                    return false;
                }
                if (row+decalY < 0 or row+decalY > GRIDSIZE-1){
                    return false;
                }
                if (grid[row+decalY][col+decalX].ship != NONE){
                    return false;
                }
            }
        }
        return true;
    }
    if (dir == 'v' or dir == 'V'){
        for (int decalX = -1; decalX < 2; decalX++){
            for (int decalY = -1; decalY < ship+2; decalY++){
                if (col+decalX < 0 or col+decalX > GRIDSIZE-1){
                    return false;
                }
                if (row+decalY < 0 or row+decalY > GRIDSIZE){
                    return false;
                }
                if (grid[row+decalY][col+decalX].ship != NONE){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

bool placeShip(Cell grid[][GRIDSIZE], Placement place, Ship ship){
    // check if a ship can be place and place it if it can be
    if (checkDirection(grid, ship, place.coordi, place.dir) == true){
        int col = place.coordi.col - 'A';
        int row = place.coordi.row;
        for (int i = 1; i < ship+1; i++){
            if (place.dir == 'h' or place.dir == 'H'){
                grid[row][col+i].ship = ship;
            }
            else{
                grid[row+i-1][col+1].ship = ship;
            }
        }
        return true;
    }
    return false;
}

Ship nbShipToShip(int nbShip){
    // return a ship depending on the parameter
    switch (nbShip) {
    case 0:
        return TORPEDO;
        break;
    case 1:
        return SUBMARINE;
        break;
    case 2:
        return DESTROYER;
        break;
    case 3:
        return CRUISER;
        break;
    case 4:
        return CARRIER;
        break;
    default:
        return NONE;
        break;
    }
}

void askPlayerToPlace(Player & aPlayer, Player & anOpponent){
    // ask for player to place all his ships
    std::string inputCoordi;
    Coordinate coordi;
    char dir;
    Placement place;
    bool error = false;
    for (int nbShip = 0; nbShip < NBSHIPS; nbShip++){
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anOpponent);
        displayGrid(aPlayer, anOpponent);
        error = false;
        while (!error){
            std::cout << std::endl << "Placement du navire " << ships[NBSHIPS-nbShip-1] << " : " << std::endl;
            do{
                std::cout << "Ou voullez-vous placer le navire ? (exemple C6) :";
            }while (!(std::cin >> inputCoordi) || !(checkCoordinate(inputCoordi, coordi)));
            do{
                std::cout << "Dans quelle dirrection voullez-vous placer le navire ? (V/H) :";
            }while (!(std::cin >> dir) || (dir != 'V' && dir != 'H'));
            place = {coordi, dir};
            error = placeShip(aPlayer.grid, place, nbShipToShip(nbShip));
            if (!error){
                std::cout << "Placement impossible veulliez entrer des coordonees et une direction valide" << std::endl;
            }
        }

    }
}

bool alreadyShot(Cell aGrid[][GRIDSIZE], Coordinate someCoordi){
    // check if a cell state is unshot
    int row = someCoordi.row;
    int col = someCoordi.col - 'A' +1;
    if (aGrid[row][col].state == UNSHOT){
        return false;
    }
    return true;
}

bool hitOrMiss(Cell aGrid[][GRIDSIZE], Coordinate someCoordi){
    // return if a ship is hit or not
    int row = someCoordi.row;
    int col = someCoordi.col - 'A';
    if (aGrid[row][col+1].ship == NONE)
    {
        aGrid[row][col+1].state = MISS;
        return false;
    }
    else {
        aGrid[row][col+1].state = HIT;
        return true;
    }
}

bool isBoatSank(Cell aGrid[][GRIDSIZE], int aRow, int aCol){
    // find the ship and return if is sank or not
    int found = 1;
    int x = aCol;
    int y = aRow;
    char dir;
    int decalX = 0;
    int decalY = 0;
    Ship ship = aGrid[aRow][aCol].ship;
    int shipCoordi[MAXSHIPSIZE][2] = {{x,y}};
    State state = aGrid[aRow][aCol].state;
    if (ship == NONE or state == MISS){
        return false;
    }
    if (aGrid[y][x-1].ship == ship){
        dir = 'h';
        decalX = -1;
    }
    else if (aGrid[y][x+1].ship == ship){
        dir = 'H';
        decalX = 1;
    }
    else if (aGrid[y+1][x].ship == ship){
        dir = 'V';
        decalY = 1;
    }
    else if (aGrid[y-1][x].ship == ship){
        dir = 'v';
        decalY = -1;
    }
    else {
        return false;
    }
    while (found != ship){
        if (dir == 'H'){
            if (x+decalX > 0 and x+decalX < GRIDSIZE and aGrid[y][x+decalX].ship == ship){
                if (aGrid[y][x+decalX].state != HIT){
                    return false;
                }
                else{
                    shipCoordi[found][0] = x+decalX;
                    shipCoordi[found][1] = y;
                    found++;
                    decalX++;
                }
            }
            else {
                dir = 'h';
                decalX = -1;
            }
        }
        if (dir == 'h'){
            if (x+decalX > 0 and x+decalX < GRIDSIZE and aGrid[y][x+decalX].ship == ship){
                if (aGrid[y][x+decalX].state != HIT){
                    return false;
                }
                else{
                    shipCoordi[found][0] = x+decalX;
                    shipCoordi[found][1] = y;
                    found++;
                    decalX--;
                }
            }
            else{
                dir = 'H';
                decalX = 1;
            }
        }
        if (dir == 'V'){
            if (y+decalY > 0 and y+decalY < GRIDSIZE and aGrid[y+decalY][x].ship == ship){
                if (aGrid[y+decalY][x].state != HIT){
                    return false;
                }
                else{
                    shipCoordi[found][0] = x;
                    shipCoordi[found][1] = y+decalY;
                    found++;
                    decalY++;
                }
            }
            else {
                dir = 'v';
                decalY = -1;
            }
        }
        if (dir == 'v'){
            if (y+decalY > 0 and y+decalY < GRIDSIZE and aGrid[y+decalY][x].ship == ship){
                if (aGrid[y+decalY][x].state != HIT){
                    return false;
                }
                else{
                    shipCoordi[found][0] = x;
                    shipCoordi[found][1] = y+decalY;
                    found++;
                    decalY--;
                }
            }
            else {
                dir = 'V';
                decalX = 1;
            }
        }
    }
    for (int i = 0; i < ship; i++){
        int x = shipCoordi[i][0];
        int y = shipCoordi[i][1];
        aGrid[y][x].state = SINK;
    }
    return true;
}


void randomPlacement(Player& aPlayer){
    // place all player ship randomly
    Coordinate coordi;
    char dir;
    Placement place;
    bool error = false;
    for (int nbShip = 0; nbShip < NBSHIPS; nbShip++){
        error = false;
        while (!error){
            coordi.row = randomIntBetween(1, GRIDSIZE-2);
            coordi.col = randomIntBetween(1, GRIDSIZE-2)+'A'-1;
            dir = randomIntBetween(0,1)==0? 'H':'V';
            place = {coordi, dir};
            error = placeShip(aPlayer.grid, place, nbShipToShip(nbShip));
        }
    }
}

void centerDisplay(std::string aText){
    // center the text passed in parameter
    int nbSpace = (80 - aText.length())/2;
    for (int  i = 0; i < nbSpace; i++){
        std::cout << " ";
    }
    std::cout << aText << std::endl;
}

void displayPlayingMenu(){
    displayBattleShip();
    centerDisplay("Playing Modes :");
    centerDisplay("1 - 2 Players");
    centerDisplay("2 - AI Easy mode");
    centerDisplay("3 - AI Normal mode");
    centerDisplay("4 - AI Difficult mode");
    std::cout << std::endl;
    std::cout << "Enter your playing mode here : ";
}

void displayShootMenu(){
    displayBattleShip();
    centerDisplay("Shoot Modes :");
    centerDisplay("1 - One Shot");
    centerDisplay("2 - Three Shots in a row");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your playing mode here : ";
}

void askPlayerToShot(Player& aPlayer, Player& anOpponent, bool saving, ofstream &saveFile){
    std::string inputCoordi;
    Coordinate coordi;
    displayTitle();
    displayPlayerNames(aPlayer, anOpponent);
    displayGrid(aPlayer, anOpponent);
    std::cout << std::endl;
    std::cout << aPlayer.name << " where do you want to shoot ? (example C6): ";
    while(!(std::cin >> inputCoordi) or !checkCoordinate(inputCoordi, coordi) or alreadyShot(anOpponent.grid, coordi)
          ){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anOpponent);
        displayGrid(aPlayer, anOpponent);
        std::cout << std::endl;
        std::cout << "Invalid coordinates." << std::endl;
        std::cout << aPlayer.name << " where do you want to shoot ? (example C6): ";
    }

    if (hitOrMiss(anOpponent.grid, coordi)){
        if (isBoatSank(anOpponent.grid, coordi.row, coordi.col-'A'+1)){
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anOpponent);
            displayGrid(aPlayer, anOpponent);
            std::cout << std::endl;
            std::cout << aPlayer.name << " shoot in " << inputCoordi << std::endl << std::endl;
            std::cout << "Ship sank" << std::endl << std::endl;
            if (saving){
                saveFile << aPlayer.name << " shoot in " << char(coordi.col) << coordi.row << std::endl;
                saveFile << "Ship sank" << std::endl;
            }
            aPlayer.score++;
        }
        else{
            clearScreen();
            displayTitle();
            displayPlayerNames(aPlayer, anOpponent);
            displayGrid(aPlayer, anOpponent);
            std::cout << std::endl << aPlayer.name << " shoot in " << inputCoordi << std::endl << std::endl;
            std::cout << "Ship hit" << std::endl << std::endl;
            if (saving){
                saveFile << aPlayer.name << " shoot in " << char(coordi.col) << coordi.row << std::endl;
                saveFile << "Ship hit" << endl;
            }
        }
    }
    else{
        clearScreen();
        displayTitle();
        displayPlayerNames(aPlayer, anOpponent);
        displayGrid(aPlayer, anOpponent);
        std::cout << std::endl << aPlayer.name << " shoot in " << inputCoordi << std::endl << std::endl;
        std::cout << "Miss" << std::endl << std::endl;
        if (saving){
            saveFile << aPlayer.name << " shoot in " << char(coordi.col) << coordi.row << std::endl;
            saveFile << "Miss" << std::endl << std::endl;
        }
    }
}

void displayTestsMenu(){
    displayBattleShip();
    centerDisplay("Do you want to execute the tests ? :");
    centerDisplay("1 - Yes");
    centerDisplay("2 - No");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter youre answer here : ";
}

void displayWin(Player aPlayer){
    displayBattleShip();
    centerDisplay("The Winner of the BattleShip is");
    std::cout << std::endl;
    centerDisplay(aPlayer.name);
}

void displayRules(){
    clearScreen();
    displayBattleShip();
    std::cout << "- You ave to place five ships of differents lengths (2, 3, 3, 4, 5)" << std::endl;
    std::cout << "- Each ship have to be place horizontaly or verticaly in a grid (10x10)" << std::endl;
    std::cout << "- You can not place two ships side by side" << std::endl;
    std::cout << "- During your turn you have to shoot somewhere in the grid to sink all the opponents ships" << std::endl;
    std::cout << "- The winner is the first to sink all the opponent ships" << std::endl;
    std::cout << std::endl << "Press Enter to continue" << std::endl;
}

void displayRulesMenu(){
    clearScreen();
    displayBattleShip();
    centerDisplay("Do you want to read the rules ?");
    std::cout << std::endl;
    centerDisplay("1 - Yes");
    centerDisplay("2 - No");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter youre answer here : ";
}

void displaySaveMenu(){
    clearScreen();
    displayBattleShip();
    centerDisplay("Do you want to this game ?");
    std::cout << std::endl;
    centerDisplay("Only the actions are saved and the last save is erased");
    std::cout << std::endl;
    centerDisplay("The save is the direcory where the project is build and is named save.txt");
    std::cout << std::endl;
    centerDisplay("1 - Yes");
    centerDisplay("2 - No");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter youre answer here : ";
}

void displaySaveImpossibleMenu(){
    clearScreen();
    displayBattleShip();
    centerDisplay("Save impossible do you want to continue ? :");
    std::cout << std::endl;
    std::cout << std::endl;
    centerDisplay("1 - Yes");
    centerDisplay("2 - No");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter youre answer here : ";
}
