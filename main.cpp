#include <iostream>
#include "voteList.h"

using namespace std;


int main() {

    vector<vector<string>> voteList;

    VoteList::createVoteList(voteList);
    VoteList::showList(voteList);

    return 0;
}
