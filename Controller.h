#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "RenderView.h"

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(RenderView* renderView READ renderView WRITE setRenderView NOTIFY renderViewChanged)

public:
    explicit Controller(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE void loadFile(const QUrl &url);

    RenderView* renderView() const;
    void setRenderView(RenderView *renderView);

signals:
    void renderViewChanged(RenderView *renderView);

private:
    RenderView *_renderView;
};

#endif // CONTROLLER_H
