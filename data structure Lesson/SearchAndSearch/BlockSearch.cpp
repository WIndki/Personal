#include <iostream>
#include <vector>

using namespace std;

struct Block
{
    int key;
    int start;
    int end;
};

int blockSearch(vector<int> &arr, vector<Block> &blocks, int kval)
{
    int blockIndex = -1;
    for (int i = 0; i < blocks.size(); i++)
    {
        if (kval <= blocks[i].key)
        {
            blockIndex = i;
            break;
        }
    }

    if (blockIndex != -1)
    {
        for (int i = blocks[blockIndex].start; i <= blocks[blockIndex].end; i++)
        {
            if (arr[i] == kval)
            {
                return i + 1;
            }
        }
    }

    return 0; // kval not found
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int kval;
    cin >> kval;

    // Define the blocks
    vector<Block> blocks(3);
    blocks[0].key = arr[(n / 3) - 1];
    blocks[0].start = 0;
    blocks[0].end = (n / 3) - 1;

    blocks[1].key = arr[2 * (n / 3) - 1];
    blocks[1].start = n / 3;
    blocks[1].end = 2 * (n / 3) - 1;

    blocks[2].key = arr[n - 1];
    blocks[2].start = 2 * n / 3;
    blocks[2].end = n - 1;
    int result = blockSearch(arr, blocks, kval);
    cout << result;

    return 0;
}
