#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query
{
    string type, s;
    size_t ind;
};

class QueryProcessor
{
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    size_t hash_func(const string& s) const
    {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (((hash * multiplier + s[i]) % prime) + prime) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}
    vector<string> result;
    Query readQuery() const
    {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found)
    {
        result.push_back(was_found ? "yes" : "no");
    }

    void processQuery(const Query& query)
    {
        if (query.type == "check")
        {
            string line = "";
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
            {
                if (hash_func(elems[i]) == query.ind)
                    line += elems[i] + " ";
            }
            if (!line.empty())
                line.pop_back();
            result.push_back(line);
        }
        else
        {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add")
            {
                if (it == elems.end())
                    elems.push_back(query.s);
            }
            else if (query.type == "del")
            {
                if (it != elems.end())
                    elems.erase(it);
            }
        }
    }

    void processQueries()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    for (auto& i: proc.result)
    {
        std::cout<<i<<std::endl;
    }
    return 0;
}


