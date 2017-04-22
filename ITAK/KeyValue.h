//
// Created by drake on 3/28/2017.
//

#ifndef GENERICS_KEYVALUE_H
#define GENERICS_KEYVALUE_H

template <typename K, typename V>
class KeyValue
{
public:
    KeyValue() { m_multiplicity = 0; }
    KeyValue(K newKey, V newValue) { m_key = newKey; m_value = newValue; m_multiplicity = 0; }
    //KeyValue(const KeyValue<K, V>& rhs);
    K getKey() { return m_key; }
    V getValue() { return m_value; }
    void setKey(K newKey) { m_key = newKey; }
    void setValue(V newValue) { m_value = newValue; }
    void incrementMultiplicity() { ++m_multiplicity; }

private:
    K m_key;
    V m_value;
    unsigned int m_multiplicity;
};

//template <typename K, typename V>
//KeyValue<K, V>::KeyValue(const KeyValue<K, V>& rhs)
//{
//    m_key = rhs.m_key;
//    m_value = rhs.m_value;
//}


#endif //GENERICS_KEYVALUE_H
