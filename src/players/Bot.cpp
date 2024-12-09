#include "Bot.h"

Bot::Bot(int width, int height, std::vector<unsigned> shipLengths) : field(width, height), shipManager(shipLengths), damage(1)
{
	placeShips();
}
Bot::Bot() : field(1, 1), shipManager({1}) {}
Bot::~Bot() {}

void Bot::placeShips()
{
	std::vector<Directions> dirs = {Directions::West, Directions::North, Directions::East, Directions::South};
	int numOfShips = shipManager.getLength();
	int count = 0;
	for (int i = 0; i < numOfShips;)
	{
		count++;
		if (count > 1000)
		{
			std::cout << "Возможно поле маловато, больше кораблей добавить не получается :(" << "\n";
			break;
		}

		Position position;
		Direction direction;
		try
		{
			int x = randomInt(0, field.getWidth() - 1);
			int y = randomInt(0, field.getWidth() - 1);
			int dir = randomInt(0, dirs.size() - 1);
			Directions direction = dirs[dir];

			auto &ship = shipManager.at(i);
			this->field.addShip(x, y, direction, ship);
			std::cout << field << '\n';

			i++;
		}
		catch (std::exception &e)
		{
			// std::cout << e.what() << "\n";
		}
	}
}

UserInputs Bot::move(Player &player)
{
	try
	{
		int x = randomInt(0, field.getWidth() - 1);
		int y = randomInt(0, field.getWidth() - 1);

		player.getField().attack(x, y, damage);
		std::cout << field << '\n';
	}
	catch (std::exception &e)
	{
		// std::cout << e.what() << "\n";
	}

	return UserInputs::Attack;
}

Field &Bot::getField()
{
	return this->field;
}

ShipManager &Bot::getShipManager()
{
	return this->shipManager;
}

void Bot::setShipManager(ShipManager &sm)
{
	this->shipManager = sm;
}

void Bot::setField(Field &f)
{
	this->field = f;
}
