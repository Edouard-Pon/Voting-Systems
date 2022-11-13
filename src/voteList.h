#ifndef VOTING_SYSTEMS_VOTELIST_H
#define VOTING_SYSTEMS_VOTELIST_H

#include <iostream>
#include "vector"

using namespace std;


class VoteList {

public:
    static void addToList(vector<vector<string>> &list, string name, unsigned id, unsigned points, unsigned place);
    static void showList(vector<vector<string>> list);
    static void createVoteList(vector<vector<string>> &list);
    static void sortByPointsVoteList(vector<vector<string>> &list);
    static void setPlacesByOrder(vector<vector<string>> &list);

};

#endif
