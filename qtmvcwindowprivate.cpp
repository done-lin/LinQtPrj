#include "qtmvcwindowprivate.h"
#include "qtmvcwindow.h"
#include <QString>
#include <QByteArray>
#include <stdio.h>
#include <stdlib.h>
#include <QtTest>
#include <QDebug>
#include <stream/time.h>
#include <stream/geometry.h>
#include <limits>
#include <qglobal.h>
#include <QVariantList>

QtMVCWindowPrivate::QtMVCWindowPrivate(QtMVCWindow *parent) :
    q_ptr(parent)
{
    mIntTestVarPrivate = 55;
    QStringList tmpList;
    tmpList << "Arial" << "Helvetica" << "Times" << "Courier";
    init_comobx_using_model(tmpList);

    connect(this, SIGNAL(signal_change_combox_model(QByteArray)), this, SLOT(slot_change_combox_model(QByteArray)));
}

void QtMVCWindowPrivate::test_visiting_q_ptr()
{
    if(q_ptr->mIntTstVar){
        qDebug("mIntTstVar: %d",q_ptr->mIntTstVar);
    }
}

void QtMVCWindowPrivate::test_pack_integers()
{
    QByteArray packed;
    MsgPackStream stream(&packed, QIODevice::WriteOnly);
    stream << 0 << 127 << -1 << -31 << 128 << 255 << -33 << -128 << 256;
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    qDebug("%s[%d], first pack is ok ", __FUNCTION__, __LINE__);
    stream << 65535 << -129 << -32768 << 65536;
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    stream << (quint32)4294967295 << -32769 << (qint32)-2147483648;
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    stream << (quint64)4294967296;
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    stream << std::numeric_limits<quint64>::max();
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    stream << (qint64)-2147483649;
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    stream << std::numeric_limits<qint64>::min();
    Q_ASSERT(stream.status() == MsgPackStream::Ok);
    qDebug("%s[%d], bgein to unpack ", __FUNCTION__, __LINE__);


    QVariantList l = MsgPack::unpack(packed).toList();

    Q_ASSERT(l[0].toInt() == 0);
    qDebug("%s[%d]: l[0] %d ", __FUNCTION__, __LINE__, l[0].toInt());
    Q_ASSERT(l[1].toInt() == 127);
    qDebug("%s[%d]: l[1] %d ", __FUNCTION__, __LINE__, l[1].toInt());
    Q_ASSERT(l[2].toInt() == -1);
    qDebug("%s[%d]: l[2] %d ", __FUNCTION__, __LINE__, l[2].toInt());
    Q_ASSERT(l[3].toInt() == -31);
    qDebug("%s[%d]: l[3] %d ", __FUNCTION__, __LINE__, l[3].toInt());
    Q_ASSERT(l[4].toInt() == 128);
    qDebug("%s[%d]: l[4] %d ", __FUNCTION__, __LINE__, l[4].toInt());
    Q_ASSERT(l[5].toInt() == 255);
    qDebug("%s[%d]: l[5] %d ", __FUNCTION__, __LINE__, l[5].toInt());
    Q_ASSERT(l[6].toInt() == -33);
    qDebug("%s[%d]: l[6] %d ", __FUNCTION__, __LINE__, l[6].toInt());
    Q_ASSERT(l[7].toInt() == -128);
    qDebug("%s[%d]: l[7] %d ", __FUNCTION__, __LINE__, l[7].toInt());
    Q_ASSERT(l[8].toInt() == 256);
    qDebug("%s[%d]: l[8] %d ", __FUNCTION__, __LINE__, l[8].toInt());
    Q_ASSERT(l[9].toInt() == 65535);
    qDebug("%s[%d]: l[9] %d ", __FUNCTION__, __LINE__, l[9].toInt());
    Q_ASSERT(l[10].toInt() == -129);
    qDebug("%s[%d]: l[10] %d ", __FUNCTION__, __LINE__, l[10].toInt());
    Q_ASSERT(l[11].toInt() == -32768);
    qDebug("%s[%d]: l[11] %d ", __FUNCTION__, __LINE__, l[11].toInt());
    Q_ASSERT(l[12].toInt() == 65536);
    qDebug("%s[%d]: l[12] %d ", __FUNCTION__, __LINE__, l[12].toInt());
    Q_ASSERT(l[13].toUInt() == 4294967295);
    qDebug("%s[%d]: l[13] %d ", __FUNCTION__, __LINE__, l[13].toInt());
    Q_ASSERT(l[14].toInt() == -32769);
    qDebug("%s[%d]: l[14] %d ", __FUNCTION__, __LINE__, l[14].toInt());

    Q_ASSERT(l[15].toInt() == -2147483648);
    Q_ASSERT(l[16].toLongLong() == 4294967296);
    Q_ASSERT(l[17].toULongLong() == std::numeric_limits<quint64>::max());
    Q_ASSERT(l[18].toLongLong() == -2147483649);
    Q_ASSERT(l[19].toLongLong() == std::numeric_limits<qint64>::min());
    qDebug("%s[%d], unpack finished ", __FUNCTION__, __LINE__);
}

void QtMVCWindowPrivate::test_unpack_string()
{
    QString str = QStringLiteral("msgpack rocks");
    QByteArray packed = MsgPack::pack(str);
    QString str2;

    {
        MsgPackStream stream(packed);
        stream >> str2;
        qDebug("%s[%d], 1 unpack str2: %s", __FUNCTION__, __LINE__, qPrintable(str2));
        Q_ASSERT(str == str2);
    }
    {
        str = QString(QByteArray(32, 'm'));
        packed = MsgPack::pack(str);
        MsgPackStream stream(packed);
        stream >> str2;
        qDebug("%s[%d], 2 unpack str2: %s", __FUNCTION__, __LINE__, qPrintable(str2));
        Q_ASSERT(str == str2);
    }
    {
        str = QString::fromUtf8(QByteArray(128, 's'));
        packed = MsgPack::pack(str);
        MsgPackStream stream(packed);
        stream >> str2;
        qDebug("%s[%d], 3 unpack str2: %s", __FUNCTION__, __LINE__, qPrintable(str2));
        Q_ASSERT(str == str2);
    }
    {
        str = QString(QByteArray(256, 'g'));
        packed = MsgPack::pack(str);
        MsgPackStream stream(packed);
        stream >> str2;
        qDebug("%s[%d], 4 unpack str2: %s", __FUNCTION__, __LINE__, qPrintable(str2));
        Q_ASSERT(str == str2);
    }
}

void QtMVCWindowPrivate::init_comobx_using_model(const QStringList &list)
{
    q_ptr->mComboxModel = new QStringListModel(this);//新建一个模型，
    q_ptr->mComboxModel->setStringList(list);//模型数据是StringList，关联模型和数据

    QModelIndex index = q_ptr->mComboxModel->index(2);//改变comobx中一个值，只要操作模型
    q_ptr->mComboxModel->setData(index, "ABC");//改变一个data，第3项改为显示A,之前显示789

    if (q_ptr->mComboxModel->stringList().indexOf("666") < 0) {//查找模型中的777字符串，如果没查到
        QStringList newlist(q_ptr->mComboxModel->stringList());
        newlist << "777";
        q_ptr->mComboxModel->setStringList(newlist);//往模型添加数据，追加。追加combox的string
    }
}

void QtMVCWindowPrivate::pushbutton_clicked()
{
    QByteArray packed;
    MsgPackStream stream(&packed, QIODevice::WriteOnly);
    QStringList list;
    list << "aaa" << "bbb" << "ccc"<<"ddd";
    stream<<list;

    if(stream.status() == MsgPackStream::Ok){
        qDebug("%s[%d], send msg", __FUNCTION__, __LINE__);
        emit signal_change_combox_model(packed);
    }

}

void QtMVCWindowPrivate::slot_change_combox_model(QByteArray urStream)
{
    QVariantList unpacked = MsgPack::unpack(urStream).toList();
    QStringList unpackedStringList;
    for (QVariantList::iterator j = unpacked.begin(); j != unpacked.end(); j++)
    {
        qDebug() << (*j).toString(); // Print QVariant
        unpackedStringList << (*j).toString();
    }
    qDebug("%s[%d], recv msg", __FUNCTION__, __LINE__);
    q_ptr->mComboxModel->setStringList(unpackedStringList);
}
