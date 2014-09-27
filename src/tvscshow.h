#ifndef TVSCSHOW_H
#define TVSCSHOW_H

#include <QObject>
#include <QDir>

class tvscshow : public QObject
{
    Q_OBJECT
public:
    explicit tvscshow(QObject *parent = 0);
    tvscshow(QString &name,QObject *parent = 0);

    const bool isValid() const;

    const QString& name() const;

    bool operator==(const tvscshow &one);

    const QList<QString> files() const;

    void addFile(QString str);
signals:

public slots:

private:
    QString _name;

    QList<QString> _fileNames;
};

#endif // TVSCSHOW_H
