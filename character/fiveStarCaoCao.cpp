#include "fiveStarCaoCao.h"


FiveStarCaoCao::FiveStarCaoCao()
{
	initValue();
	srand((unsigned)time(NULL));
}


FiveStarCaoCao::~FiveStarCaoCao()
{
}

void FiveStarCaoCao::initValue()
{
	bloodVolume = 200;

	defensivePower = 40;
	speed = 30;
	strategyPower = 30;
	attackPower = 50;
	name = QString::fromLocal8Bit("ŒÂ–«≤‹≤Ÿ");
}


void FiveStarCaoCao::normalAttack(int& attackP)
{
	attackP = attackPower;
}

void FiveStarCaoCao::launchSkill(int& strategyP)
{
	if ((rand() % 4) == 0)
		strategyP = strategyPower;
	else
		strategyP = 0;
}

void FiveStarCaoCao::getName(QString& heroName)
{
	heroName = name;
}
void FiveStarCaoCao::setBloodVolume(int BloodV)
{
	bloodVolume = BloodV;
}
void FiveStarCaoCao::getBloodVolume(int& bloodV)
{
	bloodV = bloodVolume;
}
void FiveStarCaoCao::getDefensivePower(int& defensiveP)
{
	defensiveP = defensivePower;
}