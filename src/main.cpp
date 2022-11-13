#include <iostream>
#include "voteList.h"

using namespace std;


int main() {

    vector<vector<string>> voteList;

    VoteList::createVoteList(voteList);
    VoteList::showList(voteList);

    // Tests

    for (int i = 0; i < size(voteList); ++i) {
        voteList[i][2] = to_string(rand() % 10);
    }

    cout << endl;
    VoteList::showList(voteList);

    VoteList::sortByPointsVoteList(voteList);

    cout << endl;
    VoteList::showList(voteList);

    VoteList::setPlacesByOrder(voteList);

    cout << endl;
    VoteList::showList(voteList);

    return 0;
}
