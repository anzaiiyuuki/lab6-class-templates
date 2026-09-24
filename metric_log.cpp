/*
 * Course: COEN 2220 - Programming 2
 * Name: [Aida S. Mendoza Gonzélez]
 * Lab: Lab 6 - Class Templates
 * Description: Guided example - a generic workshop metric log
 * Due date: [24 de septiembre de 2026]
 */

#include <iostream>
using namespace std;

/*
 * MetricLog ADT
 *
 * Data:
 * [Complete in Part E: describe the values managed by this log.]
 *
 * Operations:
 * [Complete in Part E: describe add(value). lo que hace add value es dependiendo de la cantidad del arreglo (CAPACITY) y suma count o suma por uno y lo guarda en ell lugar del count asinado. despues o que hace el bool es que si lo hace o no]
 * [Complete in Part E: describe get(index) and its precondition. Dependiendo el index que poga, es el valor que va a buscar en el arreglo]
 * [Complete in Part E: describe contains(target). Nos enrega un valor verdadero o falso dependiendo si existe]
 * [Complete in Part E: describe size() and isEmpty().pone el valor d count en 0]
 */

template <typename T>
class MetricLog
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Add a constant for a fixed capacity of four values.
     static const int CAPACITY=4;
    // TODO (Part C): Add an array that stores values of the generic type.
    T values[CAPACITY];
    // TODO (Part C): Add an int that tracks how many values are stored.
    int count;

public:
    // TODO (Part C): Write a constructor that creates an empty log.
    MetricLog()
    {
    count=0;
    }

    // TODO (Part C): Write add. It receives one generic value by const reference.
    // Return false when the log has no remaining capacity.
    bool add(const T& value)
    {
            if (count == CAPACITY)
        {
            return false;     // Reject a value when the fixed array is full.
        }
        values[count] = value;
        count++;
        return true;
    }

    // TODO (Part C): Write get. It receives a valid index and returns its stored value.
    T get(int index) const
    {
        // Precondition: index is between 0 and count - 1.
        return values[index];
    }
    // TODO (Part C): Write size as a const member function.
  int size() const
    {
        return count;         // Report how many values are currently stored.
    }    

        // TODO (Part C): Write isEmpty as a const member function.
    bool isEmpty() const
        {
            return count == 0;    // A log is empty only when it stores no values.
        }
    bool contains(const T& target) const;   
};

// ===== Do not resolve these TODOs yet (Part D) =====

// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.
template <typename T>
bool MetricLog<T>::contains(const T& target) const
{
    for (int index = 0; index < count; index++)
    {
        if (values[index] == target)
        {
            return true;     // The target value was found.
        }
    }

    return false;            // No stored value matched the target.
}

int main()
{
    MetricLog<int> waitlistCounts;

    waitlistCounts.add(6);
    waitlistCounts.add(11);

    cout << "First waitlist count: "
         << waitlistCounts.get(0) << endl;
    cout << "Stored waitlist counts: "
         << waitlistCounts.size() << endl;

    // ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    MetricLog<double> sessionduration;
    // TODO (Part E): Add two dummy duration values to that log.
    sessionduration.add(42.5);
    sessionduration.add(160.2);
    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    sessionduration.contains(42.5);
    sessionduration.contains(43);
    // TODO (Part E): Print descriptive English labels for all results.
    cout<< "First session duration: " <<sessionduration.get(0) <<endl;
    cout<< "Duration exists: " << boolalpha<< sessionduration.contains(42.5) <<endl; // boolalpha para true or false, cool!
    cout<< "Other duration exists: "<<boolalpha<< sessionduration.contains(160.2)  <<endl; 

    return 0;
}