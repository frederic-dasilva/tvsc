#include "tvscmodel.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFileInfoList>
#include <QDirIterator>
#include <QRegExp>
#include <QString>
#include <QRegularExpression>
#include <QByteArray>
#include <QTime>
#include "tvscepisode.h"

tvscmodel::tvscmodel(QObject *parent) :
    QObject(parent)
{
    const QString path("/home/rift/thalassa/Commun/EZTV/");

    _extension << "avi" << "mkv" << "mp4" << "srt";

    QDirIterator dirIt(path,QDirIterator::Subdirectories);

    while (dirIt.hasNext()) {
        dirIt.next();
        QFileInfo file = QFileInfo(dirIt.filePath());
        if (file.isFile())
            if (_extension.contains(file.suffix())) {
                _files << file;
            }
    }

    QRegularExpression re("(.*)S(\\d+)E(\\d+)");
    foreach (QFileInfo file,_files) {
        QRegularExpressionMatch match = re.match(file.fileName());
        if (match.hasMatch()) {
            tvscepisode::tvscepisodeinfo episode;
            episode._show = match.captured(1).replace("."," ").simplified();
            episode._season = match.captured(2);
            episode._episode = match.captured(3);
            episode._fileInfo = file;

            if(!_show.contains(episode._show)) {
                _show[episode._show] = tvscshow(episode._show,this);
            }
            tvscshow &show = _show[episode._show];
            tvscepisode epi(episode);
            show.addEpisode(epi);

        }
    }


    foreach(const tvscshow &ptr,_show)
    {
        qDebug() << ptr;
    }
}

const tvscshow& tvscmodel::show(QString &str)
{
    return _show[str];
}
