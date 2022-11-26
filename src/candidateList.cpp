#include "candidateList.h"


void CandidateList::addToList(vector<vector<string>> &list, const string name, const unsigned id, const unsigned points, const unsigned place) {
    list[id].resize(7);
    list[id][0] = to_string(id+1);
    list[id][1] = name;
    list[id][2] = to_string(points); // sb points
    list[id][3] = to_string(points); // mc points
    list[id][4] = to_string(points); // bc points
    list[id][5] = to_string(points); // nv points
    list[id][6] = to_string(place);
}

// voteSystemId: 1 = secret ballot, 2 = multiple choice, 3 = borda voting, 4 = negative voting
void CandidateList::showList(const vector<vector<string>> list, const unsigned voteSystemId, const bool hidePointsPlace,
                             const unsigned numberOfCandidates) {
    const string sepLine = "====================";
    cout << sepLine << endl << "Candidate List: " << endl;
    for (int i = 0; i < numberOfCandidates; ++i) {
        cout << "id: " << list[i][0] << " | "
             << "name: " << list[i][1] << " | ";
        if (voteSystemId == 1 && !hidePointsPlace) cout << "sb points: " << list[i][2] << " | ";
        else if (voteSystemId == 2 && !hidePointsPlace) cout << "mc points: " << list[i][3] << " | ";
        else if (voteSystemId == 3 && !hidePointsPlace) cout << "bv points: " << list[i][4] << " | ";
        else if (voteSystemId == 4 && !hidePointsPlace) cout << "nv points: " << list[i][5] << " | ";
        if (!hidePointsPlace) cout << "place: " << list[i][6];
        cout << endl;
    }
    cout << sepLine << endl;
}

void CandidateList::createVoteList(vector<vector<string>> &list) {
    unsigned listSize;
    const unsigned points = 0;
    const unsigned place = 0;
    string candidateName;

    cout << "Enter number of candidates: ";
    cin >> listSize;
    cout << endl;
    list.resize(listSize);

    cin.ignore();
    for (unsigned id = 0; id < size(list); ++id) {
        cout << "Enter candidate name: ";
        getline(cin, candidateName);
        cout << endl;
        addToList(list, candidateName, id, points, place);
    }
}

// compIndex = 2 || 3 || 4 || 5
void CandidateList::sortByPointsVoteList(vector<vector<string>> &list, const unsigned compIndex, const bool ascending) {
    vector<string> tmp(size(list[0]));
    for (int i = 0; i < size(list)-1; ++i) {
        for (int j = 0; j < size(list)-1; ++j) {
            if (stoi(list[j][compIndex]) < stoi(list[j+1][compIndex]) && !ascending) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            } else if (stoi(list[j][compIndex]) > stoi(list[j+1][compIndex]) && ascending) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
}

void CandidateList::setPlacesByOrder(vector<vector<string>> &list) {
    for (int i = 0; i < size(list); ++i) {
        list[i][6] = to_string(i+1);
    }
}

void CandidateList::addPoints(vector<vector<string>> &list, const unsigned id, const int points, const unsigned pointsIndex) {
    for (int i = 0; i < size(list); ++i) {
        if (list[i][0] == to_string(id)) {
            list[i][pointsIndex] = to_string(stoi(list[i][pointsIndex]) + points);
        }
    }
}

void CandidateList::removePoints(vector<vector<string>> &list, const unsigned id, const int points, const unsigned pointsIndex) {
    for (int i = 0; i < size(list); ++i) {
        if (list[i][0] == to_string(id)) {
            list[i][pointsIndex] = to_string(stoi(list[i][pointsIndex]) - points);
        }
    }
}

string CandidateList::getCandidateNameById(vector<vector<string>> candidateList, unsigned candidateId) {
    for (int i = 0; i < size(candidateList); ++i) {
        if (candidateList[i][0] == to_string(candidateId)) {
            return candidateList[i][1];
        }
    }
    return "Not Found";
}

unsigned CandidateList::getCandidateWithSamePoints(vector<vector<string>> candidateList, const unsigned pointsIndex) {
    unsigned candidatesCount = 1;
    for (unsigned i = 1; i < size(candidateList); ++i) {
        if (candidateList[0][pointsIndex] == candidateList[i][pointsIndex]) ++candidatesCount;
    }
    return candidatesCount;
}

void CandidateList::resetCandidatesPoints(vector<vector<string>> &candidateList, const unsigned pointsIndex) {
    for (unsigned i = 0; i < size(candidateList); ++i) {
        candidateList[i][pointsIndex] = to_string(0);
    }
}
