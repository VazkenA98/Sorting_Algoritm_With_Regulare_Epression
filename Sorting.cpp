#include "Sorting.h"
#include "Dialog.h"
#include <QIntValidator>
#include<vector>
#include<iostream>
#include<string>
#include <QMessageBox>

using namespace std;


Sorting::Sorting(QWidget *parent)
	: QMainWindow(parent)
{
	

	ui.setupUi(this);
	connect(ui.Sort, SIGNAL(clicked(bool)), this, SLOT(OnCLicked()));

	QRegExp rx("^[0-9,-]*$"); //inputi hamar 0-9 tiver tenes yev , yev - 
	QValidator *validator = new QRegExpValidator(rx, this);
	ui.Inp_box->setValidator(validator);



	ui.label_back->setStyleSheet("QLabel {background: rgba(0, 0, 0, 80);}");
	ui.label_2->setStyleSheet("QLabel {font-size: 16px;}");
	ui.label_3->setStyleSheet("QLabel {font-size: 16px;}");
	ui.label_4->setStyleSheet("QLabel {font-size: 16px;}");
	ui.Inp_box->setStyleSheet("QLineEdit{ "
		"background-color:rgb(128, 223, 255);"
		"border: 2px solid gray;"
		"border-radius: 10px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"font-size: 24px;}"

	);
	ui.Clear_box->setStyleSheet("QLineEdit{ "
		
		"border: 2px solid gray;"

		"border-radius: 10px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"font-size: 24px;}"

	);
	ui.Out_box->setStyleSheet("QLineEdit{ "
		
		"border: 2px solid gray;"

		"border-radius: 10px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"font-size: 24px;}"

	);
	
}

bool func(int a, int b)
{
	return a < b;
}


void Sorting::setID(const QString &value)
{
	strValue = value;
}
QString Sorting::getID() const
{
	return strValue;
}
////On click start ////
void Sorting::OnCLicked() {
	
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 1000000; j++) {
			ui.progressBarr->setValue(i);
		}
	}




	QRegExp rx(","); //RegEx for ',' 
	QStringList list = ui.Inp_box->text().split(rx);
	//..............shedgelu argorithms............
	QVector<int> v;
	QVector<QString> v2;
	QString ss = "";
	int count = 0;
	for (int i = 0; i < list.size(); i++) {
		QString a = list[i];
		if (a.contains("-")) {
			if (a[0] == "-") { //-7-7
				QStringList list2 = a.split("-");
				for (int j = 1; j < list2.size(); j++) {
					v2.push_back("-" + list2[j]);
				}
			}
			if (a[0] != "-") {
				QStringList list2 = a.split("-"); //7-7 
				v2.push_back(list2[0]);
				for (int j = 1; j < list2.size(); j++) {
					v2.push_back("-" + list2[j]);
				}
			}
		}
		else {
			v2.push_back(a);
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		QString ch = v2[i];
		if (ch.length() > 1 && ch[1] == "0" && ch[0] == "-") {
			v2[i] = "0";

		}
		if (ch.length() == 1 && ch[0] == "-") {
			v2[i] = "0";
		}
	}
	//............array mech letsenel vectore vor gernank sort enel.............
	v.resize(v2.size());
	for (int i = 0; i < v2.size(); i++) {
		v[i] = v2[i].toInt();//string to int
	}
	QString str = ""; //debel()
	for (int i = 0; i < v2.size(); i++) {
		QString s = QString::number(v[i]);
		str += "(" + s + ")";
	}
	ui.Clear_box->setText(str);
	//..........shedgelen hedo sort.................
	int i, j;
	for (i = 0; i < v.size(); i++)
		// Last i elements are already in place    
		for (j = 0; j < v.size() - 1; j++) {
			if (v[j] > v[j + 1]) {
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	//......................final answer...........
	QString str2 = "";
	for (int i = 0; i < v.size()-1; i++) {
		QString s = QString::number(v[i]);
		str2 +=   s + ",";
	}
	QString s = QString::number(v[v.size()-1]); //.........asi vor verchin tiven hedo , chi tervi
	str2 += s;





	setID(str2);
	
	ui.Out_box->setText(str2);
	/*QMessageBox msgBox;
	msgBox.setText(str2);
	msgBox.exec();*/
	
	//ui2->labelDialog->setText("sd");
	
	Dialog *d = new Dialog();
	d->setV(str);
	d->show();

}

