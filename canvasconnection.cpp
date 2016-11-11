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
    m_strUrl = strUrl;
    QNetworkRequest netRequest;
    netRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    //Set the information of url.
    netRequest.setUrl(QUrl(strUrl));
    //If the requests is https,we need ssl to support.
//    if(strUrl.toLower().startsWith("https"))
//    {
//        QSslConfiguration sslConfig;
//        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
//        sslConfig.setProtocol(QSsl::TlsV1_1);
//        netRequest.setSslConfiguration(sslConfig);
//    }
    //QString strBody;
    //QByteArray contentByteArray = strBody.toLatin1();
    //post request
    //m_pNetworkReply = m_pNetworkManager->post(netRequest,contentByteArray);
    //Posts a request to obtain the contents of the target request and
    //returns a new QNetworkReply object opened for reading which emits the readyRead() signal whenever new data arrives.
    m_pNetworkReply =m_pNetworkManager->get(netRequest);
    //Signal when the network requests end
    connect(m_pNetworkManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotreply()));
}

//network requests end
void canvasConnection::slotreply()
{
    QByteArray resultContent = m_pNetworkReply->readAll();
    QTextCodec* pCodec = QTextCodec::codecForName("UTF-8");
    QString strResult = pCodec->toUnicode(resultContent);
    int nHttpCode = m_pNetworkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //Status codes in HTTP
    //success
    if(nHttpCode == 200)
    {
        std::cout<<"success" ;
     //   emit signal_requestFinished(true,strResult);//请求成功
    }
    else
    {
        std::cout<<"fail" << endl;
      //  emit signal_requestFinished(false,strResult);//请求失败
    }
    m_pNetworkReply->deleteLater();
    this->deleteLater(); //释放内存
}
