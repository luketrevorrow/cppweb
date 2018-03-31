#ifndef IM_MODELS_ARTICLE
#define IM_MODELS_ARTICLE

#include <string>
#include <cstdint>
#include <vector>

namespace im
{
    namespace models
    {
        class Article
        {
        public:
            Article(const uint32_t& id, const std::string& title, const std::string& body, const std::vector<std::string>& tags, const std::string& created, const std::string& edited);
            std::string getTitle();
            std::string getBody();
            std::vector<std::string> getTags();
            std::string getCreated();
            std::string getEdited();

        private:
            uint32_t id;
            std::string title;
            //Author author; reference to author
            std::string body;
            std::vector<std::string> tags;
            std::string created;
            std::string edited;
        };
    }
}

#endif