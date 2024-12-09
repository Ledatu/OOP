#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "../Field.h"
#include "../ShipManager.h"

class Player
{

public:
	virtual UserInputs move(Player &player) = 0;
	virtual void placeShips() = 0;
	~Player() = default;
	virtual Field &getField() = 0;
	virtual ShipManager &getShipManager() = 0;
};

#endif