#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <ctime>
#include <map>
using namespace std;

map<int, int> adds;

void initMap(map<int, int> &map)
{
    map.insert(make_pair(1972, 3));
    map.insert(make_pair(1973, 1));
    map.insert(make_pair(1974, 1));
    map.insert(make_pair(1975, 1));
    map.insert(make_pair(1976, 1));
    map.insert(make_pair(1977, 1));
    map.insert(make_pair(1978, 1));
    map.insert(make_pair(1979, 1));
    map.insert(make_pair(1981, 2));
    map.insert(make_pair(1982, 2));
    map.insert(make_pair(1983, 2));
    map.insert(make_pair(1985, 2));
    map.insert(make_pair(1987, 1));
    map.insert(make_pair(1989, 1));
    map.insert(make_pair(1990, 1));
    map.insert(make_pair(1992, 2));
    map.insert(make_pair(1993, 2));
    map.insert(make_pair(1994, 2));
    map.insert(make_pair(1995, 1));
    map.insert(make_pair(1997, 2));
    map.insert(make_pair(1998, 1));
    map.insert(make_pair(2005, 1));
    map.insert(make_pair(2008, 1));
    map.insert(make_pair(2012, 2));
    map.insert(make_pair(2015, 2));
    map.insert(make_pair(2016, 1));
}

int dayInYear(int year)
{
    return year % 4 == 0 ? 366 : 365;
}

int dayInMonth(int year, int month)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0 && month == 2)
    {
        return 29;
    }

    return days[month];
}

int secondsBefore(int year, int month, int day, int hour, int minute, int second)
{
    int res = 0;

    for(int i = 1970; i < year; ++i)
    {
        res += dayInYear(i) * 24 * 3600;

        if (adds.find(i) != adds.end())
        {
            res += (adds[i] + 1) >> 1;
        }
    }

    for (int i = 1; i < month; ++i)
    {
        res += dayInMonth(year, i) * 24 * 3600;

        if (i == 7 && adds.find(year) != adds.end() && adds[year] >= 2)
        {
            res++;
        }
    }

    for (int i = 1; i < day; ++i)
    {
        res += 24 * 3600;
    }

    for (int i = 0; i < hour; i++)
    {
        res += 3600;
    }
    for (int i = 0; i < minute; i++)
    {
        res += 60;
    }

    for (int i = 0; i <= second; i++)
    {
        res += 1;
    }

    return res;
}

int main()
{
    initMap(adds);

    int year1 = 0, month1 = 0, day1 = 0, hour1 = 0, minute1 = 0, second1 = 0,
        year2 = 0, month2 = 0, day2 = 0, hour2 = 0, minute2 = 0, second2 = 0;
    scanf("%d-%d-%d %d:%d:%d", &year1, &month1, &day1, &hour1, &minute1, &second1);
    scanf("%d-%d-%d %d:%d:%d", &year2, &month2, &day2, &hour2, &minute2, &second2);

    std::cout << secondsBefore(year2, month2, day2, hour2, minute2, second2) -
            secondsBefore(year1, month1, day1, hour1, minute1, second1) << std::endl;

    return 0;
}
