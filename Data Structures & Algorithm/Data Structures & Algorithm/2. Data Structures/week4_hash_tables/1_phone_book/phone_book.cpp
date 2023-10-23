#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;
using std::unordered_map;

struct Query
{
    string type, name;
    int number;
};

unordered_map<int, string> queryMap;

vector<Query> read_queries()
{
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> queries[i].type;
        if (queries[i].type == "add")
        {
            cin >> queries[i].number >> queries[i].name;
            queryMap[queries[i].number] = queries[i].name;
        }
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result)
{
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

/*
vector<string> process_queries(const vector<Query>& queries)
{
    vector<string> result;
    for (size_t i = 0; i < queries.size(); ++i)
    {
        if (queries[i].type == "add")
            queryMap[queries[i].number] = queries[i].name;

        else if (queries[i].type == "del")
        {
            auto it = queryMap.find(queries[i].number);
            if (it != queryMap.end())
                queryMap.erase(it);
        }
        else
        {
            string response = "not found";
            auto it = queryMap.find(queries[i].number);
            if (it != queryMap.end())
                response = queryMap[queries[i].number];
            result.push_back(response);
        }
    }
    return result;
}
*/

vector<string> process_queries(const vector<Query>& queries)
{
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add")
        {
            bool was_founded = false;
            // if we already have contact with such number,
            // we should rewrite contact's name
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number)
                {
                    contacts[j].name = queries[i].name;
                    was_founded = true;
                    break;
                }
            // otherwise, just add it
            if (!was_founded)
                contacts.push_back(queries[i]);
        }
        else if (queries[i].type == "del")
        {
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number)
                {
                    contacts.erase(contacts.begin() + j);
                    break;
                }
        }
        else
        {
            string response = "not found";
            for (size_t j = 0; j < contacts.size(); ++j)
                if (contacts[j].number == queries[i].number)
                {
                    response = contacts[j].name;
                    break;
                }
            result.push_back(response);
        }
    return result;
}

int main()
{
    write_responses(process_queries(read_queries()));
    std::cin.get();
    return 0;
}
/*
100
find 1
del 7
add 4 aAbcAba
add 0 CCaABcc
add 9 cacCCbA
del 4
add 8 BbccbCC
find 8
add 2 AcaABAB
del 4
find 5
add 5 BCBACcb
find 1
add 7 BacaACB
find 1
add 1 baCcccC
del 5
add 2 abcBAbC
find 7
add 6 bacABAA
find 1
del 4
add 2 BAABCcB
find 3
add 2 BCCCcCc
add 2 abBaBcB
add 1 BBbAACb
del 6
find 8
del 5
find 7
add 6 CcbAccb
add 1 BcCccAc
add 8 ABcaaAa
del 9
del 2
find 7
find 9
add 5 CAACaBA
add 4 bBBbaba
add 3 CccbcbC
find 1
del 2
del 3
add 3 BCcbABC
find 4
find 1
find 1
del 3
del 8
del 7
find 4
find 2
find 7
find 7
del 9
del 3
find 1
add 9 CbcBCAC
find 8
add 6 acacCAA
del 5
find 0
del 2
del 8
add 6 bbbAabA
find 0
find 2
find 4
add 8 AAcCaaC
find 6
find 5
find 0
add 9 BccCCca
del 0
find 0
add 6 aaCAaaC
del 1
add 3 cAbaBAb
del 8
add 9 aCbacaC
find 3
add 4 AAcBbCA
del 4
add 6 ababCCB
add 0 bbCaBab
add 6 aabCbbA
del 6
add 1 cccBabB
find 8
add 4 CaabBCC
del 9
find 6
del 3
add 7 bCcCaCA
add 8 BACAbBb
add 8 AacbaCC
find 2
add 9 BaabCaC
find 1
cccBabB
BbccbCC
CAACaBA
cccBabB
cccBabB
BacaACB
baCcccC
cAbaBAb
BbccbCC
BacaACB
BacaACB
not found
BcCccAc
bBBbaba
BcCccAc
BcCccAc
bBBbaba
not found
not found
not found
BcCccAc
not found
CCaABcc
CCaABcc
not found
bBBbaba
bbbAabA
not found
CCaABcc
not found
cAbaBAb
not found
not found
not found
cccBabB
*/
