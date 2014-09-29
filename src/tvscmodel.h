#ifndef TVSCMODEL_H
#define TVSCMODEL_H

#include <QObject>
#include <QPair>
#include <QFileInfo>
#include <QString>
#include <QMap>

#include "tvscshow.h"

class QDir;


class tvscmodel : public QObject
{
    Q_OBJECT

   // TODO:
   // typedef  QPair<QString, tvshow*> pair;

public:
    explicit tvscmodel(QObject *parent = 0);


signals:

public slots:

private:
    const tvscshow &show(QString &str);

private:
    QStringList _extension;

    QMap<QString,tvscshow> _show;

    QList<QFileInfo> _files;
};

#endif // TVSCMODEL_H
