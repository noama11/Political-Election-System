//
// Created by noam on 1/12/23.
//

#include "social_republic.h"
#include <iostream>

// constructor
social_republic::social_republic(string _name, string _last_name, int _id) : Republican_politician(_name, _last_name,
                                                                                                      _id) {
    this->name = _name;
    this->last_name = _last_name;
    this->id = _id;

}

// return primeries power.
int social_republic::get_primaries_power() const {
    return 0;
}

// return the election
int social_republic::get_election_power() const {
    int elect_power = power * 2;
    return elect_power;
}

// return this class info.
void social_republic::print_my_info() const {
    cout << "Republican Person:" << name << " " << last_name << ", Id:" << id << ", Power:" << power << ", Type:S, Chairman: " << chairman;

}
