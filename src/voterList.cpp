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

// voteSystemId: 1 = plurality voting, 2 = bucklin voting
void VoterList::showVoterList(vector<vector<string>> voterList, bool hideVotes, unsigned voteSystemId) {
    const string sepLine = "====================";
    cout << sepLine << endl;
    for (unsigned i = 0; i < size(voterList); ++i) {
        cout << "id: " << voterList[i][0] << " | "
             << "name: " << voterList[i][1] << " | "
             << "surname: " << voterList[i][2] << " | ";
        if (hideVotes) break;
        else if (voteSystemId == 1) {
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << "candidate: " << voterList[i][j] << " | ";
            cout << endl;
        } else if (voteSystemId == 2) {
            unsigned count = 5;
            for (unsigned j = 3; j < size(voterList[i]); ++j) cout << "+ " << --count << " to candidate: " << voterList[i][j] << " | ";
            cout << endl;
        }
    }
    cout << sepLine << endl;
}
