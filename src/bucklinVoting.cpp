#include "bucklinVoting.h"
#include "voterList.h"
#include "candidateList.h"


void BucklinVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    const unsigned numberOfVotePerVoter = 4;
    const unsigned pointsIndex = 4;
    unsigned points = 4;
    string voterName;
    string voterSurname;

    cout << "This is a Bucklin Vote!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    while (voteCounter != numberOfVotePerVoter) {
        CandidateList::showList(candidateList, true);
        cout << "Rules: First vote +4 points for Candidate, Second +3, Third +2 and Fourth +1" << endl;
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        --points;
        ++voteCounter;
    }
}
