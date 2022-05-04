#pragma once
#include <vector>
#include <string>

template <typename T>
class vector
{
public:
    typedef T *iterator;
    typedef const T *const_iterator;
    typedef T *reverse_iterator;
    typedef const T *const_reverse_iterator;

    vector();
    vector(int size);
    vector(int size, T data);
    vector(std::vector<T> const &data);
    vector(vector<T> &data);

    void push_back(T data);
    void push_back(vector<T> data);
    void push_front(T data);
    void push_front(vector<T> data);

    void insert(T data, int pos);
    void insert(T data, iterator pos);
    void insert(T data, const_iterator pos);
    void insert(T data, int pos, int count);
    void insert(T data, iterator pos, int count);
    void insert(T data, const_iterator pos, int count);
    void insert(vector<T> &data, int pos);
    void insert(vector<T> &data, iterator pos);
    void insert(vector<T> &data, const_iterator pos);
    void insert(iterator pos, iterator secfpos, iterator seclpos);
    void insert(const_iterator pos, iterator secfpos, iterator seclpos);

    iterator emplace(iterator pos, T data);
    iterator emplace(const_iterator pos, T data);
    iterator emplace_back(T data);
    iterator emplace_front(T data);

    void assign(int count, T data);
    void assign(iterator fpos, iterator lpos);

    void resize(int new_size);
    void sort(std::string str);

    void clear();
    void pop_back();
    void pop_front();
    void erase(iterator pos);
    void erase(iterator fpos, iterator lpos);
    void removeAt(int pos);

    iterator begin() { return arr; }
    iterator end() { return arr + size(); }
    iterator begin() const { return arr; }
    iterator end() const { return arr + size(); }
    const_iterator cbegin() const { return arr; }
    const_iterator cend() const { return arr + size(); }
    reverse_iterator rbegin() { return arr + size(); }
    reverse_iterator rend() { return arr; }
    const_reverse_iterator crbegin() { return cend(); }
    const_reverse_iterator crend() { return cbegin(); }

    T &at(int ind) { return arr[ind]; }
    T &front() { return arr[0]; }
    T &back() { return arr[curr_end_pos - 1]; }
    const T &at(int ind) const { return arr[ind]; }
    T &front() const { return arr[0]; }
    T &back() const { return arr[curr_end_pos - 1]; }

    int size() { return curr_end_pos; }
    bool empty() { return curr_end_pos; }
    int size() const { return curr_end_pos; }
    bool empty() const { return curr_end_pos; }

    void operator=(vector<T> &data);
    T &operator[](const int ind) { return arr[ind]; }

private:
    T *arr;

    int loc_size;
    int curr_end_pos;
};

template <typename T>
vector<T>::vector()
{
    arr = new T[1];
    loc_size = 1;
    curr_end_pos = 0;
}

template <typename T>
vector<T>::vector(int size)
{
    arr = new T[size];
    loc_size = size;
    curr_end_pos = size;
}

template <typename T>
vector<T>::vector(int size, T data)
{
    arr = new T[size];
    loc_size = size;
    curr_end_pos = size;

    for (int i = 0; i < size; ++i)
        arr[i] = data;
}

template <typename T>
vector<T>::vector(std::vector<T> const &data)
{
    arr = new T[1];
    loc_size = 1;
    curr_end_pos = 0;
    for (int i = 0; i < data.size(); ++i)
        push_back(data[i]);
}

template <typename T>
vector<T>::vector(vector<T> &data)
{
    arr = new T[1];
    loc_size = 1;
    curr_end_pos = 0;
    for (int i = 0; i < data.size(); ++i)
        push_back(data[i]);
}

template <typename T>
void vector<T>::push_back(T data)
{
    iterator *temp = new iterator;
    if (loc_size == curr_end_pos)
    {
        T *temp = new T[2 * loc_size];

        for (int i = 0; i < loc_size; ++i)
            temp[i] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
    }

    arr[curr_end_pos] = data;
    ++curr_end_pos;
}

template <typename T>
void vector<T>::push_back(vector<T> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        push_back(data[i]);
    }
}

template <typename T>
void vector<T>::push_front(T data)
{
    iterator *temp = new iterator;
    if (loc_size == curr_end_pos)
    {
        T *temp_ = new T[2 * loc_size];

        for (int i = 1; i <= loc_size; ++i)
            temp_[i] = arr[i - 1];

        delete arr;
        loc_size *= 2;
        arr = temp_;
    }
    else
    {
        T *temp_ = new T[loc_size];

        for (int i = 1; i <= loc_size; ++i)
            temp_[i] = arr[i - 1];

        delete arr;
        loc_size *= 2;
        arr = temp_;
    }

    arr[0] = data;
    ++curr_end_pos;
}

template <typename T>
void vector<T>::push_front(vector<T> data)
{
    for (int i = data.size() - 1; i >= 0; --i)
    {
        push_front(data[i]);
    }
}

template <typename T>
void vector<T>::insert(T data, int pos)
{
    if (pos == curr_end_pos)
        push_back(data);
    else if (!pos)
        push_front(data);
    else if (loc_size == curr_end_pos)
    {
        T *temp = new T[2 * loc_size];

        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        temp[pos] = data;

        for (int i = pos; i < curr_end_pos + 1; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
        ++curr_end_pos;
    }
    else
    {
        T *temp = new T[curr_end_pos + 1];
        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        temp[pos] = data;

        for (int i = pos; i < curr_end_pos + 1; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
        ++curr_end_pos;
    }
}

template <typename T>
void vector<T>::insert(T data, int pos, int count)
{
    if (pos == curr_end_pos)
        for (int i = 0; i < count; ++i)
            push_back(data);
    else if (!pos)
        for (int i = 0; i < count; ++i)
            push_front(data);
    else if (loc_size <= curr_end_pos + count)
    {
        T *temp = new T[2 * loc_size + count];

        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        for (int i = pos; i < curr_end_pos + count; ++i)
            temp[i + count] = arr[i];

        delete arr;
        loc_size = 2 * loc_size + count;
        arr = temp;
        curr_end_pos += count;
    }
    else
    {
        T *temp = new T[curr_end_pos + count];
        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        for (int i = pos; i < curr_end_pos + count; ++i)
            temp[i + count] = arr[i];

        delete arr;
        loc_size = curr_end_pos + count;
        arr = temp;
        curr_end_pos += count;
    }
}

template <typename T>
void vector<T>::insert(vector<T> &data, int pos)
{
    if (pos == curr_end_pos)
        for (int i = 0; i < data.size(); ++i)
            push_back(data[i]);
    else if (!pos)
        for (int i = data.size() - 1; i >= 0; --i)
            push_front(data[i]);
    else if (loc_size <= curr_end_pos + data.size())
    {
        T *temp = new T[2 * loc_size + data.size()];

        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        for (int i = pos; i < curr_end_pos + data.size(); ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        loc_size = 2 * loc_size + data.size();
        arr = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = new T[curr_end_pos + data.size()];
        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        for (int i = pos; i < curr_end_pos + data.size(); ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        loc_size = curr_end_pos + data.size();
        arr = temp;
        curr_end_pos += data.size();
    }
}

template <typename T>
void vector<T>::insert(T data, iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        push_back(data);
    else if (!i_pos)
        push_front(data);
    else if (curr_end_pos == loc_size)
    {
        T *temp = new T[loc_size * 2];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
}

template <typename T>
void vector<T>::insert(T data, const_iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        push_back(data);
    else if (!i_pos)
        push_front(data);
    else if (curr_end_pos == loc_size)
    {
        T *temp = new T[loc_size * 2];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
}

template <typename T>
void vector<T>::insert(T data, iterator pos, int count)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        for (int i = 0; i < count; ++i)
            push_back(data);
    else if (!i_pos)
        for (int i = 0; i < count; ++i)
            push_front(data);
    else if (curr_end_pos + count >= loc_size)
    {
        T *temp = new T[loc_size * 2 + count];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = arr[i];

        delete arr;
        arr = temp;
        loc_size = loc_size * 2 + count;
        curr_end_pos += count;
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += count;
    }
}

template <typename T>
void vector<T>::insert(T data, const_iterator pos, int count)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        for (int i = 0; i < count; ++i)
            push_back(data);
    else if (!i_pos)
        for (int i = 0; i < count; ++i)
            push_front(data);
    else if (curr_end_pos + count >= loc_size)
    {
        T *temp = new T[loc_size * 2 + count];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        curr_end_pos += count;
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        curr_end_pos += count;
    }
}

template <typename T>
void vector<T>::insert(vector<T> &data, iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        for (int i = 0; i < data.size(); ++i)
            push_back(data[i]);
    else if (!i_pos)
        for (int i = data.size() - 1; i >= 0; --i)
            push_front(data[i]);
    else if (curr_end_pos + data.size() >= loc_size)
    {
        while (curr_end_pos + data.size() >= loc_size)
            loc_size *= 2;

        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
}

template <typename T>
void vector<T>::insert(vector<T> &data, const_iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (i_pos == curr_end_pos)
        for (int i = 0; i < data.size(); ++i)
            push_back(data[i]);
    else if (!i_pos)
        for (int i = 0; i < data.size(); ++i)
            push_front(data[i]);
    else if (curr_end_pos + data.size() >= loc_size)
    {
        while (curr_end_pos + data.size() >= loc_size)
            loc_size *= 2;

        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
}

template <typename T>
void vector<T>::insert(iterator pos, iterator secfpos, iterator seclpos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    temp_it = secfpos;

    for (; temp_it != seclpos; ++temp_it, ++sec_size)
    {
    }

    temp_it = secfpos;

    if (i_pos == curr_end_pos)
    {
        for (int i = 0; i < sec_size; ++i)
        {
            push_back(*temp_it);
            ++temp_it;
        }
    }
    else if (!i_pos)
    {
        temp_it = seclpos - 1;
        for (int i = 0; i < sec_size; ++i)
        {
            push_front(*temp_it);
            --temp_it;
        }
    }
    else if (curr_end_pos + sec_size >= loc_size)
    {
        T *temp = new T[loc_size * 2];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = i_pos; i < i_pos + sec_size; ++i)
        {
            temp[i] = *temp_it;
            ++temp_it;
        }

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + sec_size] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        curr_end_pos += sec_size;
    }
    else
    {
        for (int i = 0; i < sec_size; ++i)
        {
            arr[curr_end_pos] = *temp_it;
            ++temp_it;
            ++curr_end_pos;
        }
    }
}

template <typename T>
void vector<T>::insert(const_iterator pos, iterator secfpos, iterator seclpos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    temp_it = secfpos;

    for (; temp_it != seclpos; ++temp_it, ++sec_size)
    {
    }

    temp_it = secfpos;

    if (i_pos == curr_end_pos)
    {
        for (int i = 0; i < sec_size; ++i)
        {
            push_back(*temp_it);
            ++temp_it;
        }
    }
    else if (!i_pos)
    {
        temp_it = seclpos - 1;
        for (int i = 0; i < sec_size; ++i)
        {
            push_front(*temp_it);
            --temp_it;
        }
    }
    else if (curr_end_pos + sec_size >= loc_size)
    {
        T *temp = new T[loc_size * 2];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = i_pos; i < i_pos + sec_size; ++i)
        {
            temp[i] = *temp_it;
            ++temp_it;
        }

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + sec_size] = arr[i];

        delete arr;
        arr = temp;
        loc_size *= 2;
        curr_end_pos += sec_size;
    }
    else
    {
        for (int i = 0; i < sec_size; ++i)
        {
            arr[curr_end_pos] = *temp_it;
            ++temp_it;
            ++curr_end_pos;
        }
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace(iterator pos, T data)
{
    if (pos == begin())
    {
        return emplace_front(data);
    }
    else if (pos == end())
    {
        return emplace_back(data);
    }
    else
    {
        iterator temp = begin();
        int i = 0;
        for (; temp != pos; ++i, ++temp)
        {
        }

        insert(data, i);

        return arr + i;
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace(const_iterator pos, T data)
{
    if (pos == begin())
    {
        return emplace_front(data);
    }
    else if (pos == end())
    {
        return emplace_back(data);
    }
    else
    {
        iterator temp = begin();
        int i = 0;
        for (; temp != pos; ++i, ++temp)
        {
        }

        insert(data, i);

        return arr + i;
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace_back(T data)
{
    push_back(data);
    return arr + size();
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace_front(T data)
{
    push_front(data);
    return arr;
}

template <typename T>
void vector<T>::assign(int count, T data)
{
    delete arr;
    arr = new T[count];

    for (int i = 0; i < count; ++i)
        arr[i] = data;

    loc_size = count;
    curr_end_pos = count;
}

template <typename T>
void vector<T>::assign(iterator fpos, iterator lpos)
{
    delete arr;
    arr = new T[1];
    loc_size = 1;
    curr_end_pos = 0;

    for (; fpos != lpos; ++fpos)
        push_back(*fpos);
}

template <typename T>
void vector<T>::resize(int new_size)
{
    if (new_size != curr_end_pos)
    {
        if (new_size > loc_size)
        {
            T *temp = new T[new_size];

            for (int i = 0; i < curr_end_pos; ++i)
                temp[i] = arr[i];

            delete arr;
            arr = temp;
        }
        else if (new_size < curr_end_pos)
        {
            T *temp = new T[new_size];

            for (int i = 0; i < new_size; ++i)
                temp[i] = arr[i];

            delete arr;
            arr = temp;
        }
        loc_size = new_size;
        curr_end_pos = new_size;
    }
}

template <typename T>
void vector<T>::sort(std::string str)
{
    T temp;
    if (str == "GRT")
    {
        for (int i = 0; i < curr_end_pos - 1; ++i)
        {
            for (int j = 0; j < curr_end_pos - i - 1; ++j)
            {
                if (arr[0 + j] > arr[1 + j])
                {
                    temp = arr[0 + j];
                    arr[0 + j] = arr[1 + j];
                    arr[1 + j] = temp;
                }
            }
        }
    }
    else if (str == "SML")
    {
        for (int i = 0; i < curr_end_pos - 1; ++i)
        {
            for (int j = 0; j < curr_end_pos - i - 1; ++j)
            {
                if (arr[curr_end_pos - j] < arr[curr_end_pos - 1 - j])
                {
                    temp = arr[curr_end_pos - j];
                    arr[curr_end_pos - j] = arr[curr_end_pos - j - 1];
                    arr[curr_end_pos - j - 1] = temp;
                }
            }
        }
    }
}

template <typename T>
void vector<T>::pop_back()
{
    resize(curr_end_pos);
}

template <typename T>
void vector<T>::pop_front()
{
    T *temp = new T[curr_end_pos];

    for (int i = 0; i < curr_end_pos; ++i)
        temp[i] = arr[i + 1];

    delete arr;
    curr_end_pos -= 1;
    loc_size = curr_end_pos;
    arr = temp;
}

template <typename T>
void vector<T>::erase(iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0;

    while (temp_it != pos)
        ++i_pos;

    removeAt(i_pos);
}

template <typename T>
void vector<T>::erase(iterator fpos, iterator lpos)
{
    iterator temp_it = begin();
    int pos = 0, t_size = 0;

    while (temp_it != fpos)
        ++pos;

    while (temp_it != lpos)
    {
        ++t_size;
        ++temp_it;
    }

    for (int i = 0; i < t_size; ++i)
        removeAt(pos);
}

template <typename T>
void vector<T>::removeAt(int pos)
{
    T *temp = new T[loc_size];

    for (int i = 0; i < pos; ++i)
        temp[i] = arr[i];

    for (int i = pos; i < curr_end_pos; ++i)
        temp[i] = arr[i + 1];

    delete arr;
    arr = temp;
    --curr_end_pos;
}

template <typename T>
void vector<T>::clear()
{
    while (curr_end_pos)
        pop_back();
}

template <typename T>
void vector<T>::operator=(vector<T> &data)
{
    delete arr;
    arr = new T[data.size];

    for (int i = 0; i < data.size(); ++i)
        arr[i] = data[i];

    curr_end_pos = data.size();
    loc_size = data.size();
}
