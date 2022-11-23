#ifndef VOTING_SYSTEMS_BUCKLINVOTING_H
#define VOTING_SYSTEMS_BUCKLINVOTING_H

#include <iostream>
#include <vector>

using namespace std;


class BucklinVoting {

public:
    static void makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);

};


#endif
