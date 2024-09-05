//
// Created by noam on 1/11/23.
//

#ifndef CPP_WORK2_LEADER_DEMOCRETIC_H
#define CPP_WORK2_LEADER_DEMOCRETIC_H
#include "Democratic_Politician.h"


class Leader_Democretic : public Democratic_Politician{
public:
    Leader_Democretic(string _name, string _last_name, int _id);
    virtual ~Leader_Democretic() {};
    virtual void print_my_info()const; // virtual function
    virtual int get_primaries_power()const;  // function return prameries power
    virtual int get_election_power()const; // return election power of the party.

};


#endif //CPP_WORK2_LEADER_DEMOCRETIC_H
