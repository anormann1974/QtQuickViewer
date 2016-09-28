#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = Q_NULLPTR);

    Q_INVOKABLE void loadFile(const QUrl &url);

signals:

public slots:
};

#endif // CONTROLLER_H
