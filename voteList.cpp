#include "voteList.h"


void VoteList::addToList(vector<vector<string>> &list, const string name, const unsigned id, const unsigned points, const unsigned place) {
    list[id].resize(4);
    list[id][0] = to_string(id);
    list[id][1] = name;
    list[id][2] = to_string(points);
    list[id][3] = to_string(place);
}

void VoteList::showList(const vector<vector<string>> list) {
    for (int i = 0; i < size(list); ++i) {
        cout << "id: " << list[i][0] << " | "
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

}
