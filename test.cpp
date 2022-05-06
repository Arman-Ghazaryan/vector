#include <iostream>
#include <algorithm>
#include <cassert>
#include <time.h>
#include "vector.h"

int main()
{
    {
        vector<int> vec;
        assert(!vec.size());
    }

    {
        vector<int> vec(20);
        assert(vec.size() == 20);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == 0);
    }

    {
        vector<int> vec(3, 7);
        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == 7);
    }

    {
        vector<int> std_vec({1, 2, 3});
        assert(std_vec.size() == 3);
        for (int i = 0; i < std_vec.size(); ++i)
            assert(std_vec[i] == i + 1);
    }

    {
        vector<int> std_vec({1, 2, 3});
        vector<int> copy_vec(std_vec);
        assert(copy_vec.size() == 3);
        for (int i = 0; i < copy_vec.size(); ++i)
            assert(copy_vec[i] == i + 1);
    }

    {
        vector<int> vec;
        for (int i = 0; i < 3; ++i)
        {
            vec.push_back(i);
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;
        for (int i = 0; i < 3; ++i)
        {
            vec.push_front(i);
            assert(vec[0] == i);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vec.push_back(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vec.push_front(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;

        vec.insert(0, 0);
        vec.insert(2, 1);
        vec.insert(1, 1);

        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i);
    }

    {
        vector<int> vec;

        vec.insert(0, 0, 3);
        vec.insert(2, 3, 3);
        vec.insert(1, 3, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d);
            assert(vec[i + 2] == d);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vec.insert(std_vec, 0);
        vec.insert(std_vec, 3);
        vec.insert(std_vec, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d + 1);
            assert(vec[i + 2] == d + 2);
        }
    }

    {
        vector<int> vec;
        vector<int>::iterator it;

        vec.insert(0, vec.begin());
        vec.insert(2, vec.end());
        it = vec.begin() + 1;
        vec.insert(1, it);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;
        vector<int>::iterator it;

        vec.insert(0, vec.begin(), 3);
        vec.insert(2, vec.end(), 3);
        it = vec.begin() + 3;
        vec.insert(1, it, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d);
            assert(vec[i + 2] == d);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int>::iterator it;
        vector<int> vec;

        vec.insert(std_vec, vec.begin());
        vec.insert(std_vec, vec.end());
        it = vec.begin() + 3;
        vec.insert(std_vec, it);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d + 1);
            assert(vec[i + 2] == d + 2);
        }
    }

    {
        vector<int> vec;
        vector<int>::iterator it;

        vec.insert(0, vec.begin());
        vec.insert(2, vec.end());
        it = vec.begin() + 1;
        vec.insert(1, it);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;
        vector<int>::iterator it;

        vec.insert(0, vec.begin(), 3);
        vec.insert(2, vec.end(), 3);
        it = vec.begin() + 3;
        vec.insert(1, it, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d);
            assert(vec[i + 2] == d);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vector<int>::const_iterator it = vec.begin();
        vec.insert(std_vec, it);
        vector<int>::const_iterator it1 = vec.end();
        vec.insert(std_vec, it1);
        vector<int>::const_iterator it2 = vec.begin() + 3;
        vec.insert(std_vec, it2);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d + 1);
            assert(vec[i + 2] == d + 2);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vec.insert(vec.begin(), std_vec.begin(), std_vec.end());
        vec.insert(vec.end(), std_vec.begin(), std_vec.end());
        vec.insert(vec.begin() + 3, std_vec.begin(), std_vec.end());

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d + 1);
            assert(vec[i + 2] == d + 2);
        }
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        vector<int>::const_iterator it = vec.begin();
        vec.insert(it, std_vec.begin(), std_vec.end());
        vector<int>::const_iterator it1 = vec.end();
        vec.insert(it1, std_vec.begin(), std_vec.end());
        vector<int>::const_iterator it2 = vec.begin() + 3;
        vec.insert(it2, std_vec.begin(), std_vec.end());

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == d);
            assert(vec[i + 1] == d + 1);
            assert(vec[i + 2] == d + 2);
        }
    }

    {
        vector<int> vec;

        vec.emplace(vec.begin(), 0);
        vec.emplace(vec.end(), 2);
        vec.emplace(vec.begin() + 1, 1);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;

        vector<int>::const_iterator it = vec.begin();
        vec.emplace(it, 0);
        vector<int>::const_iterator it1 = vec.end();
        vec.emplace(it1, 2);
        vector<int>::const_iterator it2 = vec.begin() + 1;
        vec.emplace(it2, 1);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec(1, 1);

        vec.emplace_front(0);
        vec.emplace_back(2);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == i);
        }
    }

    {
        vector<int> vec;

        vec.assign(20, 7);
        assert(vec.size() == 20);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == 7);
    }

    {
        vector<int> std_vec({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector<int> vec;

        vec.assign(std_vec.begin(), std_vec.end());

        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i);
    }

    {
        vector<int> vec({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

        vec.resize(5);

        assert(vec.size() == 5);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i);

        vec.resize(10);

        assert(vec.size() == 10);
        for (int i = 5; i < vec.size(); ++i)
            assert(vec[i] == 0);
    }

    {
        srand(time(NULL));

        vector<int> vec;

        for (int i = 0; i < 10; ++i)
            vec.push_back(rand() % 100);

        std::sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() - 1; ++i)
            assert(vec[i] <= vec[i + 1]);

        std::sort(vec.begin(), vec.end(), std::greater<int>());
        for (int i = 0; i < vec.size() - 1; ++i)
            assert(vec[i] >= vec[i + 1]);
    }

    {
        vector<int> vec({-1, 0, 1, 2, 3});

        vec.pop_back();
        vec.pop_front();

        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i);

        vec.clear();
        assert(!vec.size());
    }

    {
        vector<int> vec({-1, 0, 1, 2, 3});

        vec.erase(vec.begin());
        vec.erase(vec.end() - 1);
        vec.erase(vec.end());

        assert(vec.size() == 2);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i);
    }

    {
        vector<int> vec({-1, 0, 1, 2, 3});

        vec.erase(vec.begin(), vec.begin() + 1);

        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == i + 1);

        vec.erase(vec.begin(), vec.end());
        assert(vec.size() == 0);

        vec.assign(10, 7);

        vec.erase(vec.begin() + 2, vec.end() - 2);
        assert(vec.size() == 4);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == 7);

        vec.assign(10, 7);

        vec.erase(vec.end() - 3, vec.end());
        assert(vec.size() == 6);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == 7);

        for (int i = 0; vec.size(); ++i)
            vec.removeAt(0);

        assert(!vec.size());
    }

    {
        vector<int> std_vec({0, 1, 2});
        vector<int> vec;

        assert(!vec.empty());
        assert(std_vec.empty());

        vec = std_vec;

        assert(vec.front() == 0);
        assert(vec.at(1) == 1);
        assert(vec.back() == 2);
    }
}