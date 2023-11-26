#pragma once

#include <cstdint>
#include <algorithm>
#include <iostream>
#include <format>
#include <chrono>
#include "OrderStatisticTree.h"
#include "Utility.h"

class Game final {
public:
	void Round(std::string playerInput) const;
	void GetScore() const;
	static const Game runtime;
	void Input() const;
private:
	Game(void);
	Game(Game& other);
	~Game();
	Game& operator=(Game& other);
		
	static const OrderStatisticTree<std::string> moveTree;
	mutable std::int64_t playerScore = 0, computerScore = 0;
	const __int64 Match(const __int64 playerMove, const __int64 computerMove) const;
};