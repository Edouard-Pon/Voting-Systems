#ifndef VOTING_SYSTEMS_PLURALITYVOTING_H
#define VOTING_SYSTEMS_PLURALITYVOTING_H

#include <iostream>
#include <vector>

using namespace std;


class PluralityVoting {

public:
    static void makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);

};

#endif
