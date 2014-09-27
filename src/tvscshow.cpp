#include "tvscshow.h"

tvscshow::tvscshow(QObject *parent)
    :QObject(parent),_name()
{
}


tvscshow::tvscshow(QString &name, QObject *parent)
    :QObject(parent),_name(name)
{

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

const QList<QString> tvscshow::files() const
{
    return _fileNames;
}

void tvscshow::addFile(QString str)
{
    _fileNames << str;
}
