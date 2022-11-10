#include <iostream>
using namespace std;

struct DVR_table
{
    int distance[10];
    int nexthop[10];
} rt[10];

int main()
{
    //Input No. of Nodes
    int n;
    cout << "Enter the Number of Router Nodes  ==> ";
    cin >> n;

    //Input Adjacency Matrix of Distance Between Routers
    cout << "Enter the Distance Matrix :- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> rt[i].distance[j];
            
            // Initially We don't know the next hop so set it as -1
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

    // Printing the Distance Table
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

    return 0;
}