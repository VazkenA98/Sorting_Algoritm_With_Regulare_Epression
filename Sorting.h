#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sorting.h"
#include"ui_Dialog.h"

class Sorting : public QMainWindow
{
	Q_OBJECT
protected:
	QString strValue;
public:
	QString getID() const;
	void setID(const QString &value);

public:
	Sorting(QWidget *parent = Q_NULLPTR);
public slots:
	void OnCLicked();

	

private:
	Ui::SortingClass ui;
	Ui::Dialog *ui2;
};
