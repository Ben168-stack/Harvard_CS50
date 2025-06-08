// #include <cs50.h>
#include "cs50.h"
#include "cs50.c"
#include <stdio.h>
#include<string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
void print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");
    
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        for (int x = 0; x < candidate_count; x++){
            string name = get_string("Rank %d: ", x + 1);
            int rank = i + 1;

            // Check for invalid vote
            if (!vote(i,rank,name))
            {
                printf("Invalid vote.\n");
            }
        }
        
        
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(int voter, int rank, string name)
{
    for(int i = 0; i < candidate_count; i++){
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
        }

    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes){
            printf("%s\n",candidates[i].name);
        }

    }

    return;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO 
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
}



// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int minvotes)
{
    // TODO
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int minvotes)
{
    // TODO
 
}