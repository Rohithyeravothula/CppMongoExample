//
// Created by rohith on 12/28/19.
//

#include "../include/mongo_dao.h"
#include<iostream>
#include<string>



namespace rohithy {
    namespace server {
        namespace mongo {

            MongoDao::MongoDao(const std::string &db_name, const std::string &collection_name) {
                mongocxx::instance inst{};
                mongocxx::client conn{mongocxx::uri{}};
                col = conn[db_name][collection_name];
            }

            bool MongoDao::insert(std::string doc) {
                bsoncxx::builder::stream::document document{};
                document << doc;
                core::optional<mongocxx::result::insert_one> result =  col.insert_one(document.view());
                return true;
            }

            void MongoDao::get(std::string doc_id, std::string *doc) {
                bsoncxx::builder::stream::document document{};
                document << "_id" << doc_id;
                auto cursor = col.find_one(document.view());
                *doc = "name: " + cursor.value()["name"].get_utf8().value.to_string();
            }

            bool MongoDao::removeOne(std::string doc_id) {
                bsoncxx::builder::stream::document document{};
                document << "_id" << doc_id;
                auto result = col.delete_one(document.view());
                return result.value().deleted_count() == 1;
            }
        }
    }
}