#ifndef COPYCATWINDOW_H
#define COPYCATWINDOW_H
#include "ui_CopyCAT.h"
#include "worker.h"

class CopyCATWindow : public QDialog {
    Q_OBJECT
public:
    explicit CopyCATWindow(QWidget *parent = nullptr);
private:
    Ui::Dialog ui;
};

#endif