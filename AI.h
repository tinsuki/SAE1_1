#ifndef AI_H
#define AI_H

#include "typeDef.h"

void AIOptimisedShoot(Player &anAI, Player &aPlayer, bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY);

void AIRandomShoot(Player &aPlayer, Player &anAI);

void AICrossShoot(Player &anAI, Player &aPlayer, char& currentX, int& currentY, bool& found, char& dir, char& previousX, int& previousY, char& oriX, int& oriY);

#endif // AI_H
