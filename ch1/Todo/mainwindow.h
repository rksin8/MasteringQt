#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>

#include <QtWidgets/QMainWindow>
#include <QVector>
#include "task.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateStatus();


public slots:
    void addTask();
    void removeTask(Task* task);
    void taskStatusChanged(Task* task);

private:
    Ui::MainWindow *ui;
    QVector<Task*> tasks_;
};

#endif // MAINWINDOW_H