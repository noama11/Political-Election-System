//
// Created by noam on 1/12/23.
//

#ifndef CPP_WORK2_REPUBLICAN_PARTY_H
#define CPP_WORK2_REPUBLICAN_PARTY_H
#include "Party.h"
// Class that inheriting from "party" class and inheriting all fields and functions from the "father" class.
class Republican_Party : public Party {
public:
    virtual bool is_fit(Politician* pol)const{return pol->is_republic();} // using polymorfizem to check it.
    Republican_Party(string name); // constructor
    virtual void print_my_info() const; // copy constructor
    ~Republican_Party() {}; // virtual destructor.

};

#endif //CPP_WORK2_REPUBLICAN_PARTY_H
