#ifndef VOTING_SYSTEMS_BORDACOUNTVOTING_H
#define VOTING_SYSTEMS_BORDACOUNTVOTING_H

#include <iostream>
#include <vector>

using namespace std;


class BordaCountVoting {

public:
    static void makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);

};


#endif
