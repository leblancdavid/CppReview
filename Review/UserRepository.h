#include "Repository.h"
#include "User.h"

namespace cppReview
{
    class UserRepository : public Repository<User>
    {
        public:
            UserRepository();
            UserRepository(const UserRepository &cpy);
            ~UserRepository();

            User Get(int id);
            void Delete(int id);
            void Create(User obj);
            void Update(User obj);
    };
}

