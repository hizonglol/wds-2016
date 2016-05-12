#ifndef MAPA_H
#define MAPA_H

#include <QObject>
#include <QLabel>
#include <QDebug>
#include <QGridLayout>
#include <QResizeEvent>

class Mapa : public QWidget
{
    Q_OBJECT
public:
    explicit Mapa(QWidget *parent = nullptr);

    virtual void resizeEvent(QResizeEvent *event);

signals:

public slots:

private:
    QGridLayout *_wWyglad;
    QPixmap _PlikMapy;
    QLabel *_wMapa;
};

#endif // MAPA_H
