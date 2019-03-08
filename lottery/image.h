#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>

namespace Ui {
class Image;
}

class Image : public QWidget
{
    Q_OBJECT

public:
    explicit Image(QWidget *parent = 0);
	void dispaly(int level);
    ~Image();

private:
    Ui::Image *ui;
protected:
	void mousePressEvent(QMouseEvent* event);
	void resizeEvent(QResizeEvent* event);
};

#endif // IMAGE_H
