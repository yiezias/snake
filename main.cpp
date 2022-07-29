
#include "grid.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	grid map(20, 20);
	QTimer tr(&map);
	tr.setInterval(200);
	tr.start();
	QObject::connect(&tr, &QTimer::timeout, &map,
			 &grid::move);
	map.resize(400, 400);
	map.show();
	return a.exec();
}
