#ifndef LAT_H
#define LAT_H

#include <QLabel>
#include <QPaintEvent>

enum latstat {
	block,
	space,
	food
};

class lat : public QLabel {
public:
	latstat stat = space;

public:
	using QLabel::QLabel;
	void paintEvent(QPaintEvent *event);
};

#endif	// LAT_H
