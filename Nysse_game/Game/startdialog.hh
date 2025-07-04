#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>

namespace Ui {
class StartDialog;
}

namespace GameSide {

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

public slots:

    void sendValue();
    void get_difficulty(int difficulty);

signals:

    void inputs_accepted(std::string difficulty_level);


private:
    Ui::StartDialog *ui;
    int difficulty_level_ = 1;
};

}
#endif // STARTDIALOG_HH
