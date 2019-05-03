#pragma once

#include <QWidget>
#include <QDialog>
#include "ui_Dialog.h"


class Dialog : public QWidget // QDialog
{
	Q_OBJECT
public:

	void setV(const QString &value);
public:
	Dialog(QWidget *parent = Q_NULLPTR);
	~Dialog();

private:
	Ui::Dialog ui;
	
};
