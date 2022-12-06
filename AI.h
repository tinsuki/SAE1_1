#ifndef AI_H
#define AI_H

#include "typeDef.h"

void AIOptimisedShoot(Player &anAI, Cell aGrid[][GRIDSIZE], bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY);

void AIRandomShoot(Cell aGrid[][GRIDSIZE], Player &anAI);

void AICrossShoot(Player &anAI, Cell aGrid[][GRIDSIZE],char& currentX, int& currentY, bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY);

#endif // AI_H
