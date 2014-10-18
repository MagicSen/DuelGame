#pragma once
class BaseGameEntity
{
private:
	int	m_ID;
	static int m_iNextValidID;
	void SetID(int val);
public:
	BaseGameEntity(int id)
	{
		SetID(id);
	}
	virtual ~BaseGameEntity(){}
	virtual void Update() = 0;
	int ID() const {return m_ID};
};
