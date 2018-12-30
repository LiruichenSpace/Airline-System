#include "qtfirst.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Qtfirst w;
	w.show();

	return a.exec();
}
