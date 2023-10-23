#include <bits/stdc++.h>
using namespace std;

int CarFueling(long dis, int cap, int n, vector<long> &station)
{
    long way = 0;
    int d = 0;
    if (cap >= dis) return 0;
    if ((dis - station[n-1]) > cap) return -1;
    else
    {
        for (int i = 0; i < n && way < dis;)
        {
            way += cap;
            if (station[i] > way)
            {
                break;
                return -1;
            }
            if (station[i] == way)
            {
                d++;
                i++;
            }
            while (station[i] < way)
            {
                i++;
                if (station[i] > way)
                {
                    return -1;
                    break;
                }
                else if (station[i+1] == way)
                {
                    d++;
                    i++;
                }
                else if (station[i] < way && way < station [i+1]|| station[i] == way)
                {
                    d++;
                    way = station[i];
                }
            }
        }
    }
    return d;
}

int main()
{
    long dis;
    cin>>dis;
    int cap;
    cin>>cap;
    int n;
    cin>>n;
    vector<long> station(n);
    for (int i = 0; i < n; i++)
        cin>>station[i];
    cout<<CarFueling(dis, cap, n, station);
    return 0;
}
