class StockPrice
{
public:
    multiset<int> m;
    map<int, int> ma;

    void update(int timestamp, int price)
    {
        if (ma.find(timestamp) != ma.end())
        {
            m.erase(m.find(ma[timestamp]));
        }
        ma[timestamp] = price;
        m.insert(price);
    }

    int current()
    {
        return ma.rbegin()->second;
    }

    int maximum()
    {
        return *m.rbegin();
    }

    int minimum()
    {
        return *m.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */