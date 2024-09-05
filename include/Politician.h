//
// Created by noam on 1/9/23.
//

#ifndef CPP_WORK2_POLITICIAN_H
#define CPP_WORK2_POLITICIAN_H
#include "string"
#include "string"
#include <vector>
//#include "Party.h"
using namespace std;

// Abstract class of politician with fields: name, id, party name, chairman name, his power, and his serial number the decided by the entry order.
// the politican are the observers of the parties and get from the update about new chairman.
class Politician {
protected:
    string name;
    string last_name;
    int id;
    string party;
    string chairman;
    int power;
    Politician(const Politician& p);
    int age_num; // represents the seniority of the politician.
    static int age; // for counting it

public:
    virtual bool is_democrat()const=0;
    virtual bool is_republic()const=0;
    Politician(string _name, string _last_name, int _id); // must recived the id, name and the last name.
    virtual ~Politician() {};  // virtual distructor for his succsesors
    virtual void print_my_info()const = 0; // virtual function
    int get_power()const; // return his power
    virtual int get_primaries_power()const = 0; // pure virtual that the succesor needs to implement, return the power on primaries time.
    virtual int get_election_power()const = 0; // pure virtual that the succesor needs to implement return the power on election time.
    void update_chairman(string chairman);  // the politicain are the observers of the parties and will get update of the new chairman using the func.
    string get_name()const; // func the return the name of this politician.
    string get_party()const;  // func that return the party name
    void set_party(string party_name); // func that set new party name.
    void set_power(int power);  // func that set power for the politician
    int get_id()const; // return the politician id.
    int get_age()const; // return the politician entry location.
};


#endif //CPP_WORK2_POLITICIAN_H
