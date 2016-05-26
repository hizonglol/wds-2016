#include "zakladkamiasta.h"


ZakladkaMiasta::ZakladkaMiasta(QString nazwa, QWidget *parent) : QWidget(parent)
{
    _wWyszukiwarka = new WyszukiwarkaMiasta();

    _wMiasto = new Miasto(/*nazwa*/);
    _wWyglad = new QGridLayout(this);



    pierwszy_rzad();
    drugi_rzad();
    trzeci_rzad();

    this -> setLayout(_wWyglad);
    this -> show();
}

void ZakladkaMiasta::pierwszy_rzad(){

  _wIkZach = new QLabel(this);
  _wTemper = new QLCDNumber(this);
  _wPrawdop = new QLCDNumber(this);
  _wTekOpis = new QLabel(this);

  _wIkZach -> setText(_wMiasto -> teraz_dane("icon").toString());
  _wTemper -> display(_wMiasto -> teraz_dane("temperature").toDouble());
  _wPrawdop -> display(_wMiasto -> teraz_dane("precipProbability").toDouble());
  _wTekOpis -> setText(_wMiasto -> teraz_dane("summary").toString());

  _wWyglad -> addWidget(_wIkZach, 0, 0);
  _wWyglad -> addWidget(_wTemper, 0, 1);
  _wWyglad -> addWidget(_wPrawdop, 0, 2);
  _wWyglad -> addWidget(_wTekOpis, 0, 3, 1, 2);

}

void ZakladkaMiasta::drugi_rzad(){

  _wZachDzien = new QCustomPlot(this);
  _wZachDzien -> addGraph();
  _wZachDzien -> addGraph();
  double ymin = 200;
  double ymax = -200;
  _wZachDzien -> xAxis -> setLabel(tr("godzina"));
  _wZachDzien -> xAxis -> setRange(0, 48);
  _wZachDzien -> yAxis -> setLabel(tr("temperatura"));
  _wZachDzien -> graph(0) -> setLineStyle(QCPGraph::lsStepCenter);

  QVector<double> x2_0(49), y2_0(49);
  QVector<double> x2_1(49), y2_1(49);
  for(int i=0; i<49; ++i){
      x2_0[i] = x2_1[i] = i;
      y2_0[i] = _wMiasto -> godzin_dane(i, "temperature").toDouble();
      if (ymax < y2_0[i]) ymax = y2_0[i];
      if (ymin > y2_0[i]) ymin = y2_0[i];
      y2_1[i] = _wMiasto -> godzin_dane(i, "humidity").toDouble();
  }
  ymin = ymin - 1;
  ymax = ymax + 1;
  _wZachDzien -> yAxis -> setRange((int)ymin, (int)ymax);

  _wZachDzien -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
  _wZachDzien -> graph(0) -> setData(x2_0, y2_0);
  //_wZachDzien -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
  //_wZachDzien -> graph(1) -> setData(x2_1, y2_1);

  _wWyglad -> addWidget(_wZachDzien, 1, 0, 1, 5);
}

void ZakladkaMiasta::trzeci_rzad(){

  _wZachTydz = new QCustomPlot(this);
  _wZachTydz -> addGraph();
  _wZachTydz -> addGraph();
  double ymin = 200;
  double ymax = -200;
  _wZachTydz -> xAxis -> setLabel(tr("dzien"));
  _wZachTydz -> xAxis -> setRange(0, 7);
  _wZachTydz -> yAxis -> setLabel(tr("temperatura"));
  _wZachTydz -> graph(0) -> setLineStyle(QCPGraph::lsStepLeft);

  QVector<double> x3_0(8), y3_0(8);
  QVector<double> x3_1(8), y3_1(8);
  for(int i=0; i<8; ++i){
      x3_0[i] = x3_1[i] = i;
      y3_0[i] = _wMiasto -> dzien_dane(i, "temperatureMax").toDouble();
      if (ymax < y3_0[i]) ymax = y3_0[i];
      if (ymin > y3_0[i]) ymin = y3_0[i];
      y3_1[i] = _wMiasto -> dzien_dane(i, "humidity").toDouble();
  }
  ymin = ymin - 1;
  ymax = ymax + 1;
  _wZachTydz -> yAxis -> setRange((int)ymin, (int)ymax);

  _wZachTydz -> graph(0) -> setPen(QPen(QColor(255, 100, 100)));
  _wZachTydz -> graph(0) -> setData(x3_0, y3_0);
  //_wZachTydz -> graph(0) -> setPen(QPen(QColor(100, 255, 100)));
  //_wZachTydz -> graph(1) -> setData(x3_1, y3_1);


  _wWyglad -> addWidget(_wZachTydz, 2, 0, 1, 5);
}
