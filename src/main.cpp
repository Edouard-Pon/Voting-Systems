#include <iostream>
#include "candidateList.h"
#include "election.h"

using namespace std;


int main() {

    vector<vector<string>> candidateList;
    vector<vector<string>> voterList;
    vector<vector<string>> candidateListBackup;

    unsigned numberOfVoters;

    cout << "Enter number of voters: ";
    cin >> numberOfVoters;
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    CandidateList::createVoteList(candidateList);
    candidateListBackup = candidateList;
    CandidateList::showList(candidateList, 0, true, size(candidateList));
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    // Secret Ballot
    Election::startElection(candidateList, voterList, numberOfVoters, 1, 2);
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    // Multiple Choice Voting
    candidateList = candidateListBackup;
    Election::startElection(candidateList, voterList, numberOfVoters, 2, 3);
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    // Borda Count Voting
    candidateList = candidateListBackup;
    Election::startElection(candidateList, voterList, numberOfVoters, 3, 4);
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    // Negative Voting
    candidateList = candidateListBackup;
    Election::startElection(candidateList, voterList, numberOfVoters, 4, 5);
    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
