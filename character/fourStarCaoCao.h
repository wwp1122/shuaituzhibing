#pragma once
#include "character.h"
//20% 

class FourStarCaoCao:public Character
{
public:
	FourStarCaoCao();
	~FourStarCaoCao();
	void initValue();
	void normalAttack(int& attackP);
	void launchSkill(int& strategyP);

	void getName(QString& name);
	void setBloodVolume(int BloodV);
	void getBloodVolume(int& bloodV);
	void getDefensivePower(int& defensiveP);
};

