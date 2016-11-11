#include "canvasconnection.h"
#include <QTextCodec>
#include <iostream>
#include <QtNetwork>

canvasConnection::canvasConnection(QObject *parent) :
    QObject(parent)
{
    m_pNetworkManager = new QNetworkAccessManager(this);
    m_pNetworkReply = NULL;
}

//Send network requests
void canvasConnection::sendRequest(const QString &strUrl)
{
	// create custom temporary event loop on stack
    QEventLoop eventLoop;
	//Open a file
	QFile file("out.json");
    m_strUrl = strUrl;
    QNetworkRequest netRequest;
    //Set the information of url.
    netRequest.setUrl(QUrl(strUrl));
    //Posts a request to obtain the contents of the target request and
    //returns a new QNetworkReply object opened for reading which emits the readyRead() signal whenever new data arrives.
    m_pNetworkReply =m_pNetworkManager->get(netRequest);
    //Signal when the network requests end
    QObject::connect(m_pNetworkManager,SIGNAL(finished(QNetworkReply*)),&evenLoop,SLOT(quit()));
	// blocks stack until "finished()" has been called
	eventLoop.exec();
	QTextStream out(&file);
    if (m_pNetworkReply->error() == QNetworkReply::NoError) {
        // success
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        file.write(m_pNetworkReply->readAll());
        qDebug() << "Success" <<m_pNetworkReply->readAll();
        delete m_pNetworkReply;
    }
    else {
        //failure
        qDebug() << "Failure" ;
        delete reply;
    }
}
