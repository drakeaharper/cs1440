//
// Created by drake on 3/28/2017.
//

#ifndef GENERICS_DICTIONARY_H
#define GENERICS_DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "KeyValue.h"

template <typename K, typename V>
class Dictionary
{
public:
    Dictionary();
     Dictionary(unsigned int size);
    void addKeyValue(K key, V value);
    void resize();
    KeyValue<K,V> getByKey(const K& key);
    KeyValue<K,V> getByIndex(unsigned int position);
    void removeByKey(const K& key);
    void removeByIndex(unsigned int position);
    unsigned int getTotalEntries() { return m_totalEntries; }

private:
    KeyValue<K,V>** m_entries;
    unsigned int m_totalEntries;
    unsigned int m_allocated;
};

template <typename K, typename V>
Dictionary<K,V>::Dictionary()
{
    m_allocated = 10;
    m_totalEntries = 0;

    m_entries = new KeyValue<K,V>*[m_allocated];
}

template <typename K, typename V>
Dictionary<K,V>::Dictionary(unsigned int size)
{
    m_allocated = size;
    m_totalEntries = 0;

    m_entries = new KeyValue<K,V>*[m_allocated];
}

template <typename K, typename V>
void Dictionary<K,V>::addKeyValue(K key, V value)
{
    bool isFound = false;
    try
    {
        getByKey(key);
        isFound = true;
    }
    catch (std::domain_error)
    {

    }

    if (!isFound)
    {
        KeyValue<K, V> *newKeyValue = new KeyValue<K, V>(key, value);

        if (m_totalEntries == m_allocated)
        {
            resize();
        }

        m_entries[m_totalEntries++] = newKeyValue;
    }
    else
    {
        throw std::domain_error("Duplicate key.");
    }
}

template <typename K, typename V>
void Dictionary<K,V>::resize()
{
    KeyValue<K,V>* carl[m_allocated];

    for (unsigned int index = 0; index < m_allocated; index++)
    {
        carl[index] = m_entries[index];
    }

    unsigned int xtemp = m_allocated;
    m_allocated *= 2;

    m_entries = new KeyValue<K,V>*[m_allocated];

    for (unsigned int index = 0; index < xtemp; index++)
    {
        m_entries[index] = carl[index];
    }

    //delete [] carl;
}

template <typename K, typename V>
KeyValue<K,V> Dictionary<K,V>::getByKey(const K& key)
{
    bool found = false;
    KeyValue<K, V> result;

    for (unsigned int index = 0; index < m_totalEntries && !found; index++)
    {
        if (m_entries[index]->getKey() == key)
        {
            result = *m_entries[index];
            found = true;
        }
    }

    if (!found)
    {
        throw std::domain_error("Key not found.");
    }

    return result;
}

template <typename K, typename V>
KeyValue<K,V> Dictionary<K,V>::getByIndex(unsigned int position)
{
    KeyValue<K,V> searched = *m_entries[position];
    return searched;
}

template <typename K, typename V>
void Dictionary<K,V>::removeByKey(const K& key)
{
    bool isRemoved = false;
    unsigned foundAt = 0;
    for (unsigned int index = 0; index < m_totalEntries && !isRemoved; index++)
    {
        if (m_entries[index]->getKey() == key && !isRemoved)
        {
            delete m_entries[index];
            isRemoved = true;
            foundAt = index;
        }
    }

    for (unsigned int index = foundAt; index < m_totalEntries - 1 && isRemoved; index++)
    {
        if (isRemoved)
        {
            m_entries[index] = m_entries[index + 1];
        }
    }

    if (!isRemoved)
    {
        throw std::domain_error("Key not found, so it was not removed.");
    }

    m_totalEntries--;
}

template <typename K, typename V>
void Dictionary<K,V>::removeByIndex(unsigned int position)
{
    delete m_entries[position];

    for (unsigned int index = position; index < m_totalEntries; index++)
    {
        m_entries[index] = m_entries[index + 1];
    }

    m_totalEntries--;
}

#endif //GENERICS_DICTIONARY_H
