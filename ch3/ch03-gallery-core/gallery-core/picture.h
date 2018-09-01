#ifndef PICTURE_H
#define PICTURE_H

#include <QUrl>
#include <QString>
#include "gallery-core_global.h"

class GALLERYCORESHARED_EXPORT Picture
{
public:
    Picture(const QString& filePath="");
    Picture(const QUrl& fileUrl);

    int id() const;
    void setId(int id);

    int albumId() const;
    void setAlbumId(int albumId);

    QUrl fileUrl() const;
    void setFileUrl(const QUrl& fileUrl);

private:
    int id_;
    int albumId_;
    QUrl fileUrl_;
};

#endif // PICTURE_H
