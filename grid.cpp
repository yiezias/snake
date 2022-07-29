#include "grid.h"
#include <QApplication>
#include <QMessageBox>

int next(int key, int site, int r, int c) {
	switch (key) {
	case Qt::Key_Up:
		return (site - c + r * c) % (r * c);
	case Qt::Key_Down:
		return (site + c) % (r * c);
	case Qt::Key_Left:
		return site / r * r
		       + (site % r + c - 1) % c;
	case Qt::Key_Right:
		return site / r * r + (site % r + 1) % c;
	default:
		return site;
	}
}

grid::grid(int r, int c)
	: arr(new lat[r * c]), rw(r), cl(c), snake(2, 0) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			layout.addWidget(&arr[i * c + j], i,
					 j);
		}
	}
	snake[0] = r / 2 * r + c / 2;
	setLayout(&layout);
	srand(time(nullptr));
	int fsite = -1;
	do {
		fsite = rand() % (r * c);
	} while (fsite == snake[0]);
	arr[fsite].stat = food;
}

void grid::move() {
	for (int var = snake.size() - 1; var != 0; --var) {
		snake[var] = snake[var - 1];
	}
	snake[0] = next(keydire, snake[0], rw, cl);
	if (arr[*snake.begin()].stat == block) {
		QMessageBox::information(this, "结束",
					 "游戏结束了");
		QApplication::quit();
	}

	if (arr[snake[0]].stat == food) {
		arr[snake[0]].stat = block;
		arr[snake[0]].repaint();
		snake.push_front(
			next(keydire, snake[0], rw, cl));
		srand(time(nullptr));
		int fsite = -1;
		do {
			fsite = rand() % (rw * cl);
		} while (arr[fsite].stat != space||fsite==snake[0]);
		arr[fsite].stat = food;
		arr[fsite].repaint();
	}
	arr[*snake.begin()].stat = block;
	arr[*snake.rbegin()].stat = space;
	arr[*snake.begin()].repaint();
	arr[*snake.rbegin()].repaint();
}

void grid::keyPressEvent(QKeyEvent *event) {
	int key = event->key();
	if ((key == Qt::Key_Left || key == Qt::Key_Right
	     || key == Qt::Key_Up || key == Qt::Key_Down)
	    && (key - keydire) % 2) {
		keydire = key;
	}
	move();
}
