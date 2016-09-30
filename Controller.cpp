#include "Controller.h"

#include <QLoggingCategory>
#include <QDebug>
#include <QUrl>
#include <osgDB/ReadFile>

namespace {
QLoggingCategory lc("Controller");

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString tmpBuf;
    QTextStream log(&tmpBuf);

    switch (type)
    {
        case QtDebugMsg:
            log << "[Debug] " << "[" << context.category << "] " << msg << "\n";
            break;
        case QtWarningMsg:
            log << "[Warning] " << "[" << context.category << "] " << msg << "\n";
            break;
        case QtCriticalMsg:
            log << "[Critical] " << "[" << context.category << "] " << msg << "\n";
            break;
        case QtFatalMsg:
            log << "[Fatal] " << "[" << context.category << "] " << msg << "\n";
    }

    DebugStream *debugStream = DebugStream::instance();
    emit debugStream->clientProcessStdout(tmpBuf);

    if (type == QtFatalMsg)
        abort();
}

}

Controller::Controller(QObject *parent)
    : QObject(parent)
    , _handler(new MyNotifyHandler)
{
    qInstallMessageHandler(myMessageOutput);

    DebugStream *debugStream = DebugStream::instance();
    connect(debugStream, &DebugStream::clientProcessStdout, this, &Controller::consoleOuput);

    osg::setNotifyHandler(_handler);
    connect(_handler, &MyNotifyHandler::writeNotify, this, &Controller::consoleOuput);
}

Controller::~Controller()
{
}

void Controller::loadFile(const QUrl &url)
{
    qCDebug(lc) << "loadFile:" << url.toLocalFile();
    const std::string filename(url.toLocalFile().toLocal8Bit().constData());
    osg::Node *node = osgDB::readNodeFile(filename);
    _renderView->setModel(node);
}

RenderView* Controller::renderView() const
{
    return _renderView;
}

void Controller::setRenderView(RenderView *renderView)
{
    if (_renderView == renderView)
        return;

    _renderView = renderView;
    emit renderViewChanged(renderView);
}

void Controller::consoleOuput(QString message)
{
    _console.append(message);
    emit consoleChanged(message);
}
