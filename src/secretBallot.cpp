#include "secretBallot.h"
#include "candidateList.h"


void SecretBallot::makeVote(vector<vector<string>> &candidateList) {
    unsigned candidateId;
    const unsigned pointsIndex = 2;
    const int points = 1;

    cout << endl << "This is a Secret Ballot Voting!" << endl;
    CandidateList::showList(candidateList, 1, true, size(candidateList));
    cout << "Rules: Choose 1 candidate to vote!" << endl;
    cout << "Make your vote by choosing id: ";
    cin >> candidateId;
    cout << endl;

    CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);

    cout << "You voted for id: " << candidateId << " | candidate: " << CandidateList::getCandidateNameById(candidateList, candidateId);
    cout << endl;
}
