//
// Created by rohith on 12/28/19.
//
#ifndef MONGOHTTPSERVER_MONGO_DAO_H
#define MONGOHTTPSERVER_MONGO_DAO_H

#include<string>

#include "dao.h"
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>


namespace rohithy {
    namespace server {
        namespace mongo {
            class MongoDao : public Dao {
            private:
                mongocxx::collection col;
            public:
                MongoDao(const std::string& db_name, const std::string& collection_name);

                bool insert(std::string doc) override;

                void get(std::string doc_id, std::string *doc) override;

                bool removeOne(std::string doc_id) override;
            };
        }
    }
}
#endif //MONGOHTTPSERVER_MONGO_DAO_H
