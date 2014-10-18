#include "Miner.h"

void Miner::Update()
{
	m_iThirst += 1;
	if(m_pCurrentState){
		m_pCurrentState->Execute(this);
	}
}

void Miner::ChangeState(State *pNewState)
{
	assert (m_pCurrentState && pNewState);

	m_pCurrentState->Exit(this);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(this);
}
