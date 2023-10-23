#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<long> NaivePointsAndSegments(std::vector<std::vector<long long>>& seg, std::vector<long long>& point)
{
    long row = seg.size();
    //long col = seg[0].size();
    long n = point.size();

    std::vector<long> ans(n, 0);

    for (long i = 0; i < row; i++)
            for (long j = 0; j < n; j++)
                if(seg[i][0] <= point[j] && point[j] <= seg[i][1])
                    ans[j] = ans[j] + 1;
    return ans;
}

std::vector<long> PointsAndSegments(const std::vector<std::vector<long long>>& segs, const std::vector<long long>& points)
{
    int start_label = 0, point_label = 1, end_label = 2;
    std::vector<long> ans(points.size(), 0);
    std::unordered_map<long long, std::vector<long>> point_map;

    long n = segs.size();
    std::vector<std::pair<long long, int>> merged;
    for (long i = 0; i < n; i++)
        merged.push_back(std::make_pair(segs[i][0], start_label));
    for (long i = 0; i < n; i++)
        merged.push_back(std::make_pair(segs[i][1], end_label));
    for (long i = 0; i < points.size(); i++)
    {
        merged.push_back(std::make_pair(points[i], point_label));

        if (point_map.find(points[i]) == point_map.cend())
        {
            point_map[points[i]] = std::vector<long> {i};
        }
        else
        {
            point_map[points[i]].push_back(i);
        }

    }

    for (const auto& [i, j] : point_map)
    {
        std::cout<<"point_map["<<i<<"] = ";
        for (const auto& k : j)
            std::cout<<k<<' ';
        std::cout<<'\n';
    }

    std::sort(merged.begin(), merged.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    int counter = 0;
    for (auto& i : merged)
    {
        if (i.second == start_label)
        {
            counter += 1;
        }
        else if (i.second == end_label)
        {
            counter -= 1;
        }
        else if (i.second == point_label)
        {
            std::vector<long>& indices = point_map[i.first];
            for (auto j : indices)
            {
                ans[j] = counter;
            }

        }
    }

    return ans;
}

std::vector<long> EvenBetterPointsAndSegments(const std::vector<std::vector<long long>>& segs, const std::vector<long long>& points)
{
    std::vector<long long> start_, end_;
    std::vector<long> ans;
    for (auto& seg : segs)
    {
        start_.push_back(seg[0]);
        end_.push_back(seg[1]);
    }
    sort(start_.begin(), start_.end());
    sort(end_.begin(), end_.end());
    for (auto& point : points)
    {
        long upper = std::upper_bound(start_.begin(), start_.end(), point) - start_.begin();
        long lower = std::lower_bound(end_.begin(), end_.end(), point) - end_.begin();
        ans.push_back(upper - lower);
    }
    return ans;
}

int main()
{
    /*
    while (true)
    {
        int m = rand() % 10 + 1;
        int n = rand() % 10 + 1;
        std::cout<<m<<' '<<n<<'\n';

        std::vector<std::vector<long long>> segs(m, std::vector<long long> (2));
        segs[0][0] = rand() % 20;
        segs[0][1] = rand() % 20 + segs[0][0];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < 2; j++)
                segs[i][j] = rand() % 20 + segs[i][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < 2; j++)
                std::cout<<segs[i][j]<<' ';
        std::cout<<'\n';

        std::vector<long long> points(n, 0);
        points[0] = rand() % 20;
        for (int i = 1; i < n; i++)
            points[i] = rand() % 20;
        for (int i = 0; i < n; i++)
            std::cout<<points[i]<<' ';
        std::cout<<'\n';

        auto res1 = NaivePointsAndSegments(segs, points);
        auto res2 = PointsAndSegments(segs, points);
        if (res1 != res2)
        {
            std::cout<<"Wrong answer: ";
            for (long long i : res1)
                std::cout<<i<<' ';
            std::cout<<" != ";
            for (long long i : res2)
                std::cout<<i<<' ';
            std::cout<<"\n\n";
            break;
        }
        else
        {
            std::cout<<"OK: ";
            for (long long i : res1)
                std::cout<<i<<' ';
            std::cout<<" != ";
            for (long long i : res2)
                std::cout<<i<<' ';
            std::cout<<"\n\n";
        }
    }
    */
    long m, n;
    std::cin>>m>>n;

    std::vector<std::vector<long long>> seg(m, std::vector<long long> (2));
    for (long i = 0; i < m; i++)
        for (long j = 0; j < 2; j++)
            std::cin>>seg[i][j];

    std::vector<long long> point(n, 0);
    for (long i = 0; i < n; i++)
        std::cin>>point[i];

    auto Sequence = EvenBetterPointsAndSegments(seg, point);

    for (long i : Sequence)
        std::cout<<i<<' ';

    return 0;
}
