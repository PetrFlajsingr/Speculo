#include <exception>

namespace boost
{
    void throw_exception( std::exception const & e ){
        throw 11; // or whatever
    }
}// namespace boost