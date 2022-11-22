#ifndef VOTING_SYSTEMS_PLURALITYVOTING_H
#define VOTING_SYSTEMS_PLURALITYVOTING_H

#include <iostream>
#include <vector>

using namespace std;


class PluralityVoting {

public:
    static void makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);
    static void addSelectedCandidate(vector<vector<string>> &voterList, string candidateName, unsigned voterId);
    static void showVoterList(vector<vector<string>> voterList, bool hideVotes);

};

#endif
