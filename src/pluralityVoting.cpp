#include "pluralityVoting.h"
#include "candidateList.h"
#include "voterList.h"


void PluralityVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    const unsigned numberOfVotePerVoter = (size(candidateList) < 10) ? size(candidateList) / 2 : 5;
    const unsigned pointsIndex = 3;
    const int points = 1;
    string voterName;
    string voterSurname;

    cout << "This is a Plurality Vote!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << endl;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    cout << endl;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    while (voteCounter != numberOfVotePerVoter) {
        CandidateList::showList(candidateList, 2, true);
        cout << "Make your vote by choosing id: ";
        cin >> candidateId;
        cout << endl;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        ++voteCounter;
    }
}
