#ifndef HEADER_H
#define HEADER_H

#include <QObject>


class Counter : public QObject {
    Q_OBJECT
private:
    int Count;

public:
    Counter();

public slots:
    void slotButton();

signals:
    void exit();
    void labelChange(QString);
};

#endif // HEADER_H
