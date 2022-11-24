#include "negativeVoting.h"
#include "candidateList.h"
#include "voterList.h"

void NegativeVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    unsigned forAgainst = 0;
    const unsigned numberOfVotePerVoter = 1;
    const unsigned pointsIndex = 5;
    const int points = 1;
    string voterName;
    string voterSurname;

    cout << "This is a Negative Voting!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    while (voteCounter != numberOfVotePerVoter) {
        CandidateList::showList(candidateList, false);
        cout << "Rules: Choose For or Against then vote for 1 candidate" << endl;
        cout << "For = 1 | Against = 2: ";
        cin >> forAgainst;
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        if (forAgainst == 1) {
            CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
            VoterList::addForAgainst(voterList, size(voterList), false);
        }
        else if (forAgainst == 2) {
            CandidateList::removePoints(candidateList, candidateId, points, pointsIndex);
            VoterList::addForAgainst(voterList, size(voterList), true);
        }
        ++voteCounter;
    }
}
