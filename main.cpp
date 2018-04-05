#include <iostream>
#include "UserRepository.h"

int main()
{
    cppReview::UserRepository userRepository;
    cppReview::User user = userRepository.Get(42);
    std::cout << "Hello World!" << std::endl;
    return 0;
}