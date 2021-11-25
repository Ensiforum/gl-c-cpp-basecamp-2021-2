#ifndef CREATECHATFORM_H
#define CREATECHATFORM_H

#include <QDialog>

namespace Ui {
class CreateChatForm;
}

class CreateChatForm : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChatForm(QWidget *parent = nullptr);
    ~CreateChatForm();

private:
    Ui::CreateChatForm *ui;
};

#endif // CREATECHATFORM_H
