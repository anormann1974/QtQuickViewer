#include "Controller.h"
#include <QLoggingCategory>
#include <QDebug>
#include <QUrl>
#include <osgDB/ReadFile>

namespace {
QLoggingCategory lc("Controller");

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    QMutexLocker lock(&mutex);

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

    std::wcerr << tmpBuf.toStdWString();

    if (type == QtFatalMsg)
        abort();
}

}

Controller::Controller(QObject *parent)
    : QObject(parent)
{
    qInstallMessageHandler(myMessageOutput);
}

void Controller::loadFile(const QUrl &url)
{
    const std::string filename(url.toLocalFile().toLocal8Bit().constData());
    osg::Node *node = osgDB::readNodeFile(filename);
    _renderView->setModel(node);
    qCDebug(lc) << "loadFile:" << url.toLocalFile() << node;
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
