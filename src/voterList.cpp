#include "voterList.h"

void VoterList::addVoter(vector<vector<string>> &voterList, const string voterName, const string voterSurname, const unsigned id) {
    vector<string> voter;

    voter.push_back(to_string(id+1));
    voter.push_back(voterName);
    voter.push_back(voterSurname);

    voterList.push_back(voter);
}

void VoterList::addSelectedCandidate(vector<vector<string>> &voterList, const string candidateName, unsigned voterId) {
    for (int i = 0; i < size(voterList); ++i) {
        if (voterList[i][0] == to_string(voterId)) {
            voterList[i].push_back(candidateName);
        }
    }
}

void VoterList::addForAgainst(vector<vector<string>> &voterList, unsigned voterId, bool againstCandidate) {
    for (int i = 0; i < size(voterList); ++i) {
        if (voterList[i][0] == to_string(voterId)) {
            if (againstCandidate) voterList[i].push_back("Against");
            else voterList[i].push_back("For");
        }
    }
}

// voteSystemId: 2 = multiple choice, 3 = borda voting, 4 = negative voting
void VoterList::showVoterList(vector<vector<string>> voterList, bool hideVotes, unsigned voteSystemId) {
    const string sepLine = "====================";
    cout << sepLine << endl << "Voter List:" << endl;
    for (unsigned i = 0; i < size(voterList); ++i) {
        cout << "id: " << voterList[i][0] << " | "
             << "name: " << voterList[i][1] << " | "
             << "surname: " << voterList[i][2] << " | ";
        if (hideVotes) break;
        else if (voteSystemId == 2) {
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << "candidate: " << voterList[i][j] << " | ";
        } else if (voteSystemId == 3) {
            unsigned count = 5;
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << "+ " << --count << " to candidate: " << voterList[i][j] << " | ";
        } else if (voteSystemId == 4 && size(voterList[i]) > 3) {
            cout << "candidate: ";
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << voterList[i][j] << " | ";
        }
        cout << endl;
    }
    cout << sepLine << endl;
}
