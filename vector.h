#pragma once
#include <vector>
#include <algorithm>

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
    ~vector();

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

    void clear();
    void pop_back();
    void pop_front();
    void erase(iterator pos);
    void erase(iterator fpos, iterator lpos);
    void removeAt(int pos);

    iterator begin() { return array_m; }
    iterator end() { return array_m + size(); }
    iterator begin() const { return array_m; }
    iterator end() const { return array_m + size(); }
    const_iterator cbegin() const { return array_m; }
    const_iterator cend() const { return array_m + size(); }
    reverse_iterator rbegin() { return array_m + size(); }
    reverse_iterator rend() { return array_m; }
    const_reverse_iterator crbegin() { return cend(); }
    const_reverse_iterator crend() { return cbegin(); }

    T &at(int ind) { return array_m[ind]; }
    T &front() { return array_m[0]; }
    T &back() { return array_m[curr_end_pos - 1]; }

    const T &at(int ind) const { return array_m[ind]; }
    T &front() const { return array_m[0]; }
    T &back() const { return array_m[curr_end_pos - 1]; }

    int size() { return curr_end_pos; }
    bool empty() { return curr_end_pos; }
    int size() const { return curr_end_pos; }
    bool empty() const { return curr_end_pos; }

    void operator=(vector<T> &data);
    T &operator[](const int ind) { return array_m[ind]; }

private:
    T *array_m;
    int loc_size;
    int curr_end_pos;
    T *reserve_(int Size);
};

template <typename T>
vector<T>::~vector()
{
    clear();
}

template <typename T>
vector<T>::vector()
{
    array_m = reserve_(1);
    loc_size = 1;
    curr_end_pos = 0;
}

template <typename T>
vector<T>::vector(int size)
{
    array_m = reserve_(size);
    loc_size = size;
    curr_end_pos = size;
}

template <typename T>
vector<T>::vector(int size, T data)
{
    array_m = reserve_(size);
    loc_size = size;
    curr_end_pos = size;

    for (int i = 0; i < size; ++i)
        array_m[i] = data;
}

template <typename T>
vector<T>::vector(std::vector<T> const &data)
{
    array_m = reserve_(1);
    loc_size = 1;
    curr_end_pos = 0;
    for (int i = 0; i < data.size(); ++i)
        push_back(data[i]);
}

template <typename T>
vector<T>::vector(vector<T> &data)
{
    array_m = reserve_(1);
    loc_size = 1;
    curr_end_pos = 0;
    for (int i = 0; i < data.size(); ++i)
        push_back(data[i]);
}

template <typename T>
void vector<T>::push_back(T data)
{
    if (loc_size == curr_end_pos)
    {
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < curr_end_pos; ++i)
            temp[i] = array_m[i];

        free(array_m);
        loc_size *= 2;
        array_m = temp;
    }

    array_m[curr_end_pos] = data;
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
    if (loc_size == curr_end_pos)
    {
        T *temp_ = reserve_(loc_size * 2);

        for (int i = 1; i <= curr_end_pos; ++i)
            temp_[i] = array_m[i - 1];

        free(array_m);
        loc_size *= 2;
        array_m = temp_;
    }
    else
    {
        T *temp_ = reserve_(loc_size);

        for (int i = 1; i <= curr_end_pos; ++i)
            temp_[i] = array_m[i - 1];

        free(array_m);
        array_m = temp_;
    }

    array_m[0] = data;
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
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        temp[pos] = data;

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        loc_size *= 2;
        array_m = temp;
        ++curr_end_pos;
    }
    else
    {
        T *temp = reserve_(curr_end_pos + 1);
        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        temp[pos] = data;

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        loc_size *= 2;
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2 + count);

        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + count] = array_m[i];

        free(array_m);
        loc_size = 2 * loc_size + count;
        array_m = temp;
        curr_end_pos += count;
    }
    else
    {
        T *temp = reserve_(curr_end_pos + count);
        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + count] = array_m[i];

        free(array_m);
        loc_size = curr_end_pos + count;
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2 + data.size());

        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        loc_size = 2 * loc_size + data.size();
        array_m = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = reserve_(curr_end_pos + data.size());
        for (int i = 0; i < pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        for (int i = pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        loc_size = curr_end_pos + data.size();
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size *= 2;
        ++curr_end_pos;
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        temp[i_pos] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2 + count);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size = loc_size * 2 + count;
        curr_end_pos += count;
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = array_m[i];

        free(array_m);
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2 + count);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + count] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size *= 2;
        curr_end_pos += count;
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < count; ++i)
            temp[i_pos + i] = data;

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + 1] = array_m[i];

        free(array_m);
        array_m = temp;
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

        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        array_m = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        array_m = temp;
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

        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        array_m = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T *temp = reserve_(loc_size);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size()] = array_m[i];

        free(array_m);
        array_m = temp;
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
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = i_pos; i < i_pos + sec_size; ++i)
        {
            temp[i] = *temp_it;
            ++temp_it;
        }

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + sec_size] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size *= 2;
        curr_end_pos += sec_size;
    }
    else
    {
        for (int i = 0; i < sec_size; ++i)
        {
            array_m[curr_end_pos] = *temp_it;
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
        T *temp = reserve_(loc_size * 2);

        for (int i = 0; i < i_pos; ++i)
            temp[i] = array_m[i];

        for (int i = i_pos; i < i_pos + sec_size; ++i)
        {
            temp[i] = *temp_it;
            ++temp_it;
        }

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + sec_size] = array_m[i];

        free(array_m);
        array_m = temp;
        loc_size *= 2;
        curr_end_pos += sec_size;
    }
    else
    {
        for (int i = 0; i < sec_size; ++i)
        {
            array_m[curr_end_pos] = *temp_it;
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

        return array_m + i;
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

        return array_m + i;
    }
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace_back(T data)
{
    push_back(data);
    return array_m + size();
}

template <typename T>
typename vector<T>::iterator vector<T>::emplace_front(T data)
{
    push_front(data);
    return array_m;
}

template <typename T>
void vector<T>::assign(int count, T data)
{
    free(array_m);
    T *temp = (T *)malloc(sizeof(T) * count);
    array_m = temp;

    for (; temp != array_m + count; ++temp)
    {
        new (temp) T();
        *temp = data;
    }

    loc_size = count;
    curr_end_pos = count;
}

template <typename T>
void vector<T>::assign(iterator fpos, iterator lpos)
{
    free(array_m);
    T *array_m = (T *)malloc(sizeof(T));
    new (array_m) T();
    loc_size = 1;
    curr_end_pos = 0;

    for (; fpos != lpos; ++fpos)
        push_back(*fpos);
}

template <typename T>
void vector<T>::resize(int new_size)
{
    if (new_size > loc_size)
    {
        T *temp = reserve_(new_size);

        for (int i = 0; i < curr_end_pos; ++i)
            temp[i] = array_m[i];

        for (int i = curr_end_pos; i < new_size; ++i)
            temp[i] = {};

        free(array_m);
        array_m = temp;
        loc_size = new_size;
    }
    else if (new_size > curr_end_pos && new_size < loc_size)
    {
        for (int i = curr_end_pos; i < new_size; ++i)
            array_m[i] = {};

        curr_end_pos = new_size;
    }
    curr_end_pos = new_size;
}

template <typename T>
void vector<T>::pop_back()
{
    resize(curr_end_pos - 1);
}

template <typename T>
void vector<T>::pop_front()
{
    --curr_end_pos;
    T *temp = reserve_(curr_end_pos);

    for (int i = 0; i < curr_end_pos; ++i)
        temp[i] = array_m[i + 1];

    free(array_m);
    loc_size = curr_end_pos;
    array_m = temp;
}

template <typename T>
void vector<T>::erase(iterator pos)
{
    if (pos == begin())
        pop_front();
    else if (pos == end())
        pop_back();
    else
    {
        iterator temp_it = begin();
        int i_pos = 0;

        while (temp_it != pos)
        {
            ++i_pos;
            ++temp_it;
        }
        removeAt(i_pos);
    }
}

template <typename T>
void vector<T>::erase(iterator fpos, iterator lpos)
{
    if (fpos == begin() && lpos == end())
        clear();
    else
    {
        iterator temp_it = fpos;
        int t_size = 0;

        while (temp_it != lpos)
        {
            ++t_size;
            ++temp_it;
        }

        if (fpos == begin())
        {
            while (t_size >= 0)
            {
                pop_front();
                --t_size;
            }
        }
        else if (lpos == end())
        {
            while (t_size >= 0)
            {
                pop_back();
                --t_size;
            }
        }
        else
        {
            int pos = 0;
            temp_it = begin();
            while (temp_it != fpos)
            {
                ++pos;
                ++temp_it;
            }

            for (int i = 0; i < t_size; ++i)
                removeAt(pos);
        }
    }
}

template <typename T>
void vector<T>::removeAt(int pos)
{
    T *temp = reserve_(loc_size);

    for (int i = 0; i < pos; ++i)
        temp[i] = array_m[i];

    for (int i = pos; i < curr_end_pos - 1; ++i)
        temp[i] = array_m[i + 1];

    free(array_m);
    array_m = temp;
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
    free(array_m);

    array_m = reserve_(data.size());

    for (int i = 0; i < data.size(); ++i)
        array_m[i] = data[i];

    curr_end_pos = data.size();
    loc_size = data.size();
}

template <typename T>
T *vector<T>::reserve_(int Size)
{
    T *temp = (T *)malloc(sizeof(T) * Size);
    T *bffr = temp;

    for (; temp != bffr + Size; ++temp)
        new (temp) T();

    return bffr;
}
