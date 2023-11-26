#include "Game.h"

using namespace std::string_literals;

const Game Game::runtime = Game();

const OrderStatisticTree<std::string> Game::moveTree = { "rock", "paper", "scissors" };

Game::Game() : playerScore(0), computerScore(0) {}

Game::Game(Game& other) : Game() {}

Game& Game::operator=(Game& other) {
	return other;
}

Game::~Game() {}

void Game::Round(std::string playerInput) const
{
	// Transform playerInput to lowercase
	std::transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::tolower);
	try
	{
		if (not moveTree.Contains(playerInput)) {
			throw std::invalid_argument("Invalid argument was given.");
		}
		std::_Iter_diff_t<std::string> playerMove = moveTree.Rank(playerInput);
		const int computerMove = Utility::Random(0, 2);
		switch (Match(playerMove, computerMove)) {
		case -1:
			std::println(std::cout, "You lose! {} beats {}", moveTree.Select(computerMove), playerInput);
			break;
		case 0:
			std::println(std::cout, "Tie with {}", playerInput);
			break;
		case 1:
			std::println(std::cout, "You win! {} beats {}", playerInput, moveTree.Select(computerMove));
			break;
		}
	}
	catch (const std::exception &e)
	{
		std::println(std::cerr, "{} at {}", e.what(), std::chrono::system_clock::now());
		throw std::invalid_argument("Invalid argument was given.");
	}
}

void Game::GetScore() const
{
	std::println(std::cout, "Score: {} (player) | {} (computer)", playerScore, computerScore);
}

void Game::Input() const
{

}

const __int64 Game::Match(const __int64 playerMove, const __int64 computerMove) const
{
	const auto outcome = playerMove - computerMove;
	// Loss
	if (outcome == -1 or outcome == 2)
	{
		computerScore++;
		return -1;
	}
	// Tie
	else if (outcome == 0)
	{
		return 0;
	}
	// Win
	else if (outcome == 1 or outcome == -2)
	{
		playerScore++;
		return 1;
	}
	// Catch any undefined error
	else {
		throw std::exception();
	}
}