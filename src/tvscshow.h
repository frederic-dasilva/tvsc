#ifndef TVSCSHOW_H
#define TVSCSHOW_H

#include <QObject>
#include <QDir>
#include "tvscepisode.h"

#include "client.h"

class tvscshow
{

public:

    tvscshow(QObject *parent = NULL);
    tvscshow(QString &name, QObject *parent = NULL);

    const bool isValid() const;

    const QString& name() const;

    bool operator==(const tvscshow &one);

    const QList<tvscepisode> episodes() const;

    void addEpisode(tvscepisode &);
signals:

public slots:

private:
    QString _name;

    QList<tvscepisode> _episodes;

    QObject *_parent;
    Tvdb::Client *_ptvdbclient;
};


QDebug operator<< (QDebug d, const tvscshow &model);


#endif // TVSCSHOW_H
