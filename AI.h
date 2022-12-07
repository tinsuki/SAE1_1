#ifndef AI_H
#define AI_H

#include "typeDef.h"

/*
 * \brief : an ai that shoot aleatory in the opponent grid and search for a ship when it find one
 * \param anAi : the ai contained in a Player variable
 * \param aPlayer : the opponent player
 * \param found : a bool to know if the ai found a ship
 * \param dir : a char, the dirrection of the ship or 'N' if don't find it
 * \param previousX : a char, the previous column where a ship was found
 * \param previousY : an int, the previous row where a ship was found
 * \param oriX : a char, the column where the ship was found in first
 * \param oriY : an int, the row where the ship was found in first
 * \param saving : a bool, if the save is enable or not
 * \param saveFile : an ofstream, the file stream in output for the save or a void ofstream
 * \return void.
 */
void AIOptimisedShoot(Player &anAI, Player &aPlayer, bool& found, char& dir, char& previousX, int& previousY, char& oriX,
                      int& oriY, bool saving, ofstream &saveFile);

/*
 * \brief : an ai that shoot aleatory in the opponent grid and search for a ship when it find one
 * \param anAi : the ai contained in a Player variable
 * \param aPlayer : the opponent player
 * \param saving : a bool, if the save is enable or not
 * \param saveFile : an ofstream, the file stream in output for the save or a void ofstream
 * \return void.
 */
void AIRandomShoot(Player &aPlayer, Player &anAI, bool saving, ofstream &saveFile);

/*
 * \brief : an ai that shoot in Cross in the opponent grid and search for a ship when it find one
 * \param anAi : the ai contained in a Player variable
 * \param aPlayer : the opponent player
 * \param found : a bool to know if the ai found a ship
 * \param dir : a char, the dirrection of the ship or 'N' if don't find it
 * \param previousX : a char, the previous column where a ship was found
 * \param previousY : an int, the previous row where a ship was found
 * \param oriX : a char, the column where the ship was found in first
 * \param oriY : an int, the row where the ship was found in first
 * \param saving : a bool, if the save is enable or not
 * \param saveFile : an ofstream, the file stream in output for the save or a void ofstream
 * \return void.
 */
void AICrossShoot(Player &anAI, Player &aPlayer, char& currentX, int& currentY, bool& found, char& dir, char& previousX,
                  int& previousY, char& oriX, int& oriY, bool saving, ofstream &saveFile);

#endif // AI_H
