#include "header.h"

Counter::Counter() : QObject()
                   , Count(0)
{
}

void Counter::slotInc()
{
    ++Count;
    QString str[] = {"","Num 1","Numb 2","Num 3","Numb 4","Num 5"};
    emit labelChange(str[Count]);

    if (Count == 5) {
        emit Exit();
    }
}
