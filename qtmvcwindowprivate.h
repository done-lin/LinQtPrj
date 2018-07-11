#ifndef QTMVCWINDOWPRIVATE_H
#define QTMVCWINDOWPRIVATE_H
#include <QObject>
#include <QWidget>
#include "qtmvcwindow.h"

class QtMVCWindowPrivate : public QObject
{
    Q_OBJECT
public:
    explicit QtMVCWindowPrivate(QtMVCWindow *parent);
    void test_visiting_q_ptr(void);
    int mIntTestVarPrivate;
signals:

public slots:

private:
    QtMVCWindow * const q_ptr;
    Q_DECLARE_PUBLIC(QtMVCWindow)
};

#endif // QTMVCWINDOWPRIVATE_H
