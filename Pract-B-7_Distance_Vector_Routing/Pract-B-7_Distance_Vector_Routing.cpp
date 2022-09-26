#include <iostream>
using namespace std;

struct DVR_table
{
    int distance[10];
    int nexthop[10];
} rt[10];

int main()
{
    int n;
    cout << "Enter the Number of Nodes  ==> ";
    cin >> n;

    cout << "Enter the Distance Matrix :- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> rt[i].distance[j];
            // || rt[i].distance[j]!=999
            
            rt[i].nexthop[j] = -1;
        }
    }

    // DVR ALGORITHM
    for(int steps = 1; steps < n; steps++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    if (i == j)
                        continue;
                    if (rt[i].distance[j] > rt[i].distance[k] + rt[k].distance[j])
                    {
                        rt[i].distance[j] = rt[i].distance[k] + rt[k].distance[j];
                        rt[i].nexthop[j] = k;
                    }
                }
            }
        }
    }

    // Printing the Table
    for (int i = 1; i <= n; i++)
    {
        cout << "\n\nDistance Table For Router " << i << " :- \n";
        cout << "Destination \t  Distance \t  Next HOP\n";
        for (int j = 1; j <= n; j++)
        {
            cout << "\t" << j <<"\t\t"<< rt[i].distance[j] << "\t\t" ;
            if(rt[i].nexthop[j]==-1)
                cout<<"-";
            else
                cout<<rt[i].nexthop[j];
            cout << endl;
        }
    }
}