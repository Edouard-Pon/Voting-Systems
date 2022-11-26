#ifndef VOTING_SYSTEMS_CANDIDATELIST_H
#define VOTING_SYSTEMS_CANDIDATELIST_H

#include <iostream>
#include <vector>

using namespace std;


class CandidateList {

public:
    static void addToList(vector<vector<string>> &list, string name, unsigned id, unsigned points, unsigned place);
    static void showList(vector<vector<string>> list, unsigned voteSystemId, bool hidePointsPlace, unsigned numberOfCandidates);
    static void createVoteList(vector<vector<string>> &list);
    static void sortByPointsVoteList(vector<vector<string>> &list, unsigned compIndex, bool ascending);
    static void setPlacesByOrder(vector<vector<string>> &list);
    static void addPoints(vector<vector<string>> &list, unsigned id, int points, unsigned pointsIndex);
    static void removePoints(vector<vector<string>> &list, unsigned id, int points, unsigned pointsIndex);
    static string getCandidateNameById(vector<vector<string>> candidateList, unsigned candidateId);
    static unsigned getCandidateWithSamePoints(vector<vector<string>> candidateList, unsigned pointsIndex);
    static void resetCandidatesPoints(vector<vector<string>> &candidateList, unsigned pointsIndex);

};

#endif
