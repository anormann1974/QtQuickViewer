#include "DebugStream.h"

void MyNotifyHandler::notify(osg::NotifySeverity severity, const char *message)
{
    QString str;

    switch (severity)
    {
        case osg::ALWAYS:
            str = QString("[Always] [OpenSceneGraph] %1").arg(message);
            break;
        case osg::FATAL:
            str = QString("[Fatal] [OpenSceneGraph] %1").arg(message);
            break;
        case osg::WARN:
            str = QString("[Warning] [OpenSceneGraph] %1").arg(message);
            break;
        case osg::NOTICE:
            str = QString("[Notice] [OpenSceneGraph] %1").arg(message);
            break;
        case osg::INFO:
            str = QString("[Info] [OpenSceneGraph] %1").arg(message);
            break;
        case osg::DEBUG_INFO:
        case osg::DEBUG_FP:
            str = QString("[Debug] [OpenSceneGraph] %1").arg(message);
            break;
        default:
            str = message;
            break;
    }

    emit writeNotify(str);
}

DebugStream* DebugStream::instance()
{
    static DebugStream *handle = new DebugStream();
    return handle;
}
