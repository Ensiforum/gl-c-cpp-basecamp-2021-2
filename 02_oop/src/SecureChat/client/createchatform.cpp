#include "createchatform.h"
#include "ui_createchatform.h"

CreateChatForm::CreateChatForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateChatForm)
{
    ui->setupUi(this);
}

CreateChatForm::~CreateChatForm()
{
    delete ui;
}
