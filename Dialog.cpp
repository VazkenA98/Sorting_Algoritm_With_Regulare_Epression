#include "Dialog.h"
#include "Sorting.h"

Dialog::Dialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//Sorting s;
	//QString str = s.getID();
	//ui.labelDialog->setText(str);

	ui.labelDialog->setStyleSheet("QLineEdit{ "
		"background-color: rgb(64, 191, 128);"
		"border: 2px solid gray;"
		"border-radius: 10px;"
		"padding: 0 8px;"
		"selection-background-color: yellow;"
		"font-size: 24px;}"

	);
}
void Dialog::setV(const QString &value) {
	ui.labelDialog->setText(value);
}

Dialog::~Dialog()
{
	
}
