#include "Controller.h"
#include <QLoggingCategory>
#include <QDebug>
#include <QUrl>

namespace {
QLoggingCategory lc("Controller");
}

Controller::Controller(QObject *parent) : QObject(parent)
{

}

void Controller::loadFile(const QUrl &url)
{
    qCDebug(lc) << "Loading file:" << url << url.toLocalFile();
}
