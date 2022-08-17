#include <iostream>
using namespace std;

int main()
{
    int w;
    cout << "Enter the size of the sliding window :- ";
    cin >> w;

    int f;
    cout << "Enter the number of frames :- ";
    cin >> f;

    int frames[f];
    cout << "Enter the " << f << " Frames one by one :- \n";
    for (int i = 0; i < f; i++)
    {
        cin >> frames[i];
    }

    cout << "\n\n(1 - Send acknowledgement 0-do not send acknowledgement) " << endl;

    for (int i = 0; i < w; i++)
    {
        if (i < f)
        {
            cout << "Sending data " << frames[i] << "..." << endl;
        }
    }

    bool flag = 0;
    for (int i = 0; i < f; i++)
    {

        cout << "\nSend the acknowledgement of '" << frames[i] << "' :- ";
        cin >> flag;

        if (flag == 1)
        {
            if (i + w < f)
            {
                cout << "Sending data " << frames[i + w] << "..." << endl;
            }
        }
        else
        {
            for (int j = i; j < i + w; j++)
            {
                if (j < f)
                {
                    cout << "Sending data " << frames[j] << "..." << endl;
                }
            }
            i--;
        }
    }

    cout << "\n\n Data Transfer Statistics Successfully "<<endl;
}
