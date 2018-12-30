#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtfirst.h"
#include"System.h"
class Qtfirst : public QMainWindow
{
	Q_OBJECT

public:
	Qtfirst(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtfirstClass ui;
	System S;
private slots:
	void on_searchflight_clicked();
	void on_managerlogin_clicked();
};
