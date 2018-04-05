#include "User.h"

namespace cppReview
{
    User::User()
    {
        _username = "";
        _password = "";
    }

    User::User(const User &user)
    {
        _username = user._username;
        _password = user._password;
    }

    User::~User()
    {

    }

    User::User(const std::string &username, const std::string &password)
    {
        _username = username;
        _password = password;
    }
}
