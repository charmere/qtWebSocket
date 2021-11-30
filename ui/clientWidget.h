//
// Created by yolo on 2021/11/25.
//

#ifndef QTWEBSOCKET_CLIENTWIDGET_H
#define QTWEBSOCKET_CLIENTWIDGET_H

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
#include <QString>
#include <QHostAddress>
#include <QDebug>
#include <QTextEdit>
#include <QByteArray>

class Client : public QWidget{
	Q_OBJECT
public:
	Client();

public:

	QLabel *addrLabel = new QLabel("addr:", this);
	QLineEdit *addrLineEdit = new QLineEdit(this);

	QPushButton *connectServer = new QPushButton("connect", this);

	QLabel *portLabel = new QLabel("port:", this);
	QLineEdit *portLineEdit = new QLineEdit(this);

	QLineEdit *msgSend = new QLineEdit(this);
	QPushButton *sendButton = new QPushButton("send", this);

	QTextEdit *showRecvMsg = new QTextEdit(this);

	QGridLayout *layout = new QGridLayout(this);

	QTcpSocket* m_tcp;
};

#endif //QTWEBSOCKET_CLIENTWIDGET_H
