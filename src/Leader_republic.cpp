//
// Created by noam on 1/12/23.
//

#include "Leader_republic.h"
#include <iostream>
//constrictor of the that politician
Leader_republic::Leader_republic(string _name, string _last_name, int _id) : Republican_politician(_name, _last_name,
                                                                                                      _id) {
    name = _name;
    last_name = _last_name;
    id = _id;

}
// function prints info
void Leader_republic::print_my_info() const {
    cout << "Republican Person:" << name << " " << last_name << ", Id:" << id << ", Power:" << power << ", Type:L, Chairman: " << chairman;
}
// return primeries power.
int Leader_republic::get_primaries_power() const {
    return power;
}

// return election power.
int Leader_republic::get_election_power() const {
    return power;
}
