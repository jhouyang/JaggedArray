#ifndef JAGGEDARRAY_VALUE_H_
#define JAGGEDARRAY_VALUE_H_

#include <boost/shared_ptr.hpp>
#include <vector>

struct OutOfBoundaryException {}

class ValueBase
{
public:
    typedef boost::shared_ptr<ValueBase> ValueBasePtr;
    virtual ~ValueBase() { }
};

template <typename T>
class Value : public ValueBase
{
public:
    Value(const T& value)
        : m_value(value)
    {
    }
    
    T& get()
    {
        return m_value;
    }

    const T& get() const
    {
        return m_value;
    }

private:
    T m_value;
};

class JaggedArray
{
public:
    template <typename T>
    void add(const T& t)
    {
        m_vec.push_back(ValueBase::ValueBasePtr(new Value<T>(t)));
    }

    template <typename T>
    const T& get(int index) const
    {
        if (index >= m_vec.size())
        {
            throw OutOfBoundaryException();
        }
        ValueBase::ValueBasePtr ptr = m_vec[index];
        Value<T>* valuePtr = dynamic_cast< Value<T>* >(ptr.get());

        return valuePtr->get();
    }

    template <typename T>
    T& get(int index)
    {
        ValueBase::ValueBasePtr ptr = m_vec[index];
        Value<T>* valuePtr = dynamic_cast< Value<T>* >(ptr.get());

        return valuePtr->get();
    }

private:

    std::vector<ValueBase::ValueBasePtr> m_vec;
};
#endif

