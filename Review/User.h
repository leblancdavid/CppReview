#include <string>

namespace cppReview
{
    class User 
    {
        public:
            User();
            User(const User &user);
            ~User();
            User(const std::string &username, const std::string &password);
        

        private:
            std::string _username;
            std::string _password;
    };
}
