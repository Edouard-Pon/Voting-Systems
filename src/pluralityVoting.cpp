#include "pluralityVoting.h"
#include "candidateList.h"
#include "voterList.h"


void PluralityVoting::makeVote(vector<vector<string>> &candidateList, vector<vector<string>> &voterList) {
    unsigned candidateId;
    unsigned voteCounter = 0;
    const unsigned numberOfVotePerVoter = (size(candidateList) < 10) ? size(candidateList) / 2 : 5;
    const unsigned pointsIndex = 3;
    const unsigned points = 1;
    string voterName;
    string voterSurname;

    cout << "This is a Plurality Vote!" << endl;
    cout << "Enter your Name: ";
    cin >> voterName;
    cout << "Enter your Surname: ";
    cin >> voterSurname;
    VoterList::addVoter(voterList, voterName, voterSurname, size(voterList));
    while (voteCounter != numberOfVotePerVoter) {
        CandidateList::showList(candidateList, true);
        cout << "Make your vote by choosing id: ";
        cin >> candidateId;
        if (candidateId == 0) break;
        addSelectedCandidate(voterList, CandidateList::getCandidateNameById(candidateList, candidateId), size(voterList));
        CandidateList::addPoints(candidateList, candidateId, points, pointsIndex);
        ++voteCounter;
    }
}

void PluralityVoting::addSelectedCandidate(vector<vector<string>> &voterList, const string candidateName, const unsigned voterId) {
    for (int i = 0; i < size(voterList); ++i) {
        if (voterList[i][0] == to_string(voterId)) {
            voterList[i].push_back(candidateName);
        }
    }
}

void PluralityVoting::showVoterList(const vector<vector<string>> voterList, const bool hideVotes) {
    const string sepLine = "====================";
    cout << sepLine << endl;
    for (unsigned i = 0; i < size(voterList); ++i) {
        if (hideVotes) cout << "id: " << voterList[i][0] << " | "
                            << "name: " << voterList[i][1] << " | "
                            << "surname: " << voterList[i][2] << endl;
        else {
            cout << "id: " << voterList[i][0] << " | "
                 << "name: " << voterList[i][1] << " | "
                 << "surname: " << voterList[i][2] << " | ";
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << "candidate: " << voterList[i][j] << " | ";
            cout << endl;
        }
    }
    cout << sepLine << endl;
}
