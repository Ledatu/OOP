#include "BotGame.h"

void BotGame::start()
{
	std::string filename = "/Users/ledatu/documents/oop/save.json";
	std::cout << "kapec\n";
	std::cout << this->user.getDamage();
	while (!this->user.getShipManager().allShipsDead())
	{
		std::cout << moveCount << " move\n";
		auto state = this->getGameState();
		std::cout << state;
		if (moveCount % 2)
		{
			this->currentPlayer = &user;
			this->currentEnemy = &bot;
		}
		else
		{
			this->currentPlayer = &bot;
			this->currentEnemy = &user;
		}

		try
		{
			auto action = this->currentPlayer->move(*(this->currentEnemy));
			if (action == UserInputs::SaveGame)
			{
				this->save(filename);
				continue;
			}
			if (action == UserInputs::LoadGame)
			{
				this->load(filename);
				auto state = this->getGameState();
				std::cout << state;
				std::cout << "Игра загружена из сохранения.";
				continue;
			}
		}
		catch (std::exception &error)
		{
			moveCount--;
			std::cout << error.what();
		}

		if (this->bot.getShipManager().allShipsDead())
		{
			auto field = this->bot.getField();
			auto shipManager = this->bot.getShipManager();

			std::vector<unsigned> shipLengths;
			for (int i = 0; i < shipManager.getLength(); i++)
			{
				shipLengths.push_back(shipManager.at(i).getLength());
			}

			this->bot = Bot(field.getWidth(), field.getHeight(), shipLengths);
			this->state.setBot(this->bot);
			this->bot.placeShips();
		}

		moveCount++;
	}
	std::cout << "Вы проиграли...\n";
}

GameState BotGame::getGameState()
{
	return this->state;
}

void BotGame::load(std::string filename)
{
	auto state = this->getGameState();
	try
	{
		state.load(filename);
	}
	catch (nlohmann::json::exception &e)
	{
		std::cerr << "Error parsing JSON: " << e.what() << std::endl;
		return;
	}
}

void BotGame::save(std::string filename)
{
	auto state = this->getGameState();
	state.save(filename);
}
// void BotGame::move(int x, int y, bool isUseAbility)
// {
// 	if (isUseAbility)
// 	{
// 		state->useSkill();
// 	}
// 	auto coords = CoordHolder();
// 	coords.read();
// 	auto coord = coords.getCoords();
// 	state->attack(coord.first, coord.second);
// 	this->countMoves += 1;
// 	state = this->stateFactory->getState();
// }

// Field& BotGame::getPlayerField (){
// 	return playerField;
// }
// Field& BotGame::getEnemyField(){
// 	return enemyField;
// }

// ShipManager& BotGame:: getPlayerShipManager()
// {
// 	return playerShipManager;
// }

// ShipManager& BotGame::getEnemyShipManager()
// {
// 	return enemyShipManager;
// }

// GameState& BotGame::getGameState(){
// 	return *state;
// }

// SkillManager& BotGame::getSkillManager()
// {
// 	return skillManager;
// }
