//
// Created by noam on 1/12/23.
//

#ifndef CPP_WORK2_SOCIAL_REPUBLIC_H
#define CPP_WORK2_SOCIAL_REPUBLIC_H
#include "Republican_politician.h"

class social_republic : public Republican_politician{
public:
    social_republic(string _name, string _last_name, int _id); // constructor.
    ~social_republic() {}; // destructor.
    virtual int get_primaries_power() const; // return promeries power
    virtual int get_election_power()const; // return election power
    virtual void print_my_info() const; // return this class info.
};


#endif //CPP_WORK2_SOCIAL_REPUBLIC_H
