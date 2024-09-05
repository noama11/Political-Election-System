//
// Created by noam on 1/11/23.
//

#ifndef CPP_WORK2_SOCIAL_DENOCRAT_H
#define CPP_WORK2_SOCIAL_DENOCRAT_H
#include "Democratic_Politician.h"

class social_democrat: public Democratic_Politician{
public:
    social_democrat(string _name, string _last_name, int _id); // construntor
    ~social_democrat() {}; // destructor
    virtual int get_primaries_power() const; // return this primaries power..
    virtual int get_election_power()const;  // return this election power
    virtual void print_my_info()const; // virtual function
};


#endif //CPP_WORK2_SOCIAL_DENOCRAT_H
