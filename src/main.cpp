#include <iostream>
#include "candidateList.h"
#include "voterList.h"
#include "pluralityVoting.h"
#include "secretBallot.h"
#include "bordaCountVoting.h"

using namespace std;


int main() {

    vector<vector<string>> candidateList;
    vector<vector<string>> voterList;

    CandidateList::createVoteList(candidateList);
    CandidateList::showList(candidateList, false);

    // Make Vote Test Multiple Users
    for (int i = 0; i < 4; ++i) {
//        SecretBallot::makeVote(candidateList);
//        PluralityVoting::makeVote(candidateList, voterList);
        BordaCountVoting::makeVote(candidateList, voterList);
        cout << endl;
    }

    // Sort Test
    CandidateList::sortByPointsVoteList(candidateList, 4);
    cout << endl;
    CandidateList::showList(candidateList, false);

    // Set Places Test
    CandidateList::setPlacesByOrder(candidateList);
    cout << endl;
    CandidateList::showList(candidateList, false);
    VoterList::showVoterList(voterList, false, 1);

    return 0;
}
