#ifndef OKNOZZAKLADKAMI_H
#define OKNOZZAKLADKAMI_H

#include <QTabWidget>
#include <QString>

class OknoZZakladkami : public QTabWidget
{
    Q_OBJECT
public:
    explicit OknoZZakladkami(QWidget *parent = 0);
    void addTab(QTabWidget *tabWidget, QString title);
signals:

public slots:
};

#endif // OKNOZZAKLADKAMI_H
