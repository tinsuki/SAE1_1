#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "typeDef.h"

/*
 * \brief Display the Title and a Whaou efect
 * \return void
 */
void displayTitle();

/*
 * \brief display the title screen
 * \return void
 */
void titleScreen();

/*
 * \brief display the names of the two players centered to the grids
 * \param player1 : a player
 * \param player2 : a player or the AI
 * \return void
 */
void displayPlayerNames(Player& player1, Player& player2);
/*
 * \brief Initialise le tableau à vid
 * \param une grille
 * \return void
 */
void initializeGrid(Cell aGrid[][GRIDSIZE]);

/*
 * \brief Affiche les grilles des deux joueurs
 * \param aPlayer : le joueur
 * \param anOpponent l'adversaire
 * \return void
 */
void displayGrid(Player & aPlayer, Player & anOpponent);

/*
 * \brief Efface l'ecran après appui sur une touche et affiche
 * << BattleShip >> stylise avec votre nom
 * appel système de la commande console << cls >> voir
 * https://cplusplus.com/reference/cstdlib/system/
 * /!\ ne fonctionne que sous Windows
 * \return void
 */
void clearScreen();

/*
 * \brief Verifie les valeurs saisies pour initialiser les coordonnees
 * de placement des navires de guerre
 * \param aPlace : la saisie du joeur par exemple << b10 >>
 * \param someCoordi : les coordonnees valides stockees
 * \return true si les coordonnees sont valides, false sinon
 */
bool checkCoordinate(std::string aPlace, Coordinate & sommeCoordi);

/*
 * \brief place un navire dans la grille en verifiant les règles
 * \param aGrid : la grille du joueur
 * \param aPlace : les coordonnees et l'orientation du placement
 * \param aShip : le type de navire (donc sa taille)
 * \return true si le placement est valide et effectue, false sinon
 */
bool placeShip(Cell grid[][GRIDSIZE], Placement place, Ship ship);

/*
 * \brief demande au joueur de placer chaque navire, verifie les coordonnees
 * (checkCoordinnate) et affiche les grilles (displayGrid) des joueurs à chaque
 * placement (placeShip)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */
void askPlayerToPlace(Player & aPlayer, Player & anOpponent);

/* \brief indique si le coup a dejà ete tire
 * \param aGrid : la grille
 * \param someCoordi : les coordonnees du tir
 * \return true si le coup a dejà ete tire
 */
bool alreadyShot(Cell aGrid[][GRIDSIZE], Coordinate someCoordi);

/* \brief modifie l'etat d'une case de la grille de l'adversaire
 * selon le coup joue
 * \param aGrid : la grille
 * \param someCoordi : les coordonnees du tir
 * \return true si HIT
 */
bool hitOrMiss(Cell aGrid[][GRIDSIZE], Coordinate someCoordi);

/*
 * \brief affiche les grilles (displayGrid) des joueurs puis demande au joueur
 * les coordonnees du tir en verifiant les coordonnees (checkCoordinate) et si
 * elles n'ont pas dejà ete jouees (alreadyShot) puis affiche HIT or MISS
 * (hitOrMiss)
 * \param aPlayer : le joueur
 * \param anOpponent : l'adversaire
 * \return void
 */
void askPlayerToShot(Player& aPlayer, Player& anOpponent);

/*
 * \brief place tous les navires aleatoirement en respectant les règles
 * du jeu (placeShip)
 * \param aPlayer : le joueur avec sa grille
 * \return void
 */
void randomPlacement(Player& aPlayer);

/*
 * \brief determine si un bateau est coule (toutes ses cases sont HIT)
 * \param aGrid : la grille
 * \param aRow : la ligne
 * \param aCol : la colonne
 */
bool isBoatSank(Cell aGrid[][GRIDSIZE], int aRow, int aCol);

/*
 * \brief ask a player for is name and store it in player.name
 * \param aPlayer : the player
 * \return void
 */
void askPlayerName(Player& aPlayer);

/*
 * \brief ask two players for is name and store it in player.name
 * \param aPlayer : the player
 * \param anOpponeent : the second player
 * \return void
 */
void askPlayersNames(Player& aPlayer, Player& anOpponent);

/*
 * \brief generate a random integer between min and max (if min > max, min <- max and max <- min)
 * \param min : an integer
 * \param max : an interger
 * \return int
 */
int randomIntBetween(int min, int max);

/*
 * \brief check if a boat can be placed in a direction
 * \param ship : a ship
 * \param coord : coordinates to place the ship
 * \param dir : the direction to place the ship (h for horizontal and v for vertical)
 * \return bool
 */
bool checkDirection(Ship ship, Coordinate coord, char dir);

/*
 * \brief verrify if the letter entered by the player is good for coordinates
 * \param aLetter : the letter to verrify
 * \return bool
 */
bool isGoodLetter(char aLetter);

/*
 * \brief verify if the player has entered a number for the coordinates
 * \param aLetter : the letter/number
 * \return void
 */
bool isNumber(char aLetter);

/*
 * \brief change a char in uppercase if it is possible
 * \param aLetter : a letter entered
 * \return void
 */
void toUpper(char& aLetter);

void displayShootMenu();

void displayPlayingMenu();

void displayTestsMenu();

void displayWin(Player aPlayer);

#endif // FUNCTIONS_H
