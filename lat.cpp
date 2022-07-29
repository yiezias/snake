#include "lat.h"

void lat::paintEvent(QPaintEvent *event) {
	Q_UNUSED(event);
	QPalette label_palette;
	if (stat == space) {
		label_palette.setColor(QPalette::Window,
				       QColor(240, 240, 240));
	} else if (stat == block) {
		label_palette.setColor(QPalette::Window,
				       QColor(255, 0, 0));
	} else if (stat == food) {
		label_palette.setColor(QPalette::Window,
				       QColor(255, 255, 0));
	}
	setAutoFillBackground(true);
	setPalette(label_palette);
}
