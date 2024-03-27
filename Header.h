#pragma once

class Tank
{
public:
	void move(int x, int y);

protected:
	virtual void doMove();

private: 
	//tank position
	int x;
	int y;
};

class enemyTank : public Tank
{
protected:
	void doMove() override;
};

//in code:

Tank* pTank = EnemyTank();
