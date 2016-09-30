#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "RenderView.h"
#include "DebugStream.h"

namespace osg {
class NotifyHandler;
}

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RenderView* renderView READ renderView WRITE setRenderView NOTIFY renderViewChanged)
    Q_PROPERTY(QString console READ console NOTIFY consoleChanged)

public:
    explicit Controller(QObject *parent = Q_NULLPTR);
    virtual ~Controller();

    Q_INVOKABLE void loadFile(const QUrl &url);

    RenderView* renderView() const;
    void setRenderView(RenderView *renderView);
    void consoleOuput(QString message);
    const QString& console() const { return _console; }

signals:
    void renderViewChanged(RenderView *renderView);
    void consoleChanged(const QString& message);

private:
    RenderView *_renderView;
    QString _console;
    MyNotifyHandler *_handler;
};

#endif // CONTROLLER_H
