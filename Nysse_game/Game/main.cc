#include <QApplication>
#include "mainwindow.hh"
#include "startdialog.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    GameSide::StartDialog d;

    GameSide::MainWindow w(&d);

    w.show();

    d.open();

    return a.exec();
}
