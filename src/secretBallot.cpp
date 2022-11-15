#include "secretBallot.h"
#include "voteList.h"


void SecretBallot::makeVote(vector<vector<string>> &list) {
    unsigned candidateId;
    unsigned pointsIndex = 2;
    unsigned points = 1;

    VoteList::showList(list, true);
    cout << "This is a secret vote!" << endl;
    cout << "Make your vote by choosing id: ";
    cin >> candidateId;

    VoteList::addPoints(list, candidateId, points, pointsIndex);
}
