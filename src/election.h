#ifndef VOTING_SYSTEMS_ELECTION_H
#define VOTING_SYSTEMS_ELECTION_H

#include <iostream>
#include <vector>

using namespace std;


class Election {

public:
    static void startVoting(vector<vector<string>> &candidateList, vector<vector<string>> &voterList,
                                     unsigned numberOfVoters, unsigned votingSystem);
    static void electionCalculation(vector<vector<string>> &candidateList, vector<vector<string>> &voterList,
                                    unsigned compIndex);
    static void clearVoterCandidateList(vector<vector<string>> &candidateList, vector<vector<string>> &voterList);
    static void startElection(vector<vector<string>> &candidateList, vector<vector<string>> &voterList,
                              unsigned numberOfVoters, unsigned votingSystemId, unsigned pointsIndex);

};


#endif
