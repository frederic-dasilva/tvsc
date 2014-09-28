#ifndef TVSCEPISODE_H
#define TVSCEPISODE_H

#include <QObject>
#include <QFileInfo>

class tvscepisode
{


public:
    struct tvscepisodeinfo {
        QString _show;
        QString _season;
        QString _episode;
        QFileInfo _fileInfo;
    };

public:
    tvscepisode();
    explicit tvscepisode(tvscepisodeinfo &info);

    QString season() const { return _info._season; }
    QString episode() const { return _info._episode; }
signals:

public slots:

private:
    tvscepisodeinfo _info;
};

QDebug operator<< (QDebug d, const tvscepisode &model);


#endif // TVSCEPISODE_H
