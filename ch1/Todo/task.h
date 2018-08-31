#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QString title, QWidget *parent = 0);
    bool isCompleted();
    ~Task();

public slots:
    void rename();
    void checked(bool checked);


signals:
    void removed(Task* task);
    void statusChanged(Task* task);



private:
    Ui::Task *ui;
};

#endif // TASK_H
