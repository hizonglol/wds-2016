#ifndef OKNOZZAKLADKAMI_H
#define OKNOZZAKLADKAMI_H

#include "zakladka.h"
#include <QTabWidget>
#include <QString>
#include <QVector>

class OknoZZakladkami : public QTabWidget
{
    Q_OBJECT
public:
    explicit OknoZZakladkami(QWidget *parent = 0);
    void addTab(QTabWidget *tabWidget, QString title);
    Zakladka* getLastTab();
signals:

public slots:

private:
    QVector<Zakladka*> _vwZakladki;
};

#endif // OKNOZZAKLADKAMI_H
