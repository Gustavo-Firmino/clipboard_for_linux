#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);

    signals:
        void finished();
    void progress(int value);

public slots:
    void doWork();
};

#endif
