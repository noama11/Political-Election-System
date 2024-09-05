//
// Created by noam on 1/11/23.
//

#include "Leader_Democretic.h"
#include <iostream>
// comstrictor of this class
Leader_Democretic::Leader_Democretic(string _name, string _last_name, int _id) : Democratic_Politician(_name, _last_name, _id) {

    name = _name;
    last_name = _last_name;
    id = _id;
}
// functon prints this class info
void Leader_Democretic::print_my_info() const {
    cout << "Democratic Person:" << name << " " << last_name << ", Id:" << id << ", Power:" << power << ", Type:L, Chairman: " << chairman;

}
// function retuern this class election power.
int Leader_Democretic::get_election_power() const {
    return power;
}
// return this primeries power.
int Leader_Democretic::get_primaries_power() const {
    return power;
}
