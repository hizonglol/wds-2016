#include "wykres2.h"

Wykres2::Wykres2(QWidget* parent) : QFrame(parent)
{
    _wWyglad = new QVBoxLayout(this);
}

Wykres2::~Wykres2()
{
    _wWyglad -> removeWidget(_wTytul);
    _wWyglad -> removeWidget(_wZachTydz);
    delete _wTytul;
    delete _wZachTydz;
    delete _wWyglad;
}


void Wykres2::DodajTytulIWykres(QString tytul, Miasto* miasto)
{
    _wTytul = new QLabel(this);
    _wZachTydz = new QCustomPlot(this);
    _wZachTydz -> addGraph();
    _wZachTydz -> addGraph();
    double ymin = 200;
    double ymax = -200;
    _wZachTydz -> xAxis -> setLabel(tr("Day"));
    _wZachTydz -> xAxis -> setRange(0, 7);
    _wZachTydz -> yAxis -> setLabel(tr("Temperature (°F)"));
    _wZachTydz -> graph(0) -> setLineStyle(QCPGraph::lsStepLeft);
    QVector<double> x0(8), y0(8);
    QVector<double> x1(8), y1(8);

    for(int i = 0; i < 8; ++i) {
        x0[i] = x1[i] = i;
        y0[i] = miasto -> TygodnioweDane(i, "temperatureMax").toDouble();

        if(ymax < y0[i]) ymax = y0[i];

        if(ymin > y0[i]) ymin = y0[i];

        y1[i] = miasto -> TygodnioweDane(i, "humidity").toDouble();
    }

    ymin = ymin - 1;
    ymax = ymax + 1;
    _wZachTydz -> yAxis -> setRange((int)ymin, (int)ymax);
    _wZachTydz -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
    _wZachTydz -> graph(0) -> setData(x0, y0);
    //_wZachTydz -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
    //_wZachTydz -> graph(1) -> setData(x1, y1);
    _wTytul -> setText(tytul);
    _wTytul -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _wWyglad -> addWidget(_wTytul);
    _wWyglad -> setAlignment(_wTytul, Qt::AlignRight);
    _wWyglad -> addWidget(_wZachTydz);
}
