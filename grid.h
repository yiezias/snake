#ifndef GRID_H
#define GRID_H

#include "lat.h"
#include <QGridLayout>
#include <QMouseEvent>
#include <QVector>
#include <QWidget>

class grid : public QWidget {
	lat *arr;
	int rw, cl;
	QGridLayout layout;
	int keydire = Qt::Key_Right;
	QVector<int> snake;

public:
	using QWidget::QWidget;
	grid(int r, int c);
	~grid() {
		delete[] arr;
	}
	void keyPressEvent(QKeyEvent *event);
public slots:
	void move();
};

#endif	// GRID_H
