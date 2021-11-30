#include <QApplication>
#include <QPushButton>
//#include <QtNetwork/QTcpSocket>
#include "ui/clientWidget.h"
#include "ui/serverWidget.h"
#include <QWidget>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);

	QWidget *clientWidget = new Client();
	QWidget *serverWidget = new Server();

	QWidget mainWidget;
	auto *layout = new QHBoxLayout;
	layout->addWidget(clientWidget);
	layout->addWidget(serverWidget);
	mainWidget.setLayout(layout);

	mainWidget.show();
	return QApplication::exec();
}
