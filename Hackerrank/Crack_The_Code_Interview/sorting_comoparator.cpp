/*
using namespace std;

struct Player {
    string name;
    int score;
};
*/
bool mycompare(Player p1, Player p2)
{
    return p1.score > p2.score;
}
bool mycompare2(Player p1, Player p2)
{
    return p1.name < p2.name;
}
vector<Player> comparator(vector<Player> players)
{
    sort(players.begin(), players.end(), mycompare);
    vector< vector<Player> > sortbygroup;
    vector<Player> one_group_same_score;
    /*printf("After first sort : ");
    for(int i = 0; i < players.size(); i++)
    {
        printf("%s %d", players[i].name.c_str() ,players[i].score);
    }
    printf("\n");*/
    for(int i = 0; i < players.size() - 1; i++)
    {
        if(players[i].score == players[i + 1].score)
        {
            one_group_same_score.push_back(players[i]);
            if(i == players.size() - 2)
            {
                one_group_same_score.push_back(players[i + 1]);
                sortbygroup.push_back(one_group_same_score);
            }
        }
        else //breakpoint
        {
            // printf("Different at %d \n",i);
            one_group_same_score.push_back(players[i]);
            sortbygroup.push_back(one_group_same_score);
            //in different group for the last element
            one_group_same_score.clear();
            if(i == players.size() - 2)
            {
                one_group_same_score.push_back(players[i + 1]);
                sortbygroup.push_back(one_group_same_score);
            }
        }
    }
    // printf("Group size(differnet scores): %d",sortbygroup.size());
    for(int i = 0; i < sortbygroup.size(); i++)
    {
        sort(sortbygroup[i].begin(), sortbygroup[i].end(), mycompare2);
    }
    players.clear();
    for(int i = 0; i < sortbygroup.size(); i++)
    {
        for(int j = 0; j < sortbygroup[i].size(); j++)
        {
            players.push_back(sortbygroup[i][j]);
        }
    }
    return players;
}
