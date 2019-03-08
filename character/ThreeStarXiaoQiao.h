#pragma once
#include "character.h"
//10%  (one) (spell damage)

class ThreeStarXiaoQiao :public Character
{
public:
	ThreeStarXiaoQiao();
	~ThreeStarXiaoQiao();
	void initValue();
	void normalAttack(int& attackP);
	void launchSkill(int& strategyP);

	void getName(QString& name);
	void setBloodVolume(int BloodV);
	void getBloodVolume(int& bloodV);
	void getDefensivePower(int& defensiveP);
};

