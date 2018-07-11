#ifndef QTMVCWINDOW_H
#define QTMVCWINDOW_H

#include <QMainWindow>

namespace Ui {
class QtMVCWindow;
}

class QtMVCWindowPrivate;

class QtMVCWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtMVCWindow(QWidget *parent = 0);
    ~QtMVCWindow();
    int mIntTstVar;
private:
    QtMVCWindowPrivate * const d_ptr;//在公有接口类中定义一个私有的，只读的d_ptr,名字必须是d_ptr
    Q_DECLARE_PRIVATE(QtMVCWindow)//在公有接口的类中，需要private，无论哪个DECLARE都是公有类，只是private和public的区别

    Ui::QtMVCWindow *ui;
};

#endif // QTMVCWINDOW_H
