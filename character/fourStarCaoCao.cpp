#include "fourStarCaoCao.h"


FourStarCaoCao::FourStarCaoCao()
{
	initValue();
	srand((unsigned)time(NULL));
}


FourStarCaoCao::~FourStarCaoCao()
{
}

void FourStarCaoCao::initValue()
{
	bloodVolume = 150;

	defensivePower = 45;
	speed = 20;
	strategyPower = 15;
	attackPower = 28;
	name = QString::fromLocal8Bit("四星曹操");
}

void FourStarCaoCao::normalAttack(int& attackP)
{
	attackP = attackPower;
}

void FourStarCaoCao::launchSkill(int& strategyP)
{
	if ((rand() % 5) == 0)
		strategyP = strategyPower;
	else
		strategyP = 0;
}

void FourStarCaoCao::getName(QString& heroName)
{
	heroName = name;
}
void FourStarCaoCao::setBloodVolume(int BloodV)
{
	bloodVolume = BloodV;
}
void FourStarCaoCao::getBloodVolume(int& bloodV)
{
	bloodV = bloodVolume;
}
void FourStarCaoCao::getDefensivePower(int& defensiveP)
{
	defensiveP = defensivePower;
}
