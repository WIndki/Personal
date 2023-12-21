#include <iostream>
using namespace std;

bool allElementsSame(int arr[])
{
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] != arr[0])
        {
            return false;
        }
    }
    return true;
}

void giveCandy(int data[])
{
    int temp[10];
    for (int i = 0; i < 10; i++)
    {
        if (data[i] % 2 == 0)
        {
            temp[i] = data[i] = data[i] / 2;
        }
        else
        {
            temp[i] = data[i] = (data[i] + 1) / 2;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        data[i] += temp[i - 1];
    }
    data[0] += temp[9];
}

int main()
{
    int candy[10];
    while (cin >> candy[0])
    {
        int count = 0;
        for (int i = 1; i < 10; i++)
        {
            cin >> candy[i];
        }
        while (!allElementsSame(candy))
        {
            // cout << count <<": ";
            // for(int i=0;i<10;i++)cout<<candy[i]<<" ";
            // cout << endl;
            giveCandy(candy);
            count++;
        }
        // cout << count <<": ";
        // for(int i=0;i<10;i++)cout<<candy[i]<<" ";
        // cout << endl;
        cout << count << " " << candy[0] << endl;
    }
}
