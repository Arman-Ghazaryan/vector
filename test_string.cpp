#include <iostream>
#include <algorithm>
#include <cassert>
#include "vector.h"
#include <string>

int main()
{
    {
        vector<std::string> vec;
        assert(!vec.size());
    }

    {
        vector<std::string> vec(10);
        assert(vec.size() == 10);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == "");
    }

    {
        vector<std::string> vec(3, "code");
        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == "code");
    }

    {
        vector<std::string> std_vec({std::to_string(1), std::to_string(2), std::to_string(3)});
        assert(std_vec.size() == 3);
        for (int i = 0; i < std_vec.size(); ++i)
            assert(std_vec[i] == std::to_string(i + 1));
    }

    {
        vector<std::string> std_vec({std::to_string(1), std::to_string(2), std::to_string(3)});
        vector<std::string> copy_vec(std_vec);
        assert(copy_vec.size() == 3);
        for (int i = 0; i < copy_vec.size(); ++i)
            assert(copy_vec[i] == std::to_string(i + 1));
    }

    {
        vector<std::string> vec;
        for (int i = 0; i < 3; ++i)
        {
            vec.push_back(std::to_string(i));
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;
        for (int i = 0; i < 3; ++i)
        {
            vec.push_front(std::to_string(i));
            assert(vec[0] == std::to_string(i));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vec.push_back(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vec.push_front(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vec.push_back(std_vec);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;

        vec.insert(std::to_string(0), 0);
        vec.insert(std::to_string(2), 1);
        vec.insert(std::to_string(1), 1);

        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i));
    }

    {
        vector<std::string> vec;

        vec.insert(std::to_string(0), 0, 3);
        vec.insert(std::to_string(2), 3, 3);
        vec.insert(std::to_string(1), 3, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d));
            assert(vec[i + 2] == std::to_string(d));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vec.insert(std_vec, 0);
        vec.insert(std_vec, 3);
        vec.insert(std_vec, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d + 1));
            assert(vec[i + 2] == std::to_string(d + 2));
        }
    }

    {
        vector<std::string> vec;
        vector<std::string>::iterator it;

        vec.insert(std::to_string(0), vec.begin());
        vec.insert(std::to_string(2), vec.end());
        it = vec.begin() + 1;
        vec.insert(std::to_string(1), it);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;
        vector<std::string>::iterator it;

        vec.insert(std::to_string(0), vec.begin(), 3);
        vec.insert(std::to_string(2), vec.end(), 3);
        it = vec.begin() + 3;
        vec.insert(std::to_string(1), it, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d));
            assert(vec[i + 2] == std::to_string(d));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string>::iterator it;
        vector<std::string> vec;

        vec.insert(std_vec, vec.begin());
        vec.insert(std_vec, vec.end());
        it = vec.begin() + 3;
        vec.insert(std_vec, it);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d + 1));
            assert(vec[i + 2] == std::to_string(d + 2));
        }
    }

    {
        vector<std::string> vec;
        vector<std::string>::iterator it;

        vec.insert(std::to_string(0), vec.begin());
        vec.insert(std::to_string(2), vec.end());
        it = vec.begin() + 1;
        vec.insert(std::to_string(1), it);

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;
        vector<std::string>::iterator it;

        vec.insert(std::to_string(0), vec.begin(), 3);
        vec.insert(std::to_string(2), vec.end(), 3);
        it = vec.begin() + 3;
        vec.insert(std::to_string(1), it, 3);

        for (int i = 0, d = 0; i < vec.size(); i += 3, ++d)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d));
            assert(vec[i + 2] == std::to_string(d));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vector<std::string>::const_iterator it = vec.begin();
        vec.insert(std_vec, it);
        vector<std::string>::const_iterator it1 = vec.end();
        vec.insert(std_vec, it1);
        vector<std::string>::const_iterator it2 = vec.begin() + 3;
        vec.insert(std_vec, it2);

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d + 1));
            assert(vec[i + 2] == std::to_string(d + 2));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vec.insert(vec.begin(), std_vec.begin(), std_vec.end());
        vec.insert(vec.end(), std_vec.begin(), std_vec.end());
        vec.insert(vec.begin() + 3, std_vec.begin(), std_vec.end());

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d + 1));
            assert(vec[i + 2] == std::to_string(d + 2));
        }
    }

    {
        vector<std::string> std_vec({std::to_string(0), std::to_string(1), std::to_string(2)});
        vector<std::string> vec;

        vector<std::string>::const_iterator it = vec.begin();
        vec.insert(it, std_vec.begin(), std_vec.end());
        vector<std::string>::const_iterator it1 = vec.end();
        vec.insert(it1, std_vec.begin(), std_vec.end());
        vector<std::string>::const_iterator it2 = vec.begin() + 3;
        vec.insert(it2, std_vec.begin(), std_vec.end());

        for (int i = 0, d = 0; i < vec.size(); i += 3)
        {
            assert(vec[i] == std::to_string(d));
            assert(vec[i + 1] == std::to_string(d + 1));
            assert(vec[i + 2] == std::to_string(d + 2));
        }
    }

    {
        vector<std::string> vec;
        // vec.reserve(3);
        vec.emplace(vec.begin(), std::to_string(0));
        vec.emplace(vec.end(), "2");
        vec.emplace(vec.begin() + 1, std::to_string(1));

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;

        vector<std::string>::const_iterator it = vec.begin();
        vec.emplace(it, std::to_string(0));
        vector<std::string>::const_iterator it1 = vec.end();
        vec.emplace(it1, std::to_string(2));
        vector<std::string>::const_iterator it2 = vec.begin() + 1;
        vec.emplace(it2, std::to_string(1));

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec(1, std::to_string(1));

        vec.emplace_front(std::to_string(0));
        vec.emplace_back(std::to_string(2));

        for (int i = 0; i < 3; ++i)
        {
            assert(vec[i] == std::to_string(i));
        }
    }

    {
        vector<std::string> vec;

        vec.assign(10, std::to_string(7));

        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(7));
    }

    {
        vector<std::string> std_vec({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"});
        vector<std::string> vec;

        vec.assign(std_vec.begin(), std_vec.end());

        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i));
    }

    {
        vector<std::string> vec({"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"});

        vec.resize(5);

        assert(vec.size() == 5);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i));

        vec.resize(10);

        assert(vec.size() == 10);
        for (int i = 5; i < vec.size(); ++i)
            assert(vec[i] == "");
    }

    {
        vector<std::string> vec({"-1", "0", "1", "2", "3"});

        vec.pop_back();
        vec.pop_front();

        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i));

        vec.clear();
        assert(!vec.size());
    }

    {
        vector<std::string> vec({"-1", "0", "1", "2", "3"});

        vec.erase(vec.begin());
        vec.erase(vec.end() - 1);
        vec.erase(vec.end());

        assert(vec.size() == 2);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i));
    }

    {
        vector<std::string> vec({"-1", "0", "1", "2", "3"});

        vec.erase(vec.begin(), vec.begin() + 1);

        assert(vec.size() == 3);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(i + 1));

        vec.erase(vec.begin(), vec.end());
        assert(vec.size() == 0);

        vec.assign(10, std::to_string(7));

        vec.erase(vec.begin() + 2, vec.end() - 2);
        assert(vec.size() == 4);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(7));

        vec.assign(10, std::to_string(7));

        vec.erase(vec.end() - 3, vec.end());
        assert(vec.size() == 6);
        for (int i = 0; i < vec.size(); ++i)
            assert(vec[i] == std::to_string(7));

        for (int i = 0; vec.size(); ++i)
            vec.removeAt(0);

        assert(!vec.size());
    }

    {
        vector<std::string> std_vec({"0", "1", "2"});
        vector<std::string> vec;

        assert(!vec.empty());
        assert(std_vec.empty());

        vec = std_vec;

        assert(vec.front() == std::to_string(0));
        assert(vec.at(1) == std::to_string(1));
        assert(vec.back() == std::to_string(2));
    }
}