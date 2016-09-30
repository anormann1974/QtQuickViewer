#ifndef DEBUGSTREAM_H
#define DEBUGSTREAM_H

#include <QObject>
#include <osg/Notify>

class DebugStream : public QObject
{
    Q_OBJECT

public:
    static DebugStream* instance();

private:
    DebugStream() {}

signals:
    void clientProcessStdout(QString s);
};

class MyNotifyHandler : public QObject, public osg::NotifyHandler
{
    Q_OBJECT
public:
    virtual void notify(osg::NotifySeverity severity, const char *message);

signals:
    void writeNotify(QString msg);
};

#endif // DEBUGSTREAM_H
