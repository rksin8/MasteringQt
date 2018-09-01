#include "databasemanager.h"

#include <QSqlDatabase>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager signleton;
    return signleton;

    /*
    if(database_ != nullptr){
        database_ = new DatabaseManager();
        return database_;
    }

    return database_;
    */

}

DatabaseManager::~DatabaseManager()
{
    database_->close();
    delete database_;

}

DatabaseManager::DatabaseManager(const QString &path) :
    database_(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao_(*database_)

{
    database_->setDatabaseName(path);
    database_->open();

    albumDao_.init();
}

DatabaseManager &DatabaseManager::operator=(const DatabaseManager &rhs)
{
        //this =rhs;
        return *this;
}
