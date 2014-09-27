#ifndef TVSC_H
#define TVSC_H

#include <QMainWindow>

namespace Ui {
class tvsc;
}

class tvsc : public QMainWindow
{
    Q_OBJECT

public:
    explicit tvsc(QWidget *parent = 0);
    ~tvsc();

private:
    Ui::tvsc *ui;
};

#endif // TVSC_H
