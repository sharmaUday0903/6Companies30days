class Solution
{
public:
    bool check(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        int s1 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        int s2 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        int s3 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        int s4 = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);
        int d1 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int d2 = (p4[0] - p3[0]) * (p4[0] - p3[0]) + (p4[1] - p3[1]) * (p4[1] - p3[1]);
        if ((s1 == s2) && (s2 == s3) && (s3 == s4) && (d1 == d2))
            return true;
        return false;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        if ((p1 == p2) || (p2 == p3) || (p3 == p4) || (p1 == p3) || (p1 == p4) || (p2 == p4))
            return false;
        bool c1 = check(p1, p2, p3, p4);
        bool c2 = check(p1, p3, p2, p4);
        bool c3 = check(p1, p4, p3, p2);
        if (c1 || c2 || c3)
            return true;
        return false;
    }
};