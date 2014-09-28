#include "tvscepisode.h"
#include <QDebug>

tvscepisode::tvscepisode()
{

}

tvscepisode::tvscepisode(tvscepisodeinfo &info)
    :_info(info)
{
}


QDebug operator<< (QDebug d, const tvscepisode &model) {
    d << "S" << model.season() << "E" << model.episode();
    return d;
}
