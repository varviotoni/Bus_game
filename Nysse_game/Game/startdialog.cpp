#include "startdialog.hh"
#include "ui_startdialog.h"

#include <QDebug>
#include <QWidget>

namespace GameSide {

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);

    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);

    connect(this, &QDialog::accepted, this, &StartDialog::sendValue);
    qDebug() << "StartDialog";
    connect(ui->choose_difficulty_spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &StartDialog::get_difficulty);



}

StartDialog::~StartDialog()
{
    delete ui;
}



void StartDialog::sendValue()
{
    if (difficulty_level_ == 1){
        emit inputs_accepted("EASY");
    }
    if (difficulty_level_ == 2){
        emit inputs_accepted("NORMAL");
    }
    if (difficulty_level_ == 3){
        emit inputs_accepted("HARD");
    }


}
void StartDialog::get_difficulty(int difficulty_level)
{
    difficulty_level_ = difficulty_level;
    if (difficulty_level_ == 1){
        ui->difficulty_text->setText("EASY");
    }
    if (difficulty_level_ == 2){
        ui->difficulty_text->setText("NORMAL");
    }
    if (difficulty_level_ == 3){
        ui->difficulty_text->setText("HARD");
    }



}

}
