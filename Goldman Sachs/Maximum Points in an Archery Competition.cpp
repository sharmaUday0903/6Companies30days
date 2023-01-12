class Solution
{
public:
    vector<int> maximumBobPoints(int numArrows, vector<int> &aliceArrows)
    {
        vector<int> bobArrows;
        int fsum = 0;
        for (int i = 0; i < (1 << 12); i++)
        {
            int temp = numArrows;
            vector<int> tempv(12, 0);
            int sum = 0;
            for (int j = 11; j >= 0; j--)
            {
                if (i & (1 << j))
                {
                    if (temp > aliceArrows[j])
                    {
                        temp -= aliceArrows[j];
                        temp--;
                        tempv[j] = aliceArrows[j] + 1;
                    }
                }
            }
            for (int j = 0; j < 12; j++)
            {
                if (i & (1 << j))
                {
                    tempv[j] += temp;
                    break;
                }
            }
            for (int j = 0; j < 12; j++)
            {
                if (tempv[j] > aliceArrows[j])
                    sum += j;
            }
            if (sum > fsum)
            {
                fsum = sum;
                bobArrows = tempv;
            }
        }

        return bobArrows;
    }
};