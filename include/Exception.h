//
// Created by noam on 1/14/23.
//

#ifndef CPP_WORK2_EXCEPTION_H
#define CPP_WORK2_EXCEPTION_H
#include <exception>

using namespace std;
// an exception that points that the id isnt valid.
class ID_NOT_VALID: public exception{
public:
    virtual const char * what() const throw() {
        return "Please enter valid id";
    }
};

// an exception that points that the name isnt valid.
class name_not_valid: public exception{
public:
    virtual const char* what() const throw(){
        return "Please enter valid name";
    }
};
// an exception that points that the details isnt valid.
class invalid_details: public exception{
public:
    virtual const char* what() const throw(){
        return "Please enter valid details";
    }
};

class memory_problem: public exception{
    virtual const char* what() const throw(){
        return "memory problem";
    }
};


#endif //CPP_WORK2_EXCEPTION_H
