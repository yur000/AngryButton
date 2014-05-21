#include "header.h"

Counter::Counter() : QObject()
                   , Count(0)
{
}

void Counter::slotButton()
{
    ++Count;                        // Counting pushes
    if (Count == 6) {
        emit exit();                // If button pushed 6 times - send signal
    }
    QString str[] = {"",
                     "Еще!",
                     "Давай, давай!",
                     "Не надоело ли?",
                     "Может уже хватит?",
                     "СЧА ВЗОРВУСЬ!!!",
                     ""
                    };
    emit labelChange(str[Count]);    // Send signal with text
}
