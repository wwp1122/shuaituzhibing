#include "image.h"
#include "ui_image.h"
#include <QMouseEvent>

QString picPath = "";
Image::Image(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Image)
{
    ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	setWindowModality(Qt::WindowModal);
	ui->label->setScaledContents(true);
}

Image::~Image()
{
    delete ui;
}

void Image::dispaly(int level)
{
	picPath = ":/Battle/picture";
	switch (level)
	{
	case 3:
		picPath += "/level3.png";
		break;
	case 4:
		picPath += "/level4.png";
		break;
	case 5:
		picPath += "/level5.png";
		break;
	}

	QImage img;
	img.load(picPath);
	img.scaled(ui->label->size(), Qt::KeepAspectRatio);
	ui->label->setPixmap(QPixmap::fromImage(img));
}


void Image::mousePressEvent(QMouseEvent* event)
{
	event->accept();
	this->close();
}

void Image::resizeEvent(QResizeEvent* event)
{
	ui->label->resize(size());
}