#include "oknozzakladkami.h"

OknoZZakladkami::OknoZZakladkami(QWidget *parent) : QTabWidget(parent)
{

}

void OknoZZakladkami::addTab(QTabWidget *tabWidget, QString title)
{
    QWidget *widget = new QWidget();
    tabWidget -> addTab(widget, title);
}
