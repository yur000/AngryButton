#include "header.h"
#include <QApplication>
#include <QCursor>
#include <QLabel>
#include <QPushButton>
#include <QLayout>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;
    QLabel      *text = new QLabel;
    QPushButton *abut = new QPushButton("Push me!");
    QBoxLayout  *Layout = new QBoxLayout(QBoxLayout::TopToBottom);

    Layout->addWidget(text,1);
    Layout->addWidget(abut,2);
    wgt.setLayout(Layout);
    wgt.resize(180, 100);
    wgt.show();

    return app.exec();
}
