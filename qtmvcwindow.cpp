#include "qtmvcwindow.h"
#include "qtmvcwindowprivate.h"
#include "ui_qtmvcwindow.h"

QtMVCWindow::QtMVCWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtMVCWindow),
    d_ptr(new QtMVCWindowPrivate(this))
{
    ui->setupUi(this);
    mIntTstVar = 88;
    qDebug("d_ptr->mIntTestVarPrivate: %d", d_ptr->mIntTestVarPrivate);
    qDebug("d_ptr->test_visiting_q_ptr begin");
    d_ptr->test_visiting_q_ptr();
}

QtMVCWindow::~QtMVCWindow()
{
    delete ui;
}
