/* BATTLE SHIP for SAE1.1
 * file : /home/tinsuki/SAE1_1/main.cpp
 * by SIMON Kevin GPA1 1st year student
 * a Battle-ship game in cpp for two or one player */

#include "functions.h"
#include "typeDef.h"
#include "test.h"
#include "AI.h"

int main() {
    if (OS == 0){ // test if the clearScreen function will work depending on the os
        std::cout << "votre systeme d'exploitation n'est pas pris en charge, ce jeu fonctionne sous \nwindows 32/64bits, linux ou mac" << std::endl;
        return 1;
    }
    // init the variables for player/s choices
    int playingMode;
    int shootMode;
    int tests;
    int rules;
    int save;
    bool saving;
    ofstream saveFile;
    // display title screen and wait for input
    titleScreen();
    std::cin.clear();
    std::cin.get();

    // ask if the player want to save the game actions
    clearScreen();
    displaySaveMenu();
    while(!(std::cin >> save) or save < 1 or save > 2){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displaySaveMenu();
    }

    // if the player/s want to save the game it save it in the dirrectory where the projec is build or the app is
    // exectuted and erase the existing save if exist and is named save.txt
    if (save == 1){
        saveFile.open("save.txt", ios::trunc);
        // if can't open the file, ask if player/s want to play
        if (!saveFile){
            clearScreen();
            displaySaveImpossibleMenu();
            while(!(std::cin >> save) or save < 1 or save > 2){
                std::cin.clear();
                std::cin.ignore();
                clearScreen();
                displaySaveMenu();
            }
            // if the player/s can't save and don't want to play stop the game
            if (save ==2){
                return 1;
            }

        }
        // if can save init the saving
        else{
            saving = true;
        }
    };

    // ask if player want to view the game rules
    clearScreen();
    displayRulesMenu();
    while(!(std::cin >> rules) or rules < 1 or rules > 2){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displayRulesMenu();
    }
    // if player/s want, display the rules of the battleship
    if (rules == 1){
        displayRules();
        std::cin.clear();
        std::cin.ignore();
        std::cin.get();
    }

    // ask if player/s want to test the game
    clearScreen();
    displayTestsMenu();
    while(!(std::cin >> tests) or tests < 1 or tests > 2){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        displayTestsMenu();
    }

    // do the tests if the player/s want
    if (tests == 1){
        clearScreen();
        test_structureDonnees();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_checkCoordinate();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_initializeGrid();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_placeShip();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_aleadyShot();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_hitOrMiss();
        std::cout << "Press enter to continue.";
        std::cin.clear();
        cin.get();
        clearScreen();
        test_isBoatSank();
        std::cout << "Press enter to continue.";
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
        std::cin.ignore();
        clearScreen();
        displayShootMenu();
    }while(!(std::cin >> shootMode) or shootMode < 1 or shootMode > 2);

    // init the variables to play
    Player player1, player2; // players
    initializeGrid(player1.grid); // player grid
    initializeGrid(player2.grid); // player grid
    player1.score = 0; // player score
    player2.score = 0; // player score
    int playerIndice = randomIntBetween(0, 1); // the first player
    int shotLeft = 3; // the number of shot allowed if there is three shot per turn
    bool AIFound = false; // AI
    char AIDir = 'N'; // AI
    char AIPreviousX = 'A'-1; // AI
    int AIPreviousY = -1; // AI
    char AIOriX = 'A'-1; // AI
    int AIOriY = -1; // AI
    char AICurrentX = 'A'-1; // AI
    int AICurrentY = -1; // AI

    // if there is two players ask for there names and if they want or not to place ther ships (random placement)
    if (playingMode == 1){
        askPlayersNames(player1, player2); // ask for players names
        clearScreen();
        displayTitle();
        std::cout<< std::endl << std::endl;

        // ask if player 1 want to place his ships or not
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

        // ask if player 2 want to place his ships or not
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
        askPlayerName(player1); // ask for player name
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

    // if save is enabled, enter the name of players in the save
    if (saving){
        saveFile << player1.name << "    |    " << player2.name << std::endl;
    }

    // init variable for the game loop
    Player playerList[2] = {player1, player2}; // this allow the random order of playing
    clearScreen();
    displayTitle();
    std::cout << std::endl << std::endl << "The first player is " << playerList[playerIndice].name << std::endl;
    std::cout << "Press Enter to continue." << std::endl;
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();

    // game loop
    do{
        clearScreen();
        switch (playingMode) {
        case 1:
            // ask player to shot
            askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice], saving, saveFile);
            // if there is three shoots count the shoots left
            if (shootMode == 2){
                shotLeft -= 1;
                if (shotLeft < 1){
                    // if there is no shoot left change the current player
                    shotLeft = 3;
                    playerIndice = 1 - playerIndice;
                }
            }
            else {
                // if there is only one shoot change the current player
                playerIndice = 1 - playerIndice;
            }
            std::cout << "Press Enter to continue." << std::endl;
            std::cin.ignore();
            std::cin.get();
            break;

        case 2:
            // if is player do the same as precedent
            if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice], saving, saveFile);
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            // if is the ai ask ai to shoot like the player but in random
            else {
                AIRandomShoot(playerList[0], playerList[1], saving , saveFile);
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.get();
            }
            // do the same as precedent
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
            // if it is player, ask to shoot
            if (playerList[playerIndice].name != "AI"){
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice], saving, saveFile);
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            else {
                // if it is ai ask ai to shoot in optimised mode
                displayTitle();
                displayPlayerNames(playerList[0], playerList[1]);
                displayGrid(playerList[0], playerList[1]);
                AIOptimisedShoot(playerList[playerIndice], playerList[1-playerIndice], AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY, saving, saveFile);
                std::cout << "Press Enter to continue." << std::endl;
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
                askPlayerToShot(playerList[playerIndice], playerList[1-playerIndice], saving, saveFile);
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore();
                std::cin.get();
            }
            // if it is ai, ask ai to shoot in cross mode
            else {
                displayTitle();
                displayPlayerNames(playerList[0], playerList[1]);
                displayGrid(playerList[0], playerList[1]);
                AICrossShoot(playerList[playerIndice], playerList[1-playerIndice], AICurrentX, AICurrentY, AIFound, AIDir, AIPreviousX, AIPreviousY, AIOriX, AIOriY, saving, saveFile);
                std::cout << "Press Enter to continue." << std::endl;
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
    // if a player score is equal to NBSHIPS stop the game
    }while (playerList[0].score < NBSHIPS and playerList[1].score  < NBSHIPS);
    clearScreen();
    // display wich player is the winner
    if (playerList[0].score == NBSHIPS) {
        displayWin(playerList[0]);
    }
    else{
        displayWin(playerList[1]);
    }
    return 0;
}
