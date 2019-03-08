#pragma once
#include <stdlib.h>
#include <time.h>
#include <qstring.h>
class Character
{
public:
	Character();
	virtual ~Character();
	virtual void initValue();
	virtual void normalAttack(int& attackP);
	virtual void launchSkill(int& strategyP);

	virtual void getName(QString& name);
	virtual void setBloodVolume(int BloodV);
	virtual void getBloodVolume(int& BloodV);
	virtual void getDefensivePower(int& defensiveP);
	//virtual void getSpeed(int& sp);
	//virtual void getStrategyPower(int& strategyP);
	//virtual void getAttackPower(int& attackP);
protected:
	QString name;
	int bloodVolume;

	int defensivePower;
	int speed;
	int strategyPower;
	int attackPower;
};

