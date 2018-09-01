#include "picturedao.h"
#include <QSqlQuery>
#include "picture.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>


PictureDao::PictureDao(QSqlDatabase &database):
    database_(database)
{

}

void PictureDao::init() const
{
    if(!database_.tables().contains("pictures")){
        QSqlQuery query(database_);
        query.exec(QString("CREATE TABLE pictures")
                   + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   + "album_id INTEGER, "
                   + "url TEXT)");
    }

}

void PictureDao::addPictureInAlbum(int albumId, Picture &picture) const
{
    QSqlQuery query(database_);
    query.prepare("INSERT INTO pictures (album_id, url)"
                  "VALUES (:album_id, :url)" );
    query.bindValue(":album_id", albumId);
    query.bindValue(":url", picture.fileUrl().toString());
    query.exec();
    //pictures.setId(query.lastInsertId().toInt());

}

void PictureDao::removePicture(int id) const
{
    QSqlQuery query(database_);
    query.prepare("DELETE FROM pictures WHERE id=:id"); // remvove album using DELETE WHERE
    query.bindValue(":id",id);
    query.exec();
}

void PictureDao::removePicturesFromAlbum(int albumId) const
{
    QSqlQuery query(database_);
    query.prepare("DELETE FROM pictures WHERE album_id=:albumId"); // remvove album using DELETE WHERE
    query.bindValue(":albumId",albumId);
    query.exec();
}

QVector<Picture *> PictureDao::picturesForAlbum(int albumId) const
{
    QSqlQuery query(database_);
    query.prepare("SELECT * FROM pictures WHERE album_id=:albumId ");
    query.bindValue(":albumId",albumId);
    query.exec();
    QVector<Picture*> list;

    while(query.next()){
        Picture* picture = new Picture();
        picture->setId(query.value("id").toInt()); //auto increment
        picture->setAlbumId(query.value("album_id").toInt());
        picture->setFileUrl(query.value("url").toString());
        list.append(picture);
    }

    return list;
}
