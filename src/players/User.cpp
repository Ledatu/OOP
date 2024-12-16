#include "User.h"

User::User(int width, int height, std::vector<unsigned> shipLengths) : field(width, height), shipManager(shipLengths)
{
	this->skillManager = SkillManager();
	this->damage = 1;
	placeShips();
}

User::User() : field(), shipManager() {}
User::~User() {}

UserInputs User::move(Player &player)
{
	UserInput userInput;
	std::cin >> userInput;

	try
	{
		if (userInput.get() == UserInputs::Attack)
		{

			Position position;
			std::cout << "Введите координаты x <пробел> y для атаки:\n";
			std::cin >> position;

			attack(player, position.x(), position.y());
		}
		else if (userInput.get() == UserInputs::UseSkill)
		{
			auto skillInfoHolder = SkillInfoHolder(&player.getField(), &player.getShipManager());
			try
			{
				Position position;
				std::string name = skillManager.at(0).name();
				if (name == "Scaner")
				{
					std::cout << "Введите координаты для проверки сканером:\n";
					std::cin >> position;
					skillInfoHolder.setPosition(position);
				}

				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw std::runtime_error("Введены некорректные данные для размеров поля.");
				}

				auto skill = skillManager.getSkill(skillInfoHolder);

				bool res = skill->use();
				if (name == "Scaner")
				{
					std::cout << (res ? "Корабль есть" : "Кораблей нет") << '\n';
				}
				else if (name == "Shelling")
				{
					skillManager.addSkillIfNeccessary(res);
				}

				delete skill;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		else
		{
			return userInput.get();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// while (cmd == Command::skill)
	// {
	// 	try
	// 	{
	// 		this->useSkill(player);
	// 	}
	// 	catch (NoneAvailableSkillsException &e)
	// 	{
	// 		std::cout << e.what();
	// 	}
	// 	try
	// 	{
	// 		commandHolder.read();
	// 	}
	// 	catch (UnknownCommandException &e)
	// 	{
	// 		std::cout << "Unknown Command" << '\n';
	// 	}
	// 	cmd = commandHolder.getCommand();
	// }
	// if (cmd == Command::load)
	// {
	// 	std::cout << "command load\n";
	// 	return Action::Load;
	// }

	// if (cmd == Command::save)
	// {
	// 	std::cout << "save game\n";
	// 	return Action::Save;
	// }
	// auto coordsHolder = CoordHolder();
	// coordsHolder.read();
	// auto coords = coordsHolder.getCoords();
	// this->attack(player, coords.first - 1, coords.second - 1);
	return UserInputs::Attack;
}

bool User::attack(Player &player, int x, int y)
{
	bool result = player.getField().attack(x, y, damage);
	this->skillManager.addSkillIfNeccessary(result);
	return result;
}

bool User::useSkill(Player &player)
{
	// auto infoHolder = SkillInfoHolder(&player.getShipManager(), &player.getField(), CoordHolder());
	// auto skill = this->skillManager.getSkill(infoHolder);
	// auto skillResult = skill->use();
	// this->damage = skillResult.get_damage();
	// if (this->damage != 1)
	// {
	// 	std::cout << "Следующая атака нанесёт 2-ой урон🚩\n";
	// }
	// if (skillResult.get_is_battleship_destroyed())
	// {
	// 	this->skillManager.addSkill();
	// 	std::cout << "Так как вы уничтожили корабль, вы получили новую способность!\n";
	// }
	// if (skillResult.get_is_battleship_cell())
	// {
	// 	std::cout << "В данной ячейке был корабль!\n";
	// 	return true;
	// }
	return false;
}

void User::placeShips()
{
	int numOfShips = shipManager.getLength();
	for (int i = 0; i < numOfShips;)
	{
		Position position;
		Direction direction;
		try
		{
			std::cout << "Введите координаты x <пробел> y:\n";
			std::cin >> position;
			std::cout << "coords: (" << position.x() << ", " << position.y() << ")\n";

			std::cin >> direction;

			auto &ship = shipManager.at(i);
			this->field.addShip(position.x(), position.y(), direction.get(), ship);
			std::cout << field << '\n';

			i++;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}
}

Field &User::getField()
{
	return this->field;
}

ShipManager &User::getShipManager()
{
	return this->shipManager;
}

SkillManager &User::getSkillManager()
{
	return this->skillManager;
}

int User::getDamage()
{
	return this->damage;
}

void User::setShipManager(ShipManager &sm)
{
	this->shipManager = sm;
}

void User::setField(Field &f)
{
	this->field = f;
}

void User::setSkillManager(SkillManager &sm)
{
	this->skillManager = sm;
}
