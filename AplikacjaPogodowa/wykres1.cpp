#include "wykres1.h"

Wykres1::Wykres1(QWidget* parent) : QFrame(parent)
{
    _wWyglad = new QVBoxLayout(this);
    Q_CHECK_PTR(_wWyglad);
}


Wykres1::~Wykres1()
{
    _wWyglad ->removeWidget(_wTytul);
    _wWyglad ->removeWidget(_wZachDzien);
    delete _wTytul;
    delete _wZachDzien;
    delete _wWyglad;
}


void Wykres1::DodajTytulIWykres(QString tytul, Miasto* miasto)
{
    _wTytul = new QLabel(this);
    Q_CHECK_PTR(_wTytul);
    _wZachDzien = new QCustomPlot(this);
    Q_CHECK_PTR(_wZachDzien);
    _wZachDzien -> addGraph();
    _wZachDzien -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachDzien -> xAxis -> setLabel(tr("Hour"));
    _wZachDzien -> xAxis -> setRange(0, 48);
    _wZachDzien -> yAxis -> setLabel(tr("Temperature (°F)"));
    _wZachDzien -> graph(0) -> setLineStyle(QCPGraph::lsStepCenter);
    QVector<double> x0(49), y0(49);
    QVector<double> x1(49), y1(49);

    for(int i = 0; i < 49; ++i) {
        x0[i] = x1[i] = i;
        y0[i] = miasto -> GodzinoweDane(i, "temperature").toDouble();

        if(ymax < y0[i]) ymax = y0[i];

        if(ymin > y0[i]) ymin = y0[i];

        y1[i] = miasto -> GodzinoweDane(i, "humidity").toDouble();
    }

    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachDzien -> yAxis -> setRange((int)ymin, (int)ymax);
    _wZachDzien -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachDzien -> graph(0) -> setData(x0, y0);
    //_wZachDzien -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachDzien -> graph(1) -> setData(x1, y1);
    _wTytul -> setText(tytul);
    _wTytul -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _wWyglad -> addWidget(_wTytul);
    _wWyglad -> setAlignment(_wTytul, Qt::AlignRight);
    _wWyglad -> addWidget(_wZachDzien);
}
