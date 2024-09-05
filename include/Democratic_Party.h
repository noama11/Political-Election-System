//
// Created by noam on 1/10/23.
//

#ifndef CPP_WORK2_DEMOCRATIC_PARTY_H
#define CPP_WORK2_DEMOCRATIC_PARTY_H
#include "Party.h"

// Class that inheriting from "party" class and inheriting all fields and functions from the "father" class.
class Democratic_Party :
        public Party{
public:
    virtual bool is_fit( Politician* pol)const{return pol->is_democrat();}
    Democratic_Party(string name1); // constructor
    Democratic_Party(const Democratic_Party& p); // copy constructor
    virtual void print_my_info() const; // pure virtual func of the "father" class that this party need to implement it.
    virtual ~Democratic_Party() {}; // virtual destructor.

};



#endif //CPP_WORK2_DEMOCRATIC_PARTY_H
