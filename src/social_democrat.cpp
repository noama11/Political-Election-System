//
// Created by noam on 1/11/23.
//

#include "social_denocrat.h"
#include <iostream>

//constrictor
social_democrat::social_democrat(string _name, string _last_name, int _id) : Democratic_Politician(_name, _last_name, _id){
    this->name = _name;
    this->last_name = _last_name;
    this->id = _id;
}
// retirn the primeries power.
int social_democrat::get_primaries_power() const {
    return 0;
}

// return election power.
int social_democrat::get_election_power() const {
    return power * 2;
}

// function prints this class info.
void social_democrat::print_my_info() const {
    cout << "Democratic Person:" << name << " " << last_name << ", Id:" << id << ", Power:" << power << ", Type:S, Chairman: " << chairman;

}
