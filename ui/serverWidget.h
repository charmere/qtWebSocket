//
// Created by yolo on 2021/11/25.
//

#ifndef QTWEBSOCKET_SERVERWIDGET_H
#define QTWEBSOCKET_SERVERWIDGET_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QDebug>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGridLayout>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QTextEdit>
#include <QByteArray>

class Server: public QWidget{
	Q_OBJECT
public:
	Server();
//	void sendMegEvent();

public:
	QLabel *addrLabel = new QLabel("addr:", this);
	QLineEdit *addrLineEdit = new QLineEdit(this);

	QPushButton *listen = new QPushButton("listen", this);

	QLabel *portLabel = new QLabel("port:", this);
	QLineEdit *portLineEdit = new QLineEdit(this);

	QLineEdit *msgSend = new QLineEdit(this);
	QPushButton *sendButton = new QPushButton("send", this);

	QTextEdit *showRecvMsg = new QTextEdit(this);

	QGridLayout *layout = new QGridLayout(this);

	QTcpServer *m_s;
	QTcpSocket *m_tcp;

};


#endif //QTWEBSOCKET_SERVERWIDGET_H
