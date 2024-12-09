#ifndef USER_H
#define USER_H

#include "Player.h"
#include "../skills/SkillManager.h"
#include "../utils.h"
#include "../exceptions/ShipNear.h"
#include <iostream>

class User : public Player
{
private:
	Field field;
	ShipManager shipManager;
	SkillManager skillManager;
	int damage;

public:
	int getDamage();
	User(int width, int height, std::vector<unsigned> shipLengths);
	User(const User &other)
		: shipManager(other.shipManager), field(other.field), skillManager(other.skillManager), damage(other.damage) {};
	~User();
	User &operator=(User &other)
	{
		if (this != &other)
		{
			this->shipManager = other.shipManager;
			this->skillManager = other.skillManager;
			this->field = other.field;
			this->damage = other.damage;
		}
		return *this;
	}
	UserInputs move(Player &player) override;
	void placeShips() override;

	bool attack(Player &player, int x, int y);
	User();
	bool useSkill(Player &player);
	Field &getField() override;
	ShipManager &getShipManager() override;
	SkillManager &getSkillManager();
	void setShipManager(ShipManager &sm);
	void setField(Field &f);
	void setSkillManager(SkillManager &sm);
};

#endif
