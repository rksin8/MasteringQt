#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QInputDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tasks_()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    updateStatus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus()
{
    int completeCount = 0;
    for(auto t : tasks_){
        if(t->isCompleted())
            completeCount++;
    }
    int todoCount = tasks_.size() - completeCount;

    ui->statusLabel->setText(QString("Status: %1 todo / %2 completed").arg(todoCount).arg(completeCount));
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name:"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),
                                         &ok);

    if (ok && !name.isEmpty()){
        qDebug() << "Adding new task:";
        Task* task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        tasks_.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }


}

void MainWindow::removeTask(Task *task)
{
    tasks_.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();

}

void MainWindow::taskStatusChanged(Task* /*task*/)
{
     updateStatus();
}
