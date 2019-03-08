#include "battle.h"
#include <qmessagebox.h>

const QStringList cnnumber = {  QString::fromLocal8Bit("一"), QString::fromLocal8Bit("二")
, QString::fromLocal8Bit("三"), QString::fromLocal8Bit("四"), QString::fromLocal8Bit("五"), 
QString::fromLocal8Bit("六"), QString::fromLocal8Bit("七"), QString::fromLocal8Bit("八"),
QString::fromLocal8Bit("九"), QString::fromLocal8Bit("十") };
int progressBarMax[3] = {200,150,100};

int own = 0;
int other = 0;
QString report = "";

Battle::Battle(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	refresh();
	ne = new newG();
}

Battle::~Battle()
{

}

void Battle::refresh()
{
	QImage img(":/Battle/picture/vs.jpg");
	QSize si = ui.VS->size();
	img.scaled(ui.VS->size(), Qt::KeepAspectRatio);
	ui.VS->setPixmap(QPixmap::fromImage(img));

	for (int i = 0; i < 6; i++)
		displayHero(i);

	ui.ownProgressBar_1->setMinimum(0);
	ui.ownProgressBar_2->setMinimum(0);
	ui.ownProgressBar_3->setMinimum(0);
	ui.otherProgressBar_1->setMinimum(0);
	ui.otherProgressBar_2->setMinimum(0);
	ui.otherProgressBar_3->setMinimum(0);

	//ui.ownProgressBar_1->setMaximum(200);
	//ui.ownProgressBar_2->setMaximum(200);
	//ui.ownProgressBar_3->setMaximum(200);
	//ui.otherProgressBar_1->setMaximum(200);
	//ui.otherProgressBar_2->setMaximum(200);
	//ui.otherProgressBar_3->setMaximum(200);
}

void Battle::displayHero(int labelIndex)
{
	QImage img;
	if (labelIndex == 0)
	{
		getPicture(ui.ownSideFirst->currentIndex(), img);
		ui.ownFirstPicture->setPixmap(QPixmap::fromImage(img));
		ui.ownProgressBar_1->setMaximum(progressBarMax[ui.ownSideFirst->currentIndex()]);
	}
	else if (labelIndex == 1)
	{
		getPicture(ui.ownSideSecond->currentIndex(), img);
		ui.ownSecondPicture->setPixmap(QPixmap::fromImage(img));
		ui.ownProgressBar_2->setMaximum(progressBarMax[ui.ownSideSecond->currentIndex()]);
	}
	else if (labelIndex == 2)
	{
		getPicture(ui.ownSideThird->currentIndex(), img);
		ui.ownThirdPicture->setPixmap(QPixmap::fromImage(img));
		ui.ownProgressBar_3->setMaximum(progressBarMax[ui.ownSideThird->currentIndex()]);
	}
	else if (labelIndex == 3)
	{
		getPicture(ui.otherSideFirst->currentIndex(), img);
		ui.otherFirstPicture->setPixmap(QPixmap::fromImage(img));
		ui.otherProgressBar_1->setMaximum(progressBarMax[ui.otherSideFirst->currentIndex()]);
	}
	else if (labelIndex == 4)
	{
		getPicture(ui.otherSideSecond->currentIndex(), img);
		ui.otherSecondPicture->setPixmap(QPixmap::fromImage(img));
		ui.otherProgressBar_2->setMaximum(progressBarMax[ui.otherSideSecond->currentIndex()]);
	}
	else if (labelIndex == 5)
	{
		getPicture(ui.otherSideThird->currentIndex(), img);
		ui.otherThirdPicture->setPixmap(QPixmap::fromImage(img));
		ui.otherProgressBar_3->setMaximum(progressBarMax[ui.otherSideThird->currentIndex()]);
	}
	else
		return;
	refreshCharacter(ui.ownSideFirst->currentIndex(), ownSide[0]);
	refreshCharacter(ui.ownSideSecond->currentIndex(), ownSide[1]);
	refreshCharacter(ui.ownSideThird->currentIndex(), ownSide[2]);
	refreshCharacter(ui.otherSideFirst->currentIndex(), otherSide[0]);
	refreshCharacter(ui.otherSideSecond->currentIndex(), otherSide[1]);
	refreshCharacter(ui.otherSideThird->currentIndex(), otherSide[2]);

	ui.ownProgressBar_1->setValue(ui.ownProgressBar_1->maximum());
	ui.ownProgressBar_2->setValue(ui.ownProgressBar_2->maximum());
	ui.ownProgressBar_3->setValue(ui.ownProgressBar_3->maximum());
	ui.otherProgressBar_1->setValue(ui.otherProgressBar_1->maximum());
	ui.otherProgressBar_2->setValue(ui.otherProgressBar_2->maximum());
	ui.otherProgressBar_3->setValue(ui.otherProgressBar_3->maximum());

	own = 0;
	other = 0;
	report = "";

	ui.displayBattleReport->clear();
}

void Battle::getPicture(int index, QImage& img)
{
	switch (index)
	{
	case 0:
		img.load(":/Battle/picture/level_5.png");
		break;
	case 1:
		img.load(":/Battle/picture/level_4.png");
		break;
	case 2:
		img.load(":/Battle/picture/level_3.png");
		break;;
	}
	return;
}

void Battle::on_ownSideFirst_currentIndexChanged(int index)
{
	displayHero(0);
}
void Battle::on_ownSideSecond_currentIndexChanged(int index)
{
	displayHero(1);
}
void Battle::on_ownSideThird_currentIndexChanged(int index)
{
	displayHero(2);
}
void Battle::on_otherSideFirst_currentIndexChanged(int index)
{
	displayHero(3);
}
void Battle::on_otherSideSecond_currentIndexChanged(int index)
{
	displayHero(4);
}
void Battle::on_otherSideThird_currentIndexChanged(int index)
{
	displayHero(5);
}

void Battle::refreshCharacter(int index, std::shared_ptr<Character>& level)
{
	switch (index)
	{
	case 0:
		level = std::shared_ptr<FiveStarCaoCao>(new FiveStarCaoCao);
		break;
	case 1:
		level = std::shared_ptr<FourStarCaoCao>(new FourStarCaoCao);
		break;
	case 2:
		level = std::shared_ptr<ThreeStarXiaoQiao>(new ThreeStarXiaoQiao);
		break;
	}
}

void Battle::on_battle_clicked()
{
	ui.displayBattleReport->clear();
	for (int i = 0; i < 8; i++)
	{
		report += QString::fromLocal8Bit("第") + cnnumber[i] + QString::fromLocal8Bit("回合: \n");
		if (!fight())
			return;
	}
	ui.displayBattleReport->setText(report);
}

bool Battle::fight()
{
	for (int i = own; i < 3; i++)
	{
		if (other == 3)
			return false;
		fight(true, ownSide[own], otherSide[other]);
	}

	for (int i = other; i < 3; i++)
	{
		if (own == 3)
			return false;
		fight(false, otherSide[other], ownSide[own]);
	}
	return true;
}

void Battle::fight(bool square, std::shared_ptr<Character>& attacker, std::shared_ptr<Character>& defender)
{
	int normalAttack, strategyP, defensive, blood = 0;
	QString attackerName, defenderName;


	attacker->getName(attackerName);
	defender->getName(defenderName);
	defender->getBloodVolume(blood);
	if (blood > 0)
	{
		defender->getDefensivePower(defensive);
		attacker->normalAttack(normalAttack);
		normalAttack *= (float)defensive / 100;
		attacker->launchSkill(strategyP);
		//strategyP *= (float)defensive / 100;
	}
	if (square)
	{
		report += QString::fromLocal8Bit("敌方：") + defenderName +
			QString::fromLocal8Bit("受到来自我方：") + attackerName +
			QString::fromLocal8Bit("的物理伤害") + QString::number(normalAttack) +
			QString::fromLocal8Bit("点和") +
			QString::fromLocal8Bit("魔法伤害") + QString::number(normalAttack) + QString::fromLocal8Bit("点\n");
		blood = blood - normalAttack - strategyP;
		if ((blood) <= 0)
		{
			blood = 0;
			report += QString::fromLocal8Bit("敌方：") + defenderName + QString::fromLocal8Bit("已阵亡\n");
			other++;
		}
		defender->setBloodVolume(blood);
	}
	else
	{
		report += QString::fromLocal8Bit("我方：") + defenderName +
			QString::fromLocal8Bit("受到来自敌方：") + attackerName +
			QString::fromLocal8Bit("的物理伤害") + QString::number(normalAttack) +
			QString::fromLocal8Bit("点和") +
			QString::fromLocal8Bit("魔法伤害") + QString::number(normalAttack) + QString::fromLocal8Bit("点\n");
		blood = blood - normalAttack - strategyP;
		if ((blood) <= 0)
		{
			blood = 0;
			report += QString::fromLocal8Bit("我方：") + defenderName + QString::fromLocal8Bit("已阵亡\n");
			own++;
		}
		defender->setBloodVolume(blood);
	}

	displayProgressBar();

	if (other == 3)
	{
		report += QString::fromLocal8Bit("我方胜利\n");
		QMessageBox::about(this, QString::fromLocal8Bit("战况"), QString::fromLocal8Bit("你赢了！"));
	}
	if (own == 3)
	{
		report += QString::fromLocal8Bit("敌方胜利\n");
		QMessageBox::about(this, QString::fromLocal8Bit("战况"), QString::fromLocal8Bit("你输了！"));
	}
}

void Battle::displayProgressBar()
{
	int blood;
	
	ownSide[0]->getBloodVolume(blood);
	ui.ownProgressBar_1->setValue(blood);

	ownSide[1]->getBloodVolume(blood);
	ui.ownProgressBar_2->setValue(blood);

	ownSide[2]->getBloodVolume(blood);
	ui.ownProgressBar_3->setValue(blood);

	otherSide[0]->getBloodVolume(blood);
	ui.otherProgressBar_1->setValue(blood);

	otherSide[1]->getBloodVolume(blood);
	ui.otherProgressBar_2->setValue(blood);

	otherSide[2]->getBloodVolume(blood);
	ui.otherProgressBar_3->setValue(blood);
}

void Battle::on_click_clicked()
{
	ne->show();
}
