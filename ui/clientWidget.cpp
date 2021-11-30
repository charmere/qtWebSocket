//
// Created by yolo on 2021/11/25.
//

#include "clientWidget.h"

Client::Client() {

	setWindowTitle("client");
	setFixedSize(500, 309);

	layout->addWidget(addrLabel, 0, 0, 1, 1);

	QString addr = "127.0.0.1";
	addrLineEdit->setText(addr);
	layout->addWidget(addrLineEdit, 0, 1, 1, 2);
	layout->addWidget(portLabel, 0, 3, 1, 1);

	QString port = "50001";
	portLineEdit->setText(port);
	layout->addWidget(portLineEdit, 0, 4, 1, 2);
	layout->addWidget(connectServer, 0, 6, 1, 1);
	layout->addWidget(msgSend, 1, 0, 1, 6);
	layout->addWidget(sendButton, 1, 6, 1, 1);

	showRecvMsg->setEnabled(false);
	layout->addWidget(showRecvMsg, 2, 0, 1, 6);

	setStyleSheet("background-color:white;");

	m_tcp = new QTcpSocket;

	connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
	{
		QByteArray data = m_tcp->readAll();
		showRecvMsg->append(data);
	});


	connect(connectServer, &QPushButton::clicked, this, [=](bool){
		QString ip = addrLineEdit->text();
		unsigned short port = portLineEdit->text().toUShort();
		qDebug() << ip << port;
		m_tcp->connectToHost(QHostAddress(ip), port);

	});

	connect(m_tcp, &QTcpSocket::connected, this, [=](){
		QString ip = addrLineEdit->text();
		QString port = portLineEdit->text();
		showRecvMsg->append("connect to " + ip + port);
	});

	connect(sendButton, &QPushButton::clicked, this, [=](bool ){
		QByteArray txt = msgSend->text().toUtf8();
		m_tcp->write(txt);

	});

}



