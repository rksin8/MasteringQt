#include "task.h"
#include "ui_task.h"

#include <QFont>
#include <QInputDialog>

Task::Task(QString title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    ui->checkBox->setText(title);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->removeButton, &QPushButton::clicked, [this]{ emit removed(this);});

    connect(ui->checkBox, &QCheckBox::toggled, this, &Task::checked);
}

bool Task::isCompleted()
{
    return ui->checkBox->isChecked();
}


Task::~Task()
{
    delete ui;
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          ui->checkBox->text(),
                                          &ok);
    if (ok && !value.isEmpty()){
       ui->checkBox->setText(value);
    }
}

void Task::checked(bool checked)
{
    QFont font(ui->checkBox->font());
    font.setStrikeOut(checked);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}
