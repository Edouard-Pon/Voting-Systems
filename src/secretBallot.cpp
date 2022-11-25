#include "secretBallot.h"
#include "candidateList.h"


void SecretBallot::makeVote(vector<vector<string>> &list) {
    unsigned candidateId;
    const unsigned pointsIndex = 2;
    const int points = 1;

    CandidateList::showList(list, 1, true);
    cout << "This is a secret vote!" << endl;
    cout << "Make your vote by choosing id: ";
    cin >> candidateId;
    cout << endl;

    CandidateList::addPoints(list, candidateId, points, pointsIndex);
}
