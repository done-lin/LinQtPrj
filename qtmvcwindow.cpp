#include "qtmvcwindow.h"
#include "qtmvcwindowprivate.h"
#include "ui_qtmvcwindow.h"
#include "qmsgpack-master/src/msgpackstream.h"
#include "qmsgpack-master/src/msgpack.h"
#include <stream/time.h>
#include <stream/geometry.h>

QtMVCWindow::QtMVCWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtMVCWindow),
    d_ptr(new QtMVCWindowPrivate(this))
{
    ui->setupUi(this);
    mIntTstVar = 88;
    ui->comboBox->setModel(mComboxModel);//关联view和模型
    qDebug("d_ptr->mIntTestVarPrivate: %d", d_ptr->mIntTestVarPrivate);
    qDebug("d_ptr->test_visiting_q_ptr begin");
    d_ptr->test_visiting_q_ptr();
    d_ptr->test_pack_integers();
    d_ptr->test_unpack_string();
}

QtMVCWindow::~QtMVCWindow()
{
    delete ui;
}

void QtMVCWindow::on_pushButton_clicked()
{
    d_ptr->pushbutton_clicked();
}
