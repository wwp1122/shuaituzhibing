#include "newg.h"
#include <qmessagebox.h>
#include <stdlib.h>
#include <time.h>

#include "image.h"

QString picturePath = "";
int star3 = 0;
int star4 = 0;
int star5 = 0;
int leftMoney = 10000;

newG::newG(QWidget *parent) :
QMainWindow(parent)
{
	setWindowTitle(QString::fromLocal8Bit("√˚Ω´ø®∞¸"));
	ui.setupUi(this);
	ui.star3->setEnabled(false);
	ui.star4->setEnabled(false);
	ui.star5->setEnabled(false);
	ui.leftMoney->setEnabled(false);
	ui.leftMoney->setText(QString::fromLocal8Bit("”‡∂Ó£∫") + QString::number(leftMoney));

}

newG::~newG()
{
}

void newG::displayPictrue(int label, int level)
{

	picturePath = ":/Battle/picture";
	switch (level)
	{
	case 3:
		picturePath += "/level3.png";
		break;
	case 4:
		picturePath += "/level4.png";
		break;
	case 5:
		picturePath += "/level5.png";
		break;
	}

	QImage img;
	img.load(picturePath);
	switch (label)
	{
	case 0:
		ui.label->setPixmap(QPixmap::fromImage(img));
		break;
	case 1:
		ui.label_2->setPixmap(QPixmap::fromImage(img));
		break;
	case 2:
		ui.label_3->setPixmap(QPixmap::fromImage(img));
		break;
	case 3:
		ui.label_4->setPixmap(QPixmap::fromImage(img));
		break;
	case 4:
		ui.label_5->setPixmap(QPixmap::fromImage(img));
		break;
	}
}

void newG::on_lottery_clicked()
{
	leftMoney -= 950;
	if (leftMoney<0)
	{
		leftMoney += 950;
		QMessageBox::about(this, "goodGame", QString::fromLocal8Bit("«Î≥‰÷µ"));
		return;
	}
	ui.label->clear();
	ui.label_2->clear();
	ui.label_3->clear();
	ui.label_4->clear();
	ui.label_5->clear();
	ui.leftMoney->setText(QString::fromLocal8Bit("”‡∂Ó£∫") + QString::number(leftMoney));
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
	{
		if ((rand() % 50) == 0)
		{
			displayPictrue(i, 5);
			star5++;
			QString starNumber = QString::fromLocal8Bit("ŒÂ–«ø®:≤‹≤Ÿ : x") + QString::number(star5);
			ui.star5->setText(starNumber);
			QMessageBox::about(this, "goodGame", QString::fromLocal8Bit("Œ‘≤€,666,ŒÂ–«"));
		}
		else if ((rand() % 5) == 0)
		{
			displayPictrue(i, 4);
			star4++;
			QString starNumber = QString::fromLocal8Bit("Àƒ–«ø®£∫≤‹≤Ÿ : x") + QString::number(star4);
			ui.star4->setText(starNumber);
		}
		else
		{
			displayPictrue(i, 3);
			star3++;
			QString starNumber = QString::fromLocal8Bit("»˝–«ø®£∫–°«« : x") + QString::number(star3);
			ui.star3->setText(starNumber);
		}
	}
	return;
}

void newG::on_singleClick_clicked()
{
	leftMoney -= 100;
	Image* img = new Image(this);
	if (leftMoney < 0)
	{
		leftMoney += 100;
		QMessageBox::about(this, "goodGame", QString::fromLocal8Bit("«Î≥‰÷µ"));
		return;
	}
	ui.label->clear();
	ui.label_2->clear();
	ui.label_3->clear();
	ui.label_4->clear();
	ui.label_5->clear();
	ui.leftMoney->setText(QString::fromLocal8Bit("”‡∂Ó£∫") + QString::number(leftMoney));

	srand((unsigned)time(NULL));
	if ((rand() % 50) == 0)
	{
		img->dispaly(5);
		star5++;
		QString starNumber = QString::fromLocal8Bit("ŒÂ–«ø®:≤‹≤Ÿ : x") + QString::number(star5);
		ui.star5->setText(starNumber);
		QMessageBox::about(this, "goodGame", QString::fromLocal8Bit("Œ‘≤€,666,ŒÂ–«"));
	}
	else if ((rand() % 5) == 0)
	{
		img->dispaly(4);
		star4++;
		QString starNumber = QString::fromLocal8Bit("Àƒ–«ø®£∫≤‹≤Ÿ : x") + QString::number(star4);
		ui.star4->setText(starNumber);
	}
	else
	{
		img->dispaly(3);
		star3++;
		QString starNumber = QString::fromLocal8Bit("»˝–«ø®£∫–°«« : x") + QString::number(star3);
		ui.star3->setText(starNumber);
	}
	img->show();
	return;
}