#pragma once
#include "Miner.h"
#include "State.h"

class EnterMineAndDigForNugget : public State
{
private:
	EnterMineAndDigForNugget();
public:
	static EnterMineAndDigForNugget* Instance();
	virtual void Enter(Miner* pMiner);
	virtual void Execute(Miner* pMiner);
	virtual void Exit(Miner* pMiner);
};
