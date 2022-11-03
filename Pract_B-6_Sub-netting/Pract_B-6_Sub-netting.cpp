#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    // Accept the IP Address From User
    string IP;
    cout << "Enter the IP Address ==> ";
    cin >> IP;

    // Split the IP string in differant octates
    stringstream ss(IP);
    string word;
    int ip_add[4];
    int i = 0;
    while (!ss.eof())
    {
        getline(ss, word, '.');
        int t = stoi(word);
        if (t >= 0 && t <= 255)
            ip_add[i++] = t;
        else
        {
            cout << "Invalid IP Address \nTerminating Program....";
            return (0);
        }
    }

    // Check the Class of the IP
    int mask[4];
    if (ip_add[0] >= 0 && ip_add[0] <= 127)
    {
        mask[0] = 255, mask[1] = mask[2] = mask[3] = 0;
        cout << "CLASS A IP Address" << endl;
        cout << "Subnet MAsk :-  255.0.0.0" << endl;
    }
    else if (ip_add[0] >= 128 && ip_add[0] <= 191)
    {
        mask[0] = mask[1] = 255, mask[2] = mask[3] = 0;
        cout << "CLASS B IP Address" << endl;
        cout << "Subnet MAsk :-  255.255.0.0" << endl;
    }
    else if (ip_add[0] >= 192 && ip_add[0] <= 223)
    {
        mask[0] = mask[1] = mask[2] = 255, mask[3] = 0;
        cout << "CLASS C IP Address" << endl;
        cout << "Subnet MAsk :-  255.255.255.0" << endl;
    }
    else if (ip_add[0] >= 224 && ip_add[0] <= 239)
    {
        mask[0] = 255, mask[1] = mask[2] = mask[3] = 0;
        cout << "CLASS D IP Address" << endl;
    }
    else if (ip_add[0] >= 240 && ip_add[0] <= 255)
    {
        mask[0] = 255, mask[1] = mask[2] = mask[3] = 0;
        cout << "CLASS E IP Address" << endl;
    }
    if (ip_add[0] > 255 || ip_add[0] < 0)
        return 0;

    // We can find Network IP and Direct Broadcasting IP only of class A,B,C
    if(ip_add[0]>=0 && ip_add[0]<=223)
    { 
        // Find the network IP and direct Broadcast IP
        int network_add[4], last_add[4];
        for (int i = 0; i < 4; i++)
        {
            network_add[i] = ip_add[i] & mask[i];
            if (mask[i] == 0)
                last_add[i] = 255;
            else
                last_add[i] = ip_add[i];
        }

        // Printing the first IP and Last IP
        cout << "First Ip (Network IP) of subnet is :-  ";
        for (int i = 0; i < 4; i++)
            cout << network_add[i] << ".";
        cout << endl;

        cout << "Last Ip (Direct Broadcasting IP) of subnet is :-  ";
        for (int i = 0; i < 4; i++)
            cout << last_add[i] << ".";
        cout << endl;
    }
}