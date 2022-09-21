#include "../choosekeys.h"
#include "../fileplaintextedit.h"
#include "../keys.h"
#include "ui_choosekeys.h"
#include <QDebug>
#include <QPointer>
#include <QtTest/QtTest>
class Test : public QObject {
  Q_OBJECT
public:
  FilePlainTextEdit text;
  QPointer<ChooseKeys> choose_keys;
  Keys hot_keys;
private slots:
  /*void test_keys_constructor_test_data () {
       QTest::addColumn<Qt::Key>("StartKeys");
       QTest::newRow (Qt::Key_O)

  }*/
  void initTestCase() {
    hot_keys = Keys();
    choose_keys = new ChooseKeys(&hot_keys);
  }
  void chooseKeysTest_data() {
    QTest::addColumn<QRadioButton *>("Buttons");
    QTest::addColumn<int>("Keys");
    QTest::addColumn<QPlainTextEdit *>("Fields");
    for (int i = 0x41; i < 0x5b; i += 4) {
      QTest::newRow((std::to_string(i - 0x40)).data())
          << choose_keys->ui->save_as << i << choose_keys->ui->save_as_keys;
      QTest::newRow((std::to_string(i + 1 - 0x40)).data())
          << choose_keys->ui->save << i + 1 << choose_keys->ui->save_keys;
      QTest::newRow((std::to_string(i + 2 - 0x40)).data())
          << choose_keys->ui->open << i + 2 << choose_keys->ui->open_keys;
      QTest::newRow((std::to_string(i + 3 - 0x40)).data())
          << choose_keys->ui->quit << i + 3 << choose_keys->ui->quit_keys;
    }
  }
  void chooseKeysTest() {
    QFETCH(QRadioButton *, Buttons);
    QFETCH(int, Keys);
    QFETCH(QPlainTextEdit *, Fields);
    QTest::mouseClick(Buttons, Qt::LeftButton);
    QTest::keyClick(choose_keys, static_cast<Qt::Key>(Keys),
                    Qt::ControlModifier);
    choose_keys->keysForUser();
    char c = Keys;
    QString s("Cntr+");
    s += c;
    QTRY_COMPARE_WITH_TIMEOUT(Fields->toPlainText(), s, 10);
  }
  void test_text_input() {
    QTest::keyClicks(&text, "hello world");
    QCOMPARE(text.toPlainText(), "hello world");
  }
  void test_untitled_flag() { QVERIFY(text.untitled_flag_); }
  void cleanUpTestCase() {
    QDir d("keys");

    qDebug() << d.exists() << d.absolutePath() << d.dirName();
    d.removeRecursively();
  }
};

QTEST_MAIN(Test)
#include "test.moc"
