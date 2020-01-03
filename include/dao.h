//
// Created by rohith on 12/31/19.
//

#ifndef MONGOHTTPSERVER_DAO_H
#define MONGOHTTPSERVER_DAO_H

class Dao {
public:
    virtual bool insert(std::string doc)=0;

    virtual void get(std::string doc_id, std::string *doc)=0;

    virtual bool removeOne(std::string doc_id)=0;

};

#endif //MONGOHTTPSERVER_DAO_H
