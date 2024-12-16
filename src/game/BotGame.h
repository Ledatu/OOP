#ifndef BotGame_H
#define BotGame_H

#include "Game.h"
#include "../players/User.h"
#include "../players/Bot.h"
#include "../players/Player.h"
#include <string>
#include "GameState.h"

class BotGame : public Game
{

	User &user;
	Bot &bot;
	GameState &state;
	Player *currentPlayer;
	Player *currentEnemy;

	int moveCount;

public:
	BotGame(User &user, Bot &bot, GameState &state) : user(user), bot(bot), state(state), moveCount(0) {};
	void start(std::string filename) override;
	void load(std::string fileName) override;
	void save(std::string fileName) override;
	void setBot(Bot *bot);
	void setUser(User *user);

	GameState getGameState() override;
};

#endif