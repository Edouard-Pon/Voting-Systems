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

    cout << endl << "This is a Borda Count Voting!" << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, voterName);
    cout << endl;
    cout << "Enter your Surname: ";
    getline(cin, voterSurname);
    cout << endl;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    CandidateList::showList(candidateList, 3, true, size(candidateList));
    cout << "Rules: First vote +4 points for Candidate, Second +3, Third +2 and Fourth +1" << endl;
    while (voteCounter != numberOfVotePerVoter) {
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        cout << endl;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        cout << "You voted for id: " << candidateId << " | candidate: " << CandidateList::getCandidateNameById(candidateList, candidateId);
        cout << endl;
        --points;
        ++voteCounter;
    }
}
