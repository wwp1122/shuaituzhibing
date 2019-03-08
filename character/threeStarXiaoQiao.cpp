#include "threeStarXiaoQiao.h"


ThreeStarXiaoQiao::ThreeStarXiaoQiao()
{
	initValue();
	srand((unsigned)time(NULL));
}


ThreeStarXiaoQiao::~ThreeStarXiaoQiao()
{
}

void ThreeStarXiaoQiao::initValue()
{
	bloodVolume = 100;

	defensivePower = 15;
	speed = 45;
	strategyPower = 65;
	attackPower = 18;
	name = QString::fromLocal8Bit("ÈýÐÇÐ¡ÇÇ");
}

void ThreeStarXiaoQiao::normalAttack(int& attackP)
{
	attackP = attackPower;
}

void ThreeStarXiaoQiao::launchSkill(int& strategyP)
{
	if ((rand() % 10)==0)
		strategyP = strategyPower;
	else
		strategyP = 0;
}

void ThreeStarXiaoQiao::getName(QString& heroName)
{
	heroName = name;
}
void ThreeStarXiaoQiao::setBloodVolume(int BloodV)
{
	bloodVolume = BloodV;
}
void ThreeStarXiaoQiao::getBloodVolume(int& bloodV)
{
	bloodV = bloodVolume;
}
void ThreeStarXiaoQiao::getDefensivePower(int& defensiveP)
{
	defensiveP = defensivePower;
}
