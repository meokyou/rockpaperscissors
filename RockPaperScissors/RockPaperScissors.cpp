#include "RockPaperScissors.h"

int main()
{
	using namespace std::string_literals;
	std::cout << R"(
===========================
   Rock, Paper, Scissors
   by Christian Anderson
===========================

Gameplay:
- Type in one of three words: 'rock', 'paper', or 'scissors'.
- When you are finished playing and you would like to quit, type 'close'.

Rules:
1. Don't type something random please? It'll result in a one point penalty.

Here we go!
)" << std::endl;

	while (true)
	{
		Game::runtime.GetScore();
		std::print(std::cout, "Rock, paper, scissors, shoot: ");
		while (true)
		{
			std::string playerInput;
			std::getline(std::cin, playerInput);
			if (playerInput == "close")
			{
				std::cout << "Thanks for playing!" << std::endl;
				return 0;
			}
			try
			{
				Game::runtime.Round(playerInput);
				break;
			}
			catch (std::invalid_argument e)
			{
				std::print(std::cout, "Invalid input! Please enter a valid move: ");
			}
		}
			
	}
	return 0;
}
