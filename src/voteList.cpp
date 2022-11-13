#include "voteList.h"


void VoteList::addToList(vector<vector<string>> &list, const string name, const unsigned id, const unsigned points, const unsigned place) {
    list[id].resize(4);
    list[id][0] = to_string(id+1);
    list[id][1] = name;
    list[id][2] = to_string(points);
    list[id][3] = to_string(place);
}

void VoteList::showList(const vector<vector<string>> list, const bool hidePointsPlace) {
    for (int i = 0; i < size(list); ++i) {
        if (hidePointsPlace)  cout << "id: " << list[i][0] << " | "
                                   << "name: " << list[i][1] << endl;
        else cout << "id: " << list[i][0] << " | "
                << "name: " << list[i][1] << " | "
                << "points: " << list[i][2] << " | "
                << "place: " << list[i][3] << endl;
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

void VoteList::sortByPointsVoteList(vector<vector<string>> &list) {
    vector<string> tmp(size(list[0]));
    for (int i = 0; i < size(list)-1; ++i) {
        for (int j = 0; j < size(list)-1; ++j) {
            if (list[j][2] < list[j+1][2]) {
                tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
}

void VoteList::setPlacesByOrder(vector<vector<string>> &list) {
    for (int i = 0; i < size(list); ++i) {
        list[i][3] = to_string(i+1);
    }
}

void VoteList::addPoints(vector<vector<string>> &list, const unsigned id, const unsigned points) {
    for (int i = 0; i < size(list); ++i) {
        if (list[i][0] == to_string(id)) {
            list[i][2] = to_string(stoi(list[i][2]) + points);
        }
    }
}
