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

    cout << endl << "This is a Negative Voting!" << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, voterName);
    cout << endl;
    cout << "Enter your Surname: ";
    getline(cin, voterSurname);
    cout << endl;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    CandidateList::showList(candidateList, 4, true, size(candidateList));
    cout << "Rules: Choose For or Against then vote for 1 candidate" << endl;
    while (voteCounter != numberOfVotePerVoter) {
        cout << "For = 1 | Against = 2: ";
        cin >> forAgainst;
        cout << endl;
        cout << "Type 0 to stop voting | Make your vote by choosing id: ";
        cin >> candidateId;
        cout << endl;
        if (candidateId == 0) break;
        VoterList::addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        if (forAgainst == 1) {
            CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
            cout << "You voted for id: " << candidateId << " | candidate: " << CandidateList::getCandidateNameById(candidateList, candidateId);
            cout << endl;
            VoterList::addForAgainst(voterList, size(voterList), false);
        }
        else if (forAgainst == 2) {
            CandidateList::removePoints(candidateList, candidateId, points, pointsIndex);
            cout << "You voted against id: " << candidateId << " | candidate: " << CandidateList::getCandidateNameById(candidateList, candidateId);
            cout << endl;
            VoterList::addForAgainst(voterList, size(voterList), true);
        }
        ++voteCounter;
    }
}
