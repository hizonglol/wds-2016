#ifndef MAPA_H
#define MAPA_H

#include <QObject>
#include <QLabel>
#include <QDebug>

class Mapa : public QLabel
{
    Q_OBJECT
public:
    explicit Mapa(QWidget *parent = nullptr);

signals:

public slots:

private:
    QPixmap _PlikMapy;
    //QLabel *_wMapa;
};

#endif // MAPA_H
