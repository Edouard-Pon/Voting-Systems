#ifndef VOTING_SYSTEMS_VOTERLIST_H
#define VOTING_SYSTEMS_VOTERLIST_H

#include <iostream>
#include <vector>

using namespace std;


class VoterList {

public:
    static void addVoter(vector<vector<string>> &voterList, string voterName, string voterSurname, unsigned id);
    static void addSelectedCandidate(vector<vector<string>> &voterList, string candidateName, unsigned voterId);
    static void showVoterList(vector<vector<string>> voterList, bool hideVotes, unsigned voteSystemId);

};


#endif
