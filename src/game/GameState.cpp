#include "GameState.h"

std::string GameState::hash(std::string data)
{
	std::hash<std::string> hash_function;
	size_t hash = hash_function(data);
	std::stringstream ss;
	ss << std::hex << hash;
	return ss.str();
}

Bot &GameState::getBot()
{
	return this->bot;
}

User &GameState::getUser()
{
	return this->user;
}

std::ostream &operator<<(std::ostream &os, GameState &state)
{
	auto userField = state.getUser().getField();
	auto botField = state.getBot().getField();

	os << "Поле игрока\n";
	os << userField << '\n';
	os << "Поле противника:\n";
	os << botField << '\n';

	os << "Способности игрока:\n";
	auto userSkillManager = state.getUser().getSkillManager();
	std::cout << "Количество способностей: " << userSkillManager.size() << '\n';
	if (userSkillManager.size() == 0)
	{
		os << "Отсутсвуют\n";
	}
	for (int i = 0; i < userSkillManager.size(); i++)
	{
		auto name = userSkillManager.at(i).name();
		os << i + 1 << ". " << name << '\n';
	}
	return os;
}

FileWrapper &operator<<(FileWrapper &fileWrapper, GameState &state)
{
	nlohmann::json j;
	nlohmann::json data;
	Serialization serialization(data);

	serialization.stringify(state.getUser().getShipManager(), "playerShipManager");
	serialization.stringify(state.getUser().getField(), "playerField");
	serialization.stringify(state.getUser().getSkillManager(), "playerSkillManager");
	serialization.stringify(state.getBot().getShipManager(), "botShipManager");
	serialization.stringify(state.getBot().getField(), "botField");

	data["currentDamage"] = state.getUser().getDamage();
	j["data"] = data;
	std::string jsonData = data.dump();
	j["hash"] = state.hash(jsonData);

	try
	{
		fileWrapper.write(j);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return fileWrapper;
}

void placeShips(ShipManager &shipManager, Field &field)
{
	std::cout << shipManager.getLength() << " battleships\n";
	for (int i = 0; i < shipManager.getLength(); i++)
	{
		std::cout << i << " i\n";
		auto &ship = shipManager.at(i);
		Position position = ship.getPosition();
		Direction direction = ship.getDirection();

		// std::cout << "x " << position.x() << " y " << position.y() << " d " << direction.get() << "\n"
		// 		  << field << '\n';
		field.addShip(position.x(), position.y(), direction.get(), ship);
	}
}

FileWrapper &operator>>(FileWrapper &fileWrapper, GameState &state)
{
	nlohmann::json j;

	try
	{
		fileWrapper.read(j);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return fileWrapper;
	}
	auto data = j["data"];
	std::string jsonHash = j["hash"];

	std::string jsonData = data.dump();
	std::string currentHash = state.hash(jsonData);
	if (jsonHash != currentHash)
	{
		std::cout << jsonHash << " " << currentHash << "\n";
		throw std::runtime_error("JSON был модифицирован.");
	}

	Deserialization deserialization(data);

	ShipManager shipManager;
	Field field;
	SkillManager skillManager;

	ShipManager botShipManager;
	Field botField;

	deserialization.parse(shipManager, "playerShipManager");
	deserialization.parse(field, "playerField");

	deserialization.parse(skillManager, "playerSkillManager");
	placeShips(shipManager, field);

	deserialization.parse(botShipManager, "botShipManager");
	deserialization.parse(botField, "botField");
	placeShips(botShipManager, botField);

	// std::cout << field.GetWidth() << " " << field.GetHeight() << "width and height of loaded field\n";
	state.getUser().setShipManager(shipManager);
	state.getUser().setSkillManager(skillManager);
	state.getUser().setField(field);

	state.getBot().setShipManager(botShipManager);
	state.getBot()
		.setField(botField);

	return fileWrapper;
}

void GameState::save(const std::string fileName)
{
	FileWrapper wrapper(fileName);
	wrapper << *this;
}

GameState &GameState::load(const std::string fileName)
{
	FileWrapper fileWrapper(fileName);
	fileWrapper >> *this;
	return *this;
}

void GameState::setBot(Bot &bot)
{
	this->bot = bot;
}

void GameState::setUser(User &user)
{
	this->user = user;
}
