template <typename T, typename F>
T myfilter(const T &v, F f)
{
    T n{};
    auto i = n.begin();
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (f(*it))
        {
            i = n.insert(i, *it);    
            i++;
        }
        
    }
    return n;
}
