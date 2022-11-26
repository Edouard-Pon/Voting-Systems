#include "election.h"
#include "secretBallot.h"
#include "candidateList.h"
#include "multipleChoiceVoting.h"
#include "bordaCountVoting.h"
#include "negativeVoting.h"
#include "voterList.h"

void Election::startVoting(vector<vector<std::string>> &candidateList, vector<vector<std::string>> &voterList,
                                    unsigned numberOfVoters, unsigned votingSystem) {
    for (int i = 0; i < numberOfVoters; ++i) {
        if (votingSystem == 1) SecretBallot::makeVote(candidateList);
        else if (votingSystem == 2) MultipleChoiceVoting::makeVote(candidateList, voterList);
        else if (votingSystem == 3) BordaCountVoting::makeVote(candidateList, voterList);
        else if (votingSystem == 4) NegativeVoting::makeVote(candidateList, voterList);
    }
}

void Election::electionCalculation(vector<vector<std::string>> &candidateList, vector<vector<std::string>> &voterList,
                                   const unsigned compIndex) {
    CandidateList::sortByPointsVoteList(candidateList, compIndex, false);
    CandidateList::setPlacesByOrder(candidateList);
}

void Election::clearVoterCandidateList(vector<vector<std::string>> &candidateList,
                                       vector<vector<std::string>> &voterList) {
    voterList.clear();
    CandidateList::sortByPointsVoteList(candidateList, 0, true);
}

void Election::startElection(vector<vector<string>> &candidateList, vector<vector<string>> &voterList,
                             unsigned numberOfVoters, unsigned votingSystemId, unsigned pointsIndex) {
    unsigned numberOfWinners;
    while (true) {
        startVoting(candidateList, voterList, numberOfVoters, votingSystemId);
        electionCalculation(candidateList, voterList, pointsIndex);
        CandidateList::showList(candidateList, votingSystemId, false, size(candidateList));
        numberOfWinners = CandidateList::getCandidateWithSamePoints(candidateList, pointsIndex);
        if (size(voterList) != 0) VoterList::showVoterList(voterList, false, votingSystemId);
        if (numberOfWinners == 1) {
            cout << "Winner of this vote" << endl;
            CandidateList::showList(candidateList, votingSystemId, false, 1);
            clearVoterCandidateList(candidateList, voterList);
            break;
        }
        cout << numberOfWinners << " Candidates in 1st place. Next tour with these Candidates will start!" << endl;
        if (size(candidateList) > 2) candidateList.erase(candidateList.begin() + numberOfWinners, candidateList.end());
        CandidateList::resetCandidatesPoints(candidateList, 2);
    }
}
