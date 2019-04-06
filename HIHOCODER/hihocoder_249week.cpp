#include<iostream>

using namespace std;

char maze[10][10];
int n, m;
int player_hp;
int player_attack;
int entrance_i;
int entrance_j;
unsigned allmask;
int visited[1 << 28];

struct Monster
{
    int hp;
    int attack;
    char type;
    int cost[6];
    int buff[6];

    void set(int h, int a, char t)
    {
        hp = h;
        attack = a;
        type = t;
    }

    void cal()
    {
        for (int i = 0; i <= 5; ++i)
        {
            int monster_hp = hp;
            int buff_left = i;
            
            while(buff_left && monster_hp > 0)
            {
                monster_hp -= player_attack;
                --buff_left;
            }

            if (monster_hp > 0)
            {
                int attack_num = (monster_hp + player_attack - 1) / player_attack;
                cost[i] = attack * attack_num;
            }

            if(type == 'S')
            {
                buff_left = 5;
            }

            buff[i] = buff_left;
        }
    }
};

Monster monsters[100];

unsigned getmask(int i,int j)
{
    return 1 << (i * (m + 1) + j);
}

unsigned neighbormask(unsigned mask)
{
    return (mask << (1 + m)) | (mask >> (1 + m)) | (mask >> 1) | (mask << 1);
}

int search(int cur)
{
    if (visited[cur] != 0)
    {
        return visited[cur];
    }

    int curmask = (cur >> 3);
    int curbuff = cur & 7;

    if((curmask & allmask) == allmask)
    {
        visited[cur] = 1;
        return 1;
    }

    visited[cur] = player_hp + 1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            unsigned tempmask = getmask(i, j);

            if(tempmask & curmask)
            {
                continue;
            }

            unsigned neighbor = neighbormask(tempmask);

            if((neighbor & curmask) == 0)// no neighbor
            {
                continue;
            }
            
            int tempbuff = curbuff - 1;

            if (tempbuff < 0)
            {
                tempbuff = 0;
            }
            
            int cost = 0;
            
            if(maze[i][j] != '.')
            {
                int monster_i = maze[i][j];
                cost = monsters[monster_i].cost[tempbuff];
                tempbuff = monsters[monster_i].buff[tempbuff];
            }

            int cost2 = search(((curmask | tempmask) << 3) | tempbuff);
            int cost_total = cost2 + cost;
            visited[cur] = min(visited[cur], cost_total);
        }
    }

    return visited[cur];
}

int main()
{
    int hp;
    int attack;

    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        cin >> maze[i];
    }

    int monster_len=0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(maze[i][j] == 'S')
            {
                cin >> hp >> attack;

                maze[i][j] = monster_len;
                monsters[monster_len++].set(hp, attack, 'S');
                allmask |= getmask(i, j);
            }
            else if(maze[i][j]=='M')
            {
                cin >> hp >> attack;

                maze[i][j] = monster_len;
                monsters[monster_len++].set(hp, attack, 'M');
                allmask |= getmask(i, j);
            }
            else if(maze[i][j]=='D')
            {
                entrance_i=i;
                entrance_j=j;
            }
        }
    }

    cin >> player_hp >> player_attack;

    for(int i = 0; i < monster_len; ++i)
    {
        monsters[i].cal();
    }

    int remain_hp = player_hp - search((getmask(entrance_i,entrance_j) << 3) + 5) + 1;

    if(remain_hp <= 0)
    {
        cout << "DEAD" << endl;
    }
    else
    {
        cout << remain_hp << endl;
    }

    return 0;
}
