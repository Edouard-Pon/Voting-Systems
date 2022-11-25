#include <iostream>
#include "candidateList.h"
#include "voterList.h"
#include "pluralityVoting.h"
#include "secretBallot.h"
#include "bordaCountVoting.h"
#include "negativeVoting.h"

using namespace std;


int main() {

    vector<vector<string>> candidateList;
    vector<vector<string>> voterList;

    unsigned numberOfVoters;

    cout << "Enter number of voters: ";
    cin >> numberOfVoters;
    cout << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    CandidateList::createVoteList(candidateList);
    CandidateList::showList(candidateList, 0, true);

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < numberOfVoters; ++i) {
        SecretBallot::makeVote(candidateList);
    }
    CandidateList::sortByPointsVoteList(candidateList, 2);
    CandidateList::setPlacesByOrder(candidateList);
    CandidateList::showList(candidateList, 1, false);
    voterList.clear();
    CandidateList::sortByPointsVoteList(candidateList, 0);

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < numberOfVoters; ++i) {
        PluralityVoting::makeVote(candidateList, voterList);
    }
    CandidateList::sortByPointsVoteList(candidateList, 3);
    CandidateList::setPlacesByOrder(candidateList);
    CandidateList::showList(candidateList, 2, false);
    VoterList::showVoterList(voterList, false, 1);
    voterList.clear();
    CandidateList::sortByPointsVoteList(candidateList, 0);

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < numberOfVoters; ++i) {
        BordaCountVoting::makeVote(candidateList, voterList);
    }
    CandidateList::sortByPointsVoteList(candidateList, 4);
    CandidateList::setPlacesByOrder(candidateList);
    CandidateList::showList(candidateList, 3, false);
    VoterList::showVoterList(voterList, false, 2);
    voterList.clear();
    CandidateList::sortByPointsVoteList(candidateList, 0);

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    for (int i = 0; i < numberOfVoters; ++i) {
        NegativeVoting::makeVote(candidateList, voterList);
    }
    CandidateList::sortByPointsVoteList(candidateList, 5);
    CandidateList::setPlacesByOrder(candidateList);
    CandidateList::showList(candidateList, 4, false);
    VoterList::showVoterList(voterList, false, 3);
    voterList.clear();
    candidateList.clear();

    cout << "~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
