#include "voterList.h"

void VoterList::addVoter(vector<vector<string>> &voterList, string voterName, string voterSurname, unsigned int id) {
    vector<string> voter;

    voter.push_back(to_string(id+1));
    voter.push_back(voterName);
    voter.push_back(voterSurname);

    voterList.push_back(voter);
}
