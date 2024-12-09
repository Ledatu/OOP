#ifndef BOT_H
#define BOT_H

#include "Player.h"
#include "../game/Game.h"
#include "../utils.h"

class Bot : public Player
{
private:
	Field field;
	ShipManager shipManager;
	std::vector<std::pair<int, int>> availableMoves;
	int damage;

public:
	Bot(int width, int height, std::vector<unsigned> shipLengths);
	Bot(const Bot &other) : field(other.field), shipManager(other.shipManager), damage(other.damage) {};
	Bot &operator=(const Bot &other)
	{
		if (this != &other)
		{
			this->field = other.field;
			this->shipManager = other.shipManager;
			this->damage = other.damage;
		}
		return *this;
	}
	Bot();
	~Bot();
	UserInputs move(Player &player) override;
	Field &getField() override;
	void placeShips() override;
	void setField(Field &f);
	void setShipManager(ShipManager &sm);
	ShipManager &getShipManager() override;
};

#endif
