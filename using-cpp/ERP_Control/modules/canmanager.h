#ifndef CANMANAGER_H
#define CANMANAGER_H

#include <QObject>
#include <QtSerialBus/QCanBus>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QThread>

class CanManager : public QThread
{
    Q_OBJECT

public:
    explicit CanManager(QObject *parent = nullptr);
    Q_PROPERTY(QString TextArea  READ TextArea WRITE setTextArea NOTIFY TextAreaChanged)
    Q_PROPERTY(QString frameID   READ frameID WRITE setFrameID NOTIFY frameIDChanged)
    Q_PROPERTY(QString frameData READ frameData WRITE setFrameData NOTIFY frameDataChanged)

    Q_INVOKABLE void setTextArea(const QString &);
    Q_INVOKABLE void buttontest();

    bool loadConf(const QString &path);
    void connectDevice();
    void disconnectDevice();
//    void sendRawFrame(const QCanBusFrame &frame) const;
    void sendMessege(const QVariantMap &msg) const;
    void processReceivedFrames(); //dbc parsing using GENEVI/CANdb
    void processErrors(QCanBusDevice::CanBusError) const;
    void processFramesWritten(qint64);
    static void sendRawFrame(QCanBusFrame &frame) ;

    QString TextArea() const { return m_TextArea;}
    QString frameID() const { return m_FrameID;}
    QString frameData() const { return m_FrameData;}

    void setFrameID(const QString &frameID);
    void setFrameData(const QString &frameData);




    static QString m_TextArea;


private:
    QCanBusDevice *m_canDevice;
//    QCanBusDevice *send_device;
    static QCanBusDevice *send_device;
    bool bInitiated;
    QJsonObject jsonConfObj;
    qint64 m_numberFramesWritten;
    QVariant bitRate;
    QString pluginName;
    QString deviceInterfaceName;
    QString m_test;

    QString m_FrameID;
    QString m_FrameData;
    QCanBusFrame m_busFrame;



signals:
    void canMessageReceived(const QVariantMap&);
    void TextAreaChanged();
    void frameIDChanged(QString frameID);
    void frameDataChanged(QString frameData);

public slots:
    //Thread
    void run();

};

#endif // CANMANAGER_H

