#ifndef RENDERVIEW_H
#define RENDERVIEW_H

#include <QQuickFramebufferObject>
#include <osg/Node>

class RenderView : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    class PendingEvents;

    RenderView();
    virtual ~RenderView();

    Renderer* createRenderer() const Q_DECL_OVERRIDE;

    osg::Node* model() const;
    void setModel(osg::Node *node);

    PendingEvents& pendingEvents();

signals:
    void modelChanged(osg::Node *node);

protected:
    QSGNode* updatePaintNode(QSGNode *, UpdatePaintNodeData *) Q_DECL_OVERRIDE;

    void geometryChanged(const QRectF& newGeometry, const QRectF& oldGeometry) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private:
    QScopedPointer<PendingEvents> _pendingEvents;
    osg::ref_ptr<osg::Node> _model;
};

#endif // RENDERVIEW_H
