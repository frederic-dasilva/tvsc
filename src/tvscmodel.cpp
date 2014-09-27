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

tvscmodel::tvscmodel(QObject *parent) :
    QObject(parent)
{
    const QString path("my_path");

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
            QString sShow = match.captured(1).replace("."," ").simplified();
            QString sSeason = match.captured(2);
            QString sEpisode = match.captured(3);

            if(!_show.contains(sShow)) {
                _show[sShow] = new tvscshow(sShow,this);
            }
            tvscshow *pShow = show(sShow);
            pShow->addFile(file.fileName());

        }
    }


    foreach(tvscshow *ptr,_show)
    {
        qDebug() << ptr->name();
        qDebug() << ptr->files();
    }
}

tvscshow* tvscmodel::show(QString &str)
{
    return _show[str];
}
