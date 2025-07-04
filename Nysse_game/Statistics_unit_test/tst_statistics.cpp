#include <QtTest>
#include <QString>
#include "../Course/CourseLib/interfaces/istatistics.hh"
#include "../Game/statistics.hh"


// Unit test for all reasonable and accessible member functions in statistics class.

class statistics : public QObject
{
    Q_OBJECT

public:
    statistics();
    ~statistics();

private slots:
    void make_test_data();
    void test_givePoints();
    void test_passengerDied();
    void test_nysseLeft();

    void test_nysseIsRemoved();
    void test_NoPrey();
    void test_sayAlienIsDead();





};

statistics::statistics()
{

}

statistics::~statistics()
{

}

void statistics::make_test_data()
{

}

void statistics::test_givePoints()
{
    Statistics S("NORMAL");
    QVERIFY2(S.givePoints() == 0, "Wrong points");
}

void statistics::test_passengerDied()
{
    Statistics S("NORMAL");
    S.passengerDied(3);
    QVERIFY2(S.givePoints() == 15, "Wrong update");
}

void statistics::test_nysseLeft()
{
    Statistics S("NORMAL");
    S.nysseLeft();
    QVERIFY2(S.givePoints() == -40, "Wrong Nysse point update");

}

void statistics::test_nysseIsRemoved()
{
    Statistics S("NORMAL");
    S.nysseIsRemoved(3);
    QVERIFY2(S.givePoints() == 30, "Wrong passenger point update" );
}

void statistics::test_NoPrey()
{
    Statistics S("NORMAL");
    S.noPrey();
    QVERIFY2(S.sayAlienIsDead() == false, "Alien died when not supposed to");

}

void statistics::test_sayAlienIsDead()
{
    Statistics S("NORMAL");
    S.sayAlienIsDead();
    QVERIFY2(S.sayAlienIsDead() == false, "Alien died when not supposed to");
}



QTEST_APPLESS_MAIN(statistics)

#include "tst_statistics.moc"
