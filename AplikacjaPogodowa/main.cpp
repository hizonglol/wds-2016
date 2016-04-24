#include "mainwindow.h"
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(QUrl("https://api.forecast.io/forecast/e0d597789a2dbf7ffbd658e2832b71df/37.8267,-122.423"));
    QNetworkReply *reply(manager.get(request));
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    qDebug(reply->readAll());

    return a.exec();
}
