#include <iostream>
using namespace std;

int main()
{
    // Input the size of the sliding window
    int w;
    cout << "\nEnter the size of the sliding window :- ";
    cin >> w;

    // Input the number of frames and all frames
    int f;
    cout << "\nEnter the number of frames :- ";
    cin >> f;

    int frames[f];
    cout << "\nEnter the " << f << " Frames one by one :- \n";
    for (int i = 0; i < f; i++)
    {
        cin >> frames[i];
    }

    // To send Acknowledgement press '1' and press '0' not to send Acknowledgement
    cout << "\n\n(1 - Send Acknowledgement 0-do not send Acknowledgement) " << endl;

    // Sending The Frames of Initial Sliding Window
    for (int i = 0; i < w; i++)
    {
        if (i < f)
        {
            cout << "Sending data " << frames[i] << "..." << endl;
        }
    }

    /*
        Take Acknowledgement of each frame
        If Acknowledgement received then send next one single frame  &
        If Acknowledgement not received then send whole sliding window again from starting
    */
    bool flag = 0;
    for (int i = 0; i < f; i++)
    {

        cout << "\nSend the Acknowledgement of '" << frames[i] << "'\n (1 or 0) :- ";
        cin >> flag;

        if (flag == 1)
        {
            if (i + w < f)
            {
                cout << "\nSending data " << frames[i + w] << "..." << endl;
            }
        }
        else
        {
            for (int j = i; j < i + w; j++)
            {
                if (j < f)
                {
                    cout << "\nSending data " << frames[j] << "...";
                }
            }
            cout << endl;
            i--;
        }
    }

    cout << "\n\n Frames Transfered Successfully " << endl;
}
