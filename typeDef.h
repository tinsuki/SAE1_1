#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <string>
#include <iostream>
#include <random>
#include <fstream> // include fstream to save


#ifdef __WIN32
    #define OS 1
#endif
#ifdef __APPLE__
    #define OS 2
#endif
#ifdef __linux__
    #define OS 3
#endif
#ifndef OS
    #define OS 0
#endif



using namespace std;

//la dimension de la grille de jeu 10+2 pour detection du navire voisin
const int GRIDSIZE = 12 ; // change SIZE in GRIDSIZE due to windows.h compatibility

// le nombre de navires de guerre
const int NBSHIPS = 5;

// le nombre de cases occupees par les navires d'un joueur (score)
const int NBCELLS = 17;

// The maximun size of a ship
const int MAXSHIPSIZE = 5; // add the maximun size of a ship for a function

// les navires de guerre disponibles et leur taille sur la grille
enum Ship
{
    CARRIER=5,
    CRUISER=4,
    DESTROYER=3,
    SUBMARINE=3,
    TORPEDO=2,
    NONE=0
}; //numero = nb cases

// les noms des navires de guerre
const string ships[NBSHIPS] = {"carrier", "cruiser", "destroyer", "submarine", "torpedo"};

// les differents etats que peut prendre une case de la grille et leur affichage
enum State
{
    HIT='x',
    SINK='#',
    MISS='o',
    UNSHOT='~'
};

// une case de la grille
// le navire present sur la case
// l’etat de la case
struct Cell
{
    Ship ship;
    State state;
};

// le joueur avec
// son nom
// son score pour determiner qui a perdu
// sa grille de jeu
struct Player
{
    std::string name;
    int score;
    Cell grid[GRIDSIZE][GRIDSIZE];
};

// les coordonnees de la case sur la grille
// sa ligne de 1 à 10
// sa colonne de ‘A’ à ‘J’ (lettre en MAJ)
struct Coordinate
{
  char col;
  int row;
};

// le placement du navire sur la grille
// sa coordonnee (E5)
// sa direction ‘H’ horizontal ou ‘V’ vertical depuis la coordonnee
struct Placement
{
    Coordinate coordi;
    char dir;
};

#endif // TYPEDEF_H
