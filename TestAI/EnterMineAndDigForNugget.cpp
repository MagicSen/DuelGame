#include "EnterMineAndDigForNugget.h"

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	if(pMiner->Location() != goldmine){
	cout << "\n" << GetNameofEntity(pMiner->ID()) 
	     << ": " << "Walking" to the gold mine";
	pMiner->ChangeLocation(goldmine);
	}
}

void EnterMineAndDigForNugget::Execute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();
	cout << "\n" << GetNameOfEntity(pMiner->ID()) 
	     << ": " << "Pickin' up a nugget";
	if(pMiner->PocketsFull()){
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}
	if(pMiner->Thirsty()){
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
	cout << "\n" << GetNameofEntity(pMiner->ID()) << ": "
	     << "Ah'm leaving the gold mine with mah pockets full o' sweet gold";
}
