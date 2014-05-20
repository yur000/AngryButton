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
    QApplication app(argc, argv);
    QWidget      wgt;
    QLabel      *text = new QLabel("Хэй!");
    QPushButton *abut = new QPushButton("Push me!");
    QBoxLayout  *Layout = new QBoxLayout(QBoxLayout::TopToBottom);
    Counter     counter;

    Layout->addWidget(text,1);
    Layout->addWidget(abut,2);
    wgt.setLayout(Layout);
    wgt.resize(180, 100);
    wgt.show();

    QObject::connect(abut, SIGNAL(clicked()),
                     &counter, SLOT(slotInc())
                    );

    QObject::connect(&counter, SIGNAL(labelChange(QString)),
                     text, SLOT(setText(QString))
                    );

    QObject::connect(&counter, SIGNAL(Exit()),
                     &app, SLOT(quit())
                     );

    return app.exec();
}
