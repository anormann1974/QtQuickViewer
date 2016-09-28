#include "Controller.h"
#include <QLoggingCategory>
#include <QDebug>
#include <QUrl>
#include <osgDB/ReadFile>

namespace {
QLoggingCategory lc("Controller");
}

Controller::Controller(QObject *parent)
    : QObject(parent)
{
}

void Controller::loadFile(const QUrl &url)
{
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
