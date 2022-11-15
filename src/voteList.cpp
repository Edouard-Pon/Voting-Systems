#include "voteList.h"


void VoteList::addToList(vector<vector<string>> &list, const string name, const unsigned id, const unsigned points, const unsigned place) {
    list[id].resize(7);
    list[id][0] = to_string(id);
    list[id][1] = name;
    list[id][2] = to_string(points); // sb points
    list[id][3] = to_string(points); // pv points
    list[id][4] = to_string(points); // bc points
    list[id][5] = to_string(points); // bv points
    list[id][6] = to_string(place);
}

void VoteList::showList(const vector<vector<string>> list, const bool hidePointsPlace) {
    for (int i = 0; i < size(list); ++i) {
        if (hidePointsPlace)  cout << "id: " << list[i][0] << " | "
                                   << "name: " << list[i][1] << endl;
        else cout << "id: " << list[i][0] << " | "
                << "name: " << list[i][1] << " | "
                << "sb points: " << list[i][2] << " | "
                << "pv points: " << list[i][3] << " | "
                << "bc points: " << list[i][4] << " | "
                << "bv points: " << list[i][5] << " | "
                << "place: " << list[i][6] << endl;
    }
}

void VoteList::createVoteList(vector<vector<string>> &list) {
    unsigned listSize;
    unsigned points = 0;
    unsigned place = 0;
    string choiceName;

    cout << "Enter number of choices: ";
    cin >> listSize;
    list.resize(listSize);

    for (unsigned id = 0; id < size(list); ++id) {
        cout << "Enter choice name: ";
        cin >> choiceName;
        addToList(list, choiceName, id, points, place);
    }
}

// compIndex = 2 || 3 || 4 || 5
void VoteList::sortByPointsVoteList(vector<vector<string>> &list, const unsigned compIndex) {
    vector<string> tmp(size(list[0]));
    for (int i = 0; i < size(list)-1; ++i) {
        for (int j = 0; j < size(list)-1; ++j) {
            if (list[j][compIndex] < list[j+1][compIndex]) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
}

void VoteList::setPlacesByOrder(vector<vector<string>> &list) {
    for (int i = 0; i < size(list); ++i) {
        list[i][6] = to_string(i+1);
    }
}

void VoteList::addPoints(vector<vector<string>> &list, const unsigned id, const unsigned points, const unsigned pointsIndex) {
    for (int i = 0; i < size(list); ++i) {
        if (list[i][0] == to_string(id)) {
            list[i][pointsIndex] = to_string(stoi(list[i][pointsIndex]) + points);
        }
    }
}
