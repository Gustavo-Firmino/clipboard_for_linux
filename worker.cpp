#include "worker.h"
#include <QThread>

Worker::Worker(QObject *parent) : QObject(parent)
{
}

void Worker::doWork()
{


    emit finished();
}