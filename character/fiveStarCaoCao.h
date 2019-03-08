#pragma once
#include "character.h"
//%25 (one) (spell damage)

class FiveStarCaoCao :public Character
{
public:
	FiveStarCaoCao();
	~FiveStarCaoCao();
	void initValue();
	void normalAttack(int& attackP);
	void launchSkill(int& strategyP);

	void getName(QString& name);
	void setBloodVolume(int BloodV);
	void getBloodVolume(int& bloodV);
	void getDefensivePower(int& defensiveP);
};

