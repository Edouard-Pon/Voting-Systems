#include "bordaCountVoting.h"
#include "voterList.h"
#include "candidateList.h"


void BordaCountVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    const unsigned numberOfVotePerVoter = 4;
    const unsigned pointsIndex = 4;
    int points = 4;
    string voterName;
    string voterSurname;

    cout << "This is a Borda Count Voting!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << endl;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    cout << endl;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    while (voteCounter != numberOfVotePerVoter) {
        CandidateList::showList(candidateList, true);
        cout << "Rules: First vote +4 points for Candidate, Second +3, Third +2 and Fourth +1" << endl;
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        cout << endl;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        --points;
        ++voteCounter;
    }
}
