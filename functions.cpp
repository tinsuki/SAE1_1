#ifdef __WIN32
#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
#include "functions.h"
#include <stdio.h>

void displayTitle(){
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

void displayPlayerNames(Player& player1, Player& player2){
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
    clearScreen();
    displayTitle();
    std::cout << "Joueur n 1 :" << std::endl;
    askPlayerName(aPlayer);
    clearScreen();
    displayTitle();
    std::cout << "Joueur n 2 :" << std::endl;
    askPlayerName(anOpponent);
}

void initializeGrid(Cell aGrid[][MYSIZE]){
    // travel the 2d grid
    for (int iRow = 0; iRow < MYSIZE; iRow++){
        for (int iCol = 0; iCol < MYSIZE; iCol++){
            // set the cell at ship = none and state = unshot
            aGrid[iRow][iCol] = {NONE, UNSHOT} ;
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
    for (int iRow = 1; iRow < MYSIZE-1; iRow++){
        if (iRow < 10){
            std::cout << " " << iRow << " ";
        }
        else {
            std::cout << iRow << " ";
        }
        for (int iCol = 1; iCol < MYSIZE-1; iCol++){
            Ship playerShip = aPlayer.grid[iRow][iCol].ship;
            if (playerShip != NONE){
                State state = aPlayer.grid[iRow][iCol].state;
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
            #ifdef __WIN32
            SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
            std::cout << playerShip << "  ";
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
        for (int iCol = 1; iCol < MYSIZE-1; iCol++){
            State state = anOpponent.grid[iRow][iCol].state;
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
    if ((aLetter >= 'a' and aLetter < 'a'+MYSIZE-2) or (aLetter >= 'A' and aLetter < 'A'+MYSIZE-2)){
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
    toUpper(letter);
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
    if (number < 1 or number > MYSIZE-2){

        return false;
    }
    sommeCoordi = {letter, number};
    return true;
}

void clearScreen(){
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
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);
    int number = distr(eng);
    return number;
}

bool checkDirection(Cell grid[][MYSIZE], Ship ship, Coordinate coord, char dir){
    int row = coord.row;
    int col = coord.col+1 - 'A';
    if (row < 0 or row > MYSIZE-2 or col < 0 or col > MYSIZE-2){
        return false;
    }
    if (dir == 'h' or dir == 'H'){
        for (int decalX = -1; decalX < ship+2; decalX++){
            for (int decalY = -1; decalY < 2; decalY++){
                if (col+decalX < 0 or col+decalX > MYSIZE-1){
                    return false;
                }
                if (row+decalY < 0 or row+decalY > MYSIZE-1){
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
                if (col+decalX < 0 or col+decalX > MYSIZE-1){
                    return false;
                }
                if (row+decalY < 0 or row+decalY > MYSIZE){
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

bool placeShip(Cell grid[][MYSIZE], Placement place, Ship ship){
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
                std::cout << "Placement impossible veulliez entrer des coordonées et une direction valide" << std::endl;
            }
        }

    }
}

bool alreadyShot(Cell aGrid[][MYSIZE], Coordinate someCoordi){
    int row = someCoordi.row;
    int col = someCoordi.col - 'A' +1;
    if (aGrid[row][col].state == UNSHOT){
        return false;
    }
    return true;
}

bool hitOrMiss(Cell aGrid[][MYSIZE], Coordinate someCoordi){
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

bool isBoatSank(Cell aGrid[][MYSIZE], int aRow, int aCol){
    int found = 1;
    int x = aCol;
    int y = aRow;
    char dir;
    int decalX = 0;
    int decalY = 0;
    Ship ship = aGrid[aRow][aCol].ship;
    int shipCoordi[ship][2] = {{x,y}};
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
            if (x+decalX > 0 and x+decalX < MYSIZE and aGrid[y][x+decalX].ship == ship){
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
            if (x+decalX > 0 and x+decalX < MYSIZE and aGrid[y][x+decalX].ship == ship){
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
            if (y+decalY > 0 and y+decalY < MYSIZE and aGrid[y+decalY][x].ship == ship){
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
            if (y+decalY > 0 and y+decalY < MYSIZE and aGrid[y+decalY][x].ship == ship){
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
    Coordinate coordi;
    char dir;
    Placement place;
    bool error = false;
    for (int nbShip = 0; nbShip < NBSHIPS; nbShip++){
        error = false;
        while (!error){
            coordi.row = randomIntBetween(1, MYSIZE-2);
            coordi.col = randomIntBetween(1, MYSIZE-2)+'A'-1;
            dir = randomIntBetween(0,1)==0? 'H':'V';
            place = {coordi, dir};
            error = placeShip(aPlayer.grid, place, nbShipToShip(nbShip));
        }
    }
}

void centerDisplay(std::string aText){
    int nbSpace = (80 - aText.length())/2;
    for (int  i = 0; i < nbSpace; i++){
        std::cout << " ";
    }
    std::cout << aText << std::endl;
}

void displayPlayingMenu(){
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
    centerDisplay("Playing Modes :");
    centerDisplay("1 - 2 Players");
    centerDisplay("2 - AI Easy mode");
    centerDisplay("3 - AI Normal mode");
    centerDisplay("4 - AI Difficult mode");
    std::cout << std::endl;
    std::cout << "Enter your playing mode here : ";
}

void displayShootMenu(){
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
    centerDisplay("Shoot Modes :");
    centerDisplay("1 - One Shot");
    centerDisplay("2 - Three Shots in a row");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your playing mode here : ";
}

void askPlayerToShot(Player& aPlayer, Player& anOpponent){
    std::string inputCoordi;
    Coordinate coordi;
    displayTitle();
    displayPlayerNames(aPlayer, anOpponent);
    displayGrid(aPlayer, anOpponent);
    std::cout << aPlayer.name << " ou voulez-vous tirer ? (exemple C6): ";
    while(!(std::cin >> inputCoordi) or !checkCoordinate(inputCoordi, coordi) or alreadyShot(anOpponent.grid, coordi)
          ){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Coordonnees invalides." << std::endl;
        std::cout << aPlayer.name << " ou voulez-vous tirer ? (exemple C6): ";
    }
    clearScreen();
    displayTitle();
    displayPlayerNames(aPlayer, anOpponent);
    displayGrid(aPlayer, anOpponent);
    std::cout << aPlayer.name << " tir en" << inputCoordi << std::endl;
    if (hitOrMiss(anOpponent.grid, coordi)){
        if (isBoatSank(anOpponent.grid, coordi.row, coordi.col-'A'+1)){
            std::cout << "Navire coule" << std::endl;
            aPlayer.score++;
        }
        else{
            std::cout << "Navire touche" << std::endl;
        }
    }
    else{
        std::cout << "Plouf" << std::endl;
    }
}

void displayTestsMenu(){
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
    centerDisplay("Do you want to execute the tests ? :");
    centerDisplay("1 - Yes");
    centerDisplay("2 - No");
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Enter youre answer here : ";
}

void displayWin(Player aPlayer){
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
    centerDisplay("The Winner of the BattleShip is");
    std::cout << std::endl;
    centerDisplay(aPlayer.name);
}
