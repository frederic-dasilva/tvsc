#include "tvsc.h"
#include "ui_tvsc.h"
#include "tvscmodel.h"
tvsc::tvsc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tvsc)
{
    ui->setupUi(this);
    tvscmodel m;
}

tvsc::~tvsc()
{
    delete ui;
}
