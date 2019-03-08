#ifndef NEWG_H
#define NEWG_H

#include <QtWidgets/QMainWindow>
#include "ui_newg.h"

class newG : public QMainWindow
{
	Q_OBJECT

public:
	newG(QWidget *parent = 0);
	~newG();

private:
	Ui::newGClass ui;
	void displayPictrue(int label, int level);
	private slots:
	void on_lottery_clicked();
	void on_singleClick_clicked();
};

#endif // NEWG_H
