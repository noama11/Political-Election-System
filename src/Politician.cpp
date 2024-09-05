//
// Created by noam on 1/9/23.
//

#include "Politician.h"

int Politician::age = 0;

// constructor for create new politician.
Politician::Politician(string _name, string _last_name, int _id) {
    name = _name;
    last_name = _last_name;
    id = _id;
    party = "None";
    power = 0;
    chairman = "None";
    age_num = ++age;
}

// copy constructor.
Politician::Politician(const Politician &p) {
    name = p.name;
    last_name = p.last_name;
    id = p.id;
    party = p.party;
    chairman = p.chairman;
    power = p.power;
}

// return power
int Politician::get_power() const {
    return power;
}

// set new chairman
void Politician::update_chairman(string chairman) {
    this->chairman = chairman;

}
// return the name of the politician.
string Politician::get_name() const {
    return name;
}
// return the party name.
string Politician::get_party() const {
    return party;
}
// set the party name.
void Politician::set_party(string party_name) {
    party = party_name;
}
// set the power
void Politician::set_power(int power_) {

    power = power_;
}
// return the id num
int Politician::get_id() const {
    return id;
}
// return the entry location.
int Politician::get_age() const {
    return age_num;
}



