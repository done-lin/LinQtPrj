#include "qtmvcwindowprivate.h"
#include "qtmvcwindow.h"
#include <QDebug>

QtMVCWindowPrivate::QtMVCWindowPrivate(QtMVCWindow *parent) :
    q_ptr(parent)
{
    mIntTestVarPrivate = 55;
}

void QtMVCWindowPrivate::test_visiting_q_ptr()
{
    if(q_ptr->mIntTstVar){
        qDebug("mIntTstVar: %d",q_ptr->mIntTstVar);
    }
}
