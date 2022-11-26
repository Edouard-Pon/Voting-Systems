#ifndef VOTING_SYSTEMS_MULTIPLECHOICEVOTING_H
#define VOTING_SYSTEMS_MULTIPLECHOICEVOTING_H

#include <iostream>
#include <vector>

using namespace std;


class MultipleChoiceVoting {

public:
    static void makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);

};

#endif
