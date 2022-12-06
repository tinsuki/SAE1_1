/* BATTLE SHIP for SAE1.1
 * file : /home/tinsuki/SAE1_1/main.cpp
 * by SIMON Kevin GPA1 1st year student
 * a Battle-ship game in cpp for two player */

#include <limits>
#include "functions.h"
#include "typeDef.h"
#include "test.h"
#include "AI.h"

int main() {
    std::string entry;
    if (OS == 0){ // test if the clearScreen function will work depending on the os
        std::cout << "votre systeme d'exploitation n'est pas pris en charge, ce jeu fonctionne sous \nwindows 32/64bits, linux ou mac" << std::endl;
        return 1;
    }
    // init the variables for player/s choices
    int playingMode;
    int shootMode;
    int tests;
    // display title screen and wait for input
    titleScreen();
    std::cin.clear();
    std::cin.get();

    // ask if player want to test the game
    clearScreen();
    displayTestsMenu();
    while(!(std::cin >> tests) or tests < 1 or tests > 2){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displayTestsMenu();
    }

    // do the tests if the player want
    if (tests == 1){
        clearScreen();
        test_structureDonnees();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_checkCoordinate();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_initializeGrid();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_placeShip();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_aleadyShot();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_hitOrMiss();
        std::cout << "Press enter to continue.";
        cin.get();
        clearScreen();
        test_isBoatSank();
        std::cout << "Press enter to continue.";
        cin.get();
    }

    // ask if there is one or two player and the difficulty of the AI if there is only one player
    do{
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displayPlayingMenu();
    }while(!(std::cin >> playingMode) or playingMode < 1 or playingMode > 4);

    // ask if the player/s want only one or three shot/s per turn
    do{
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clearScreen();
        displayShootMenu();
    }while(!(std::cin >> shootMode) or shootMode < 1 or shootMode > 2);

    // init the variables to play
    Player player1, player2;
    initializeGrid(player1.grid);
    initializeGrid(player2.grid);
    player1.score = 0;
    player2.score = 0;
    int playerIndice = randomIntBetween(0, 1);
    int shotLeft = 3;
    bool AIFound = false;
    char AIDir = 'N';
    char AIPreviousX = 'A'-1;
    int AIPreviousY = -1;
    char AIOriX = 'A'-1;
    int AIOriY = -1;
    char AICurrentX = 'A'-1;
    int AICurrentY = -1;

    // if there is two players ask for there names and if they want or not to place ther ships (random placement)
    if (playingMode == 1){
        askPlayersNames(player1, player2);
        clearScreen();
        displayTitle();
        std::cout<< std::endl << std::endl;

        // ask if player want to place his ships or not
        char isRandomPlacement;
        std::cout << player1.name << " would you like a random placement for your ship? (Y/N/y/n) : ";
        while (!(cin >> isRandomPlacement) and !(isRandomPlacement == 'Y' or isRandomPlacement == 'y' or isRandomPlacement == 'N' or isRandomPlacement == 'n')){
            std::cin.clear();
            std::cin.ignore();
            clearScreen();
            displayTitle();
            std::cout<< std::endl << std::endl;
            std::cout << "Invalid Entry." << std::endl;
            std::cout << player1.name << " would you like a random placement for your ship? (Y/N/y/n) : ";
        }
        if (isRandomPlacement == 'Y' or isRandomPlacement == 'y'){
            randomPlacement(player1);
        }
        else {
            askPlayerToPlace(player1, player2);
        }

        // ask if player want to place his ships or not
        clearScreen();
        displayTitle();
        std::cout << player2.name << "Would you like a random placement for your ship? (Y/N/y/n) : ";
        while (!(cin >> isRandomPlacement) and !(isRandomPlacement == 'Y' or isRandomPlacement == 'y' or isRandomPlacement == 'N' or isRandomPlacement == 'n')){
            std::cin.clear();
            std::cin.ignore();
            clearScreen();
            displayTitle();
            std::cout<< std::endl << std::endl;
            std::cout << "Invalid Entry." << std::endl;
            std::cout << player2.name << "Would you like a random placement for your ship? (Y/N/y/n) : ";
        }
        if (isRandomPlacement == 'Y' or isRandomPlacement == 'y'){
            randomPlacement(player2);
        }
        else {
            askPlayerToPlace(player2, player1);
        }
        clearScreen();
    }

    // if there is an AI init the variable player2 as the AI
    if (playingMode > 1){
        clearScreen();
        displayTitle();
        askPlayerName(player1);
        player2.name = "AI";

        // ask if player want to place his ships or not
        clearScreen();
        displayTitle();
        char isRandomPlacement;
        std::cout << player1.name << " would you like a random placement for your ship? (Y/N/y/n) : ";
        while (!(cin >> isRandomPlacement) and !(isRandomPlacement == 'Y' or isRandomPlacement == 'y' or isRandomPlacement == 'N' or isRandomPlacement == 'n')){
            std::cin.clear();
            std::cin.ignore();
            clearScreen();
            displayTitle();
            std::cout<< std::endl << std::endl;
            std::cout << "Invalid Entry." << std::endl;
            std::cout << player1.name << " would you like a random placement for your ship? (Y/N/y/n) : ";
        }
        if (isRandomPlacement == 'Y' or isRandomPlacement == 'y'){
            randomPlacement(player1);
        }
        else {
            askPlayerToPlace(player1, player2);
        }
        randomPlacement(player2);
    }
    // init variable for the game loop
    Player playerList[2] = {player1, player2};
    clearScreen();
    displayTitle();
    std::cout << std::endl << std::endl << "The first player is " << playerList[playerIndice].name << std::endl;
    std::cout << "Press Enter to continu." << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();

    // game loop
    do{
        clearScreen();
        switch (playingMode) {
        case 1:
            askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice]);
            if (shootMode == 2){
                shotLeft -= 1;
                if (shotLeft < 1){
                    shotLeft = 3;
                    playerIndice = 1 - playerIndice;
                }
            }
            else {
                playerIndice = 1 - playerIndice;
            }
            std::cout << "Press Enter to continu." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;
        case 2:
            if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice]);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            else {
                displayTitle();
                displayPlayerNames(playerList[0], playerList[1]);
                displayGrid(playerList[0], playerList[1]);
                AIRandomShoot(playerList[0].grid, playerList[1]);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.get();
            }
            if (shootMode == 2){
                shotLeft -= 1;
                if (shotLeft < 1){
                    shotLeft = 3;
                    playerIndice = 1 - playerIndice;
                }
            }
            else {
                playerIndice = 1 - playerIndice;
            }
            break;
        case 3:
             if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice]);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            else {
                displayTitle();
                displayPlayerNames(playerList[0], playerList[1]);
                displayGrid(playerList[0], playerList[1]);
                AIOptimisedShoot(playerList[playerIndice], playerList[1-playerIndice].grid, AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.get();
            }
            if (shootMode == 2){
                shotLeft -= 1;
                if (shotLeft < 1){
                    shotLeft = 3;
                    playerIndice = 1 - playerIndice;
                }
            }
            else {
                playerIndice = 1 - playerIndice;
            }
            break;
        case 4:
            if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice]);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            else {
                displayTitle();
                displayPlayerNames(playerList[0], playerList[1]);
                displayGrid(playerList[0], playerList[1]);
                AICrossShoot(playerList[playerIndice], playerList[1-playerIndice].grid, AICurrentX, AICurrentY, AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY);
                std::cout << "Press Enter to continu." << std::endl;
                std::cin.get();
            }
            if (shootMode == 2){
                shotLeft -= 1;
                if (shotLeft < 1){
                    shotLeft = 3;
                    playerIndice = 1 - playerIndice;
                }
            }
            else {
                playerIndice = 1 - playerIndice;
            }
            break;
        default:
            break;
        }
    }while (playerList[0].score < NBSHIPS and playerList[1].score  < NBSHIPS);
    if (playerList[0].score == NBSHIPS) {
        displayWin(playerList[0]);
    }
    else{
        displayWin(playerList[1]);
    }
    return 0;
}
