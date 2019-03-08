#ifndef BATTLE_H
#define BATTLE_H

#include <QtWidgets/QWidget>
#include <iostream>
#include <memory>
#include "ui_battle.h"
#include "character\character.h"
#include "character\fiveStarCaoCao.h"
#include "character\fourStarCaoCao.h"
#include "character\threeStarXiaoQiao.h"

#include "lottery\newg.h"
class Battle : public QWidget
{
	Q_OBJECT

public:
	Battle(QWidget *parent = 0);
	~Battle();
	void refresh();
	void getPicture(int index, QImage& img);
	void displayHero(int labelIndex);//0-2 own 3-5 other
	public slots:
	void on_battle_clicked();

	void on_ownSideFirst_currentIndexChanged(int index);
	void on_ownSideSecond_currentIndexChanged(int index);
	void on_ownSideThird_currentIndexChanged(int index);
	void on_otherSideFirst_currentIndexChanged(int index);
	void on_otherSideSecond_currentIndexChanged(int index);
	void on_otherSideThird_currentIndexChanged(int index);
	void on_click_clicked();
private:
	void refreshCharacter(int index, std::shared_ptr<Character>& level);
	bool fight();
	void fight(bool square,std::shared_ptr<Character>& attacker,std::shared_ptr<Character>& defender);
	void displayProgressBar();

	Ui::BattleClass ui;
	std::shared_ptr<Character> ownSide[3];
	std::shared_ptr<Character> otherSide[3];
	newG* ne;
};

#endif // BATTLE_H
