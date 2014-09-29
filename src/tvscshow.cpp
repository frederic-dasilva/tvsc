#include "tvscshow.h"
#include <QDebug>


tvscshow::tvscshow(QObject *parent)
    :_name(QString::null),_parent(parent)
{
 _ptvdbclient = new Tvdb::Client(parent);
}

tvscshow::tvscshow(QString &name,QObject *parent)
    :_name(name),_parent(parent)
{
   _ptvdbclient = new Tvdb::Client(parent);
}


const bool tvscshow::isValid() const
{

}

const QString& tvscshow::name() const
{
    return _name;
}

bool tvscshow::operator==(const tvscshow &one)
{
    return (one.name() == name());
}

const QList<tvscepisode> tvscshow::episodes() const
{
    return _episodes;
}

void tvscshow::addEpisode(tvscepisode &episode)
{
    _episodes << episode;
}


QDebug operator<< (QDebug d, const tvscshow &model) {
    d << model.name();
    const QList<tvscepisode> list = model.episodes();
    foreach(tvscepisode ptr,list) {
        qDebug() << ptr;
    }

    return d;
}
