#include "pluralityVoting.h"
#include "voteList.h"


void PluralityVoting::makeVote(vector<vector<string>> &list) {
    unsigned nameId;

    VoteList::showList(list, true);
    cout << "Make your vote by choosing id: ";
    cin >> nameId;

    VoteList::addPoints(list, nameId, 1);
}
