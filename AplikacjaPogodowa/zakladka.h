#ifndef ZAKLADKA_H
#define ZAKLADKA_H

#include <QWidget>
#include <QGridLayout>

class Zakladka : public QWidget
{
    Q_OBJECT
public:
    explicit Zakladka(QWidget *parent = 0);
    QGridLayout _Layout;

signals:

public slots:
};

#endif // ZAKLADKA_H
