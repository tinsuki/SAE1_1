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
    if (OS == 0){ // test if the clearScreen function will work depending on the os
        std::cout << "votre systeme d'exploitation n'est pas pris en charge, ce jeu fonctionne sous \nwindows 32/64bits, linux ou mac" << std::endl;
        return 1;
    }
    int playingMode;
    int shootMode;
    int tests;
    titleScreen();
    std::cin.get();
    do{
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clearScreen();
        displayTestsMenu();
    }while(!(std::cin >> tests) or tests < 1 or tests > 2);
    if (tests == 1){
        clearScreen();
        test_structureDonnees();
        std::cout << std::endl;
        test_checkCoordinate();
        std::cout << std::endl;
        test_initializeGrid();
        std::cout << std::endl;
        test_placeShip();
        std::cout << std::endl;
        test_aleadyShot();
        std::cout << std::endl;
        test_hitOrMiss();
        std::cout << std::endl;
        test_isBoatSank();
        std::cout << std::endl;
        std::cout << "Press enter to continu" << std::endl;
        std::cin.get();
    }
    do{
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        clearScreen();
        displayPlayingMenu();
    }while(!(std::cin >> playingMode) or playingMode < 1 or playingMode > 4);
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
    player2.score = 1;
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
    if (playingMode == 1){
        askPlayersNames(player1, player2);
        clearScreen();
        displayTitle();
        std::cout<< std::endl << std::endl;
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
    if (playingMode > 1){
        clearScreen();
        displayTitle();
        askPlayerName(player1);
        player2.name = "AI";
        askPlayerToPlace(player1, player2);
        randomPlacement(player2);
    }
    Player playerList[2] = {player1, player2};
    displayTitle();
    std::cout << std::endl << std::endl << "The first player is " << playerList[playerIndice].name << std::endl;
    std::cout << "Press Enter to continu." << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
    clearScreen();
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
            break;
        case 2:
            if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice]);
            }
            else {
                AIRandomShoot(playerList[1-playerIndice].grid, playerList[playerIndice]);
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
            }
            else {
                AIOptimisedShoot(playerList[playerIndice], playerList[1-playerIndice].grid, AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY);
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
            }
            else {
                AICrossShoot(playerList[playerIndice], playerList[1-playerIndice].grid, AICurrentX, AICurrentY, AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY);
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
        std::cout << "Press Enter to continu." << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin.get();
    }while ((playerList[0].score!= NBSHIPS+1) and (playerList[1].score != NBSHIPS+1));
    if (playerList[0].score == NBSHIPS) {
        displayWin(playerList[0]);
    }
    else{
        displayWin(playerList[1]);
    }
    return 0;
}
