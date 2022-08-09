#include <stdio.h>
#include <math.h>
int bintodec(int b[])
{
    int ans = 4 * b[0] + 2 * b[1] + 1 * b[2];
    return ans;
}

int main()
{
    int d7, d6, d5, d3;
    printf("Enter the data d7 :- ");
    scanf("%d", &d7);
    printf("Enter the data d6 :- ");
    scanf("%d", &d6);
    printf("Enter the data d5 :- ");
    scanf("%d", &d5);
    printf("Enter the data d3 :- ");
    scanf("%d", &d3);

    int p1, p2, p4;
    p1 = d3 ^ d5 ^ d7;
    p2 = d3 ^ d6 ^ d7;
    p4 = d5 ^ d6 ^ d7;

    printf("\nparity bit p1 :- %d", p1);
    printf("\nparity bit p2 :- %d", p2);
    printf("\nparity bit p4 :- %d", p4);

    int encoded_data[7] = {p1, p2, d3, p4, d5, d6, d7};

    printf("\nEncoded Data after adding Parity :- ");
    for (int i = 6; i >= 0; i--)
    {
        printf("%d ", encoded_data[i]);
    }

    int recieved_data[7];
    int flag = 1;
    printf("\n\nEnter the Recieved data One By One :- ");
    for (int i = 6; i >= 0; i--)
    {
        scanf("%d", &recieved_data[i]);
    }

    int parity_check[3];
    p1 = recieved_data[0], p2 = recieved_data[1], p4 = recieved_data[3];
    d3 = recieved_data[2], d5 = recieved_data[4], d6 = recieved_data[5], d7 = recieved_data[6];

    parity_check[0] = p4 ^ d5 ^ d6 ^ d7;
    parity_check[1] = p2 ^ d3 ^ d6 ^ d7;
    parity_check[2] = p1 ^ d3 ^ d5 ^ d7;

    int error_loc = bintodec(parity_check);
    if (error_loc == 0)
    {
        printf("There is no error in data transmission ");
    }
    else
    {
        printf("\n\nError at Location %d", error_loc);
        printf("\nRecived data   :- ");
        for (int i = 6; i >= 0; i--)
        {
            printf("%d", recieved_data[i]);
        }
        recieved_data[error_loc - 1] ^= 1;
        printf("\nCorrected Data :- ");
        for (int i = 6; i >= 0; i--)
        {
            printf("%d", recieved_data[i]);
        }
    }
    return 0;
}