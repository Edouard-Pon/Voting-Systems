#include "multipleChoiceVoting.h"
#include "candidateList.h"
#include "voterList.h"


void MultipleChoiceVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    const unsigned numberOfVotePerVoter = (size(candidateList) < 10) ? size(candidateList) / 2 : 5;
    const unsigned pointsIndex = 3;
    const int points = 1;
    string voterName;
    string voterSurname;

    cout << endl << "This is a Multiple Choice Voting!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << endl;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    cout << endl;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    CandidateList::showList(candidateList, 2, true, size(candidateList));
    cout << "Rules: You can vote for " << numberOfVotePerVoter << " candidates!" << endl;
    while (voteCounter != numberOfVotePerVoter) {
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        cout << endl;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        ++voteCounter;
    }
}
