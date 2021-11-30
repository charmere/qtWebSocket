#include "serverWidget.h"

Server::Server() {

	setWindowTitle("client");
	setFixedSize(500, 309);

	layout->addWidget(addrLabel, 0, 0, 1, 1);

	QString addr = "0.0.0.0";
	addrLineEdit->setText(addr);
	layout->addWidget(addrLineEdit, 0, 1, 1, 2);
	layout->addWidget(portLabel, 0, 3, 1, 1);
	QString port = "50001";
	portLineEdit->setText(port);
	layout->addWidget(portLineEdit, 0, 4, 1, 2);
	layout->addWidget(listen, 0, 6, 1, 1);

	layout->addWidget(msgSend, 1, 0, 1, 6);
	layout->addWidget(sendButton, 1, 6, 1, 1);

	showRecvMsg->setEnabled(false);
	layout->addWidget(showRecvMsg, 2, 0, 3, 6);
	setStyleSheet("background-color:white;");

	m_s = new QTcpServer();

	connect(listen, &QPushButton::clicked, this, [=](bool){
		unsigned short port = portLineEdit->text().toUShort();
		m_s->listen(QHostAddress::Any, port);
		qDebug() << m_s->isListening();
		showRecvMsg->append("start listening");

	});

	connect(m_s, &QTcpServer::newConnection, this, [=]() {
		m_tcp = m_s->nextPendingConnection();
		showRecvMsg->append("has client connect");

		connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
		{
			QByteArray data = m_tcp->readAll();
			showRecvMsg->append("客户端say: " + data);
		});
		connect(m_tcp, &QTcpSocket::disconnected, this, [=]()
		{
			m_tcp->close();
			m_tcp->deleteLater();   // delete m_tcp
		});
	});

	connect(sendButton, &QPushButton::clicked, this, [=](bool ){
		QByteArray txt = msgSend->text().toUtf8();
		m_tcp->write(txt);
	});

}

//void Server::sendMegEvent() {
//	QString msg = ui->msg->toPlainText();
//	m_tcp->write(msg.toUtf8());
//	ui->record->append("服务器say: " + msg);
//}


