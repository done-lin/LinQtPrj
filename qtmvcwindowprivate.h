#ifndef QTMVCWINDOWPRIVATE_H
#define QTMVCWINDOWPRIVATE_H
#include <QObject>
#include <QWidget>
#include "qtmvcwindow.h"
#include "msgpack.h"
#include "msgpackcommon.h"
#include "msgpackstream.h"

class QtMVCWindowPrivate : public QObject
{
    Q_OBJECT
public:
    explicit QtMVCWindowPrivate(QtMVCWindow *parent);
    void test_visiting_q_ptr(void);
    void test_pack_integers(void);
    void test_unpack_string(void);
    void init_comobx_using_model(const QStringList &list);
    void pushbutton_clicked(void);
    int mIntTestVarPrivate;
signals:
    void signal_change_combox_model(QByteArray urStream);
public slots:
    void slot_change_combox_model(QByteArray urStream);
private:
    QtMVCWindow * const q_ptr;
    Q_DECLARE_PUBLIC(QtMVCWindow)
};

#endif // QTMVCWINDOWPRIVATE_H
