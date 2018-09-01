#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "databasemanager.h"
#include "album.h"

AlbumDao::AlbumDao(QSqlDatabase &database) :
    database_(database)
{

}

void AlbumDao::init() const
{
    if(!database_.tables().contains("albums")){
        QSqlQuery query(database_);
        query.exec("CREATE TABLE albumbs (id INTEGER PRIMARY KEY AUTOINCREAMENT, name TEXT");
    }

}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(database_);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());

}

void AlbumDao::updateAlbum(const Album &album) const
{
    QSqlQuery query(database_);
    query.prepare("UPDATE albums SET id=:id, name=:name");  //upadate id and name using UPDATE SET
    query.bindValue(":id",album.id());
    query.bindValue(":name", album.name());
    query.exec();
    //album.setId(query.lastInsertId().toInt());
}

void AlbumDao::removeAlbum(int id) const
{
    QSqlQuery query(database_);
    query.prepare("DELETE FROM albums WHERE id=:id"); // remvove album using DELETE WHERE
    query.bindValue(":id",id);
    query.exec();
}

QVector<Album *> AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", database_);
    query.exec();
    QVector<Album*> list;
    while(query.next()){
        Album* album = new Album();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list.append(album);
    }
    return list;
}
