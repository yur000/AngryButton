#include "header.h"

Counter::Counter() : QObject()
                   , Count(0)
{
}

void Counter::slotInc()
{
    ++Count;
    if (Count == 6) {
        emit Exit();
    }
    QString str[] = {"","Еще!","Давай, давай!","Не надоело ли?","Может уже хватит?","СЧА ВЗОРВУСЬ!!!",""};
    emit labelChange(str[Count]);
}
