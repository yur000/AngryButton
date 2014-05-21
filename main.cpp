#include "header.h"
#include <QApplication>
#include <QCursor>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QString>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    // Init
    QApplication app(argc, argv);
    QWidget      wgt;
    QLabel      *text = new QLabel("Хэй!");
    QPushButton *abut = new QPushButton("Push me!");
    QBoxLayout  *Layout = new QBoxLayout(QBoxLayout::TopToBottom);
    Counter     counter;

    // Building window
    Layout->addWidget(text, 0,Qt::AlignCenter);
    Layout->setMargin(10);
    Layout->addWidget(abut);
    wgt.setLayout(Layout);
    wgt.resize(200, 100);
    wgt.setWindowTitle("Angry Button");
    wgt.show();

    // Connecting SLOTs and SIGNALs
    QObject::connect(abut, SIGNAL(clicked()),
                     &counter, SLOT(slotButton())
                    );

    QObject::connect(&counter, SIGNAL(labelChange(QString)),
                     text, SLOT(setText(QString))
                    );

    QObject::connect(&counter, SIGNAL(exit()),
                     &app, SLOT(quit())
                     );

    return app.exec();
}
