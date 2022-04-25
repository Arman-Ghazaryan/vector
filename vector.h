#pragma once

template <typename T>
class vector
{
public:
    typedef T *iterator;

    vector();
    vector(int size);
    vector(int size, T data);
    vector(vector<T> &data);

    void push_back(T data);
    void push_back(vector<T> data);
    void push_front(T data);
    void push_front(vector<T> data);

    void insert(T data, int pos);
    void insert(T data, int pos, int count);
    void insert(vector<T> data, int pos);
    void insert(T data, iterator pos);
    void insert(vector<T> data, iterator pos);
    void insert(iterator pos, iterator secfpos, iterator seclpos);

    void resize(int new_size);

    void pop_back();
    void pop_front();
    void erase(iterator pos);
    void erase(iterator fpos, iterator lpos);
    void removeAt(int pos);

    iterator begin() { return arr; }
    iterator end() { return arr + size(); }

    T &front() { return arr[0]; }
    T &back() { return arr[curr_end_pos - 1]; }

    int size() { return curr_end_pos; }

    void operator=(vector<T> &data);
    T &operator[](int ind);

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

    if (loc_size == curr_end_pos)
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
    }
    ++curr_end_pos;
}

template <typename T>
void vector<T>::insert(T data, int pos, int count)
{
    if (loc_size == curr_end_pos)
    {
        T *temp = new T[2 * loc_size + count];

        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        pos += count;

        for (int i = pos; i < curr_end_pos + count; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
    }
    else
    {
        T *temp = new T[curr_end_pos + 1];
        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < count; ++i)
            temp[pos + i] = data;

        pos += count;

        for (int i = pos; i < curr_end_pos + count; ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
    }
    curr_end_pos += count;
}

template <typename T>
void vector<T>::insert(vector<T> data, int pos)
{
    if (loc_size == curr_end_pos)
    {
        T *temp = new T[2 * loc_size + data.size()];

        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        pos += data.size();

        for (int i = pos; i < curr_end_pos + data.size(); ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
    }
    else
    {
        T *temp = new T[curr_end_pos + 1];
        for (int i = 0; i < pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[pos + i] = data[i];

        pos += data.size();

        for (int i = pos; i < curr_end_pos + data.size(); ++i)
            temp[i + 1] = arr[i];

        delete arr;
        loc_size *= 2;
        arr = temp;
    }
    curr_end_pos += data.size();
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

    if (curr_end_pos + sec_size >= loc_size)
    {
        T temp = new T[loc_size * 2];

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
void vector<T>::insert(T data, iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (curr_end_pos == loc_size)
    {
        T temp = new T[loc_size * 2];

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
        T temp = new T[loc_size];

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
void vector<T>::insert(vector<T> data, iterator pos)
{
    iterator temp_it = begin();
    int i_pos = 0, sec_size = 0;

    for (; temp_it != pos; ++temp_it, ++i_pos)
    {
    }

    if (curr_end_pos + data.size() >= loc_size)
    {
        while (curr_end_pos + data.size() >= loc_size)
            loc_size *= 2;

        T temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
    else
    {
        T temp = new T[loc_size];

        for (int i = 0; i < i_pos; ++i)
            temp[i] = arr[i];

        for (int i = 0; i < data.size(); ++i)
            temp[i_pos + i] = data[i];

        for (int i = i_pos; i < curr_end_pos; ++i)
            temp[i + data.size] = arr[i];

        delete arr;
        arr = temp;
        curr_end_pos += data.size();
    }
}

template <typename T>
void vector<T>::resize(int new_size)
{
    if (new_size != curr_end_pos)
    {
        if (new_size > loc_size)
        {
            T *temp = new T[new_size];

            for (int i = 0; i < loc_size; ++i)
                temp[i] = arr[i];

            delete arr;
            loc_size = new_size;
            arr = temp;
        }
        else if (new_size > curr_end_pos && new_size < loc_size)
        {
            curr_end_pos = new_size;
        }
        else
        {
            T *temp = new T[new_size];

            for (int i = 0; i < new_size; ++i)
                temp[i] = arr[i];

            delete arr;
            loc_size = new_size;
            curr_end_pos = new_size - 1;
            arr = temp;
        }
    }
}

template <typename T>
void vector<T>::pop_back()
{
    resize(curr_end_pos - 1);
}

template <typename T>
void vector<T>::pop_front()
{
    T *temp = new T[curr_end_pos - 1];

    for (int i = 0; i < curr_end_pos - 1; ++i)
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

    for (int i = pos; i < curr_end_pos - 1; ++i)
        temp[i] = arr[i + 1];

    delete arr;
    arr = temp;
    --curr_end_pos;
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

template <typename T>
T &vector<T>::operator[](int ind)
{
    return arr[ind];
}
