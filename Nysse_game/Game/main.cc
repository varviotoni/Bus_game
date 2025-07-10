#include <QApplication>
#include "mainwindow.hh"
#include "startdialog.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);

    GameSide::StartDialog d;
    auto icity = GameSide::createGame();

    std::shared_ptr<GameSide::City> city =
            std::dynamic_pointer_cast<GameSide::City>(icity);

    GameSide::MainWindow w(&d);


    d.open();
    w.show();

    

    return a.exec();
}
