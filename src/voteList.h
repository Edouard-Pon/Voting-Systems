#ifndef VOTING_SYSTEMS_VOTELIST_H
#define VOTING_SYSTEMS_VOTELIST_H

#include <iostream>
#include <vector>

using namespace std;


class VoteList {

public:
    static void addToList(vector<vector<string>> &list, string name, unsigned id, unsigned points, unsigned place);
    static void showList(vector<vector<string>> list, bool hidePointsPlace);
    static void createVoteList(vector<vector<string>> &list);
    static void sortByPointsVoteList(vector<vector<string>> &list, unsigned compIndex);
    static void setPlacesByOrder(vector<vector<string>> &list);
    static void addPoints(vector<vector<string>> &list, unsigned id, unsigned points, unsigned pointsIndex);

};

#endif
