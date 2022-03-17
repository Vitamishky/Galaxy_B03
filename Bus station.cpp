#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main()
{
    int Q, Bus = 0;
    cin >> Q;
    map <int, string> help;
    map <pair<string, int>, vector<string>> bus_station;
    map <string, vector<string>> stops_for_bus;
    for(int i = 0; i < Q; i++)
    {
        string command;
        cin >> command;
        if(command == "ALL_BUSES")
        {
            if(bus_station.size() == 0)
                cout << "No buses" << endl;
            else
            {
                for(auto c : bus_station)
                {
                    cout << "Bus " << c.first.first << ": ";
                    for(auto f : c.second)
                    {
                        cout << f << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        else
        {
            if(command == "STOPS_FOR_BUS")
            {
                int w = 0;
                string bus;
                cin >> bus;
                for(auto c : bus_station)
                {
                    if(c.first.first == bus)
                    {
                        w = 1;
                        for(auto f : c.second)
                        {
                            cout << "Stop " << f << ": ";
                            string Proverka = "No";
                            string stop = f;
                            for(auto d : bus_station)
                            {
                                if(d.first.first != bus)
                                {
                                    for(auto r : d.second)
                                    {
                                        if(stop == r)
                                        {
                                            Proverka = "Yes";
                                            help[d.first.second] = d.first.first;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(Proverka == "Yes")
                            {
                                for(auto d : help)
                                {
                                    cout << d.second << " ";
                                }
                                cout << endl;
                            }
                            else
                            {
                                cout << "no interchange" << endl;
                            }
                            Proverka = "No";
                            help.clear();
                        }
                    }
                }
                if(w == 0)
                    cout << "No bus" << endl;
                w = 0;
            }
            if(command == "BUSES_FOR_STOP")
            {
                string Proverka = "No";
                string stop;
                cin >> stop;
                for(auto c : bus_station)
                {
                    for(auto f : c.second)
                    {
                        if(stop == f)
                        {
                            Proverka = "Yes";
                            help[c.first.second] = c.first.first;
                            break;
                        }
                    }
                }
                if(Proverka == "Yes")
                {
                    for(auto c : help)
                    {
                        cout << c.second << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No stop" << endl;
                }
                Proverka = "No";
                help.clear();
            }
            if(command == "NEW_BUS")
            {
                Bus++;
                string bus;
                int stop_count;
                cin >> bus >> stop_count;
                for(int j = 0; j < stop_count; j++)
                {
                    auto para = make_pair(bus, Bus);
                    string stop;
                    cin >> stop;
                    bus_station[para].push_back(stop);
                }
            }
        }
    }

    return 0;
}
/*
10
ALL_BUSES
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
ALL_BUSES
BUSES_FOR_STOP Vnukovo
BUSES_FOR_STOP Solntsevo
BUSES_FOR_STOP qwerty
STOPS_FOR_BUS 272
*/
