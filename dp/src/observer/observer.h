/*
 * observer.h
 *
 *  Created on: 07.09.2018
 *      Author: osab4393
 */

#ifndef OBSERVER_OBSERVER_H_
#define OBSERVER_OBSERVER_H_

/*
 * The observer pattern is a software design pattern in which an object, called the subject, maintains a list of its dependents,
 * called observers, and notifies them automatically of any state changes, usually by calling one of their methods.
 *
 * It is mainly used to implement distributed event handling systems, in "event driven" software. Most modern languages such as C# have
 * built in "event" constructs which implement the observer pattern components, for easy programming and short code.
 *
 * The observer pattern is also a key part in the familiar model–view–controller (MVC) architectural pattern.[1] The observer pattern
 * is implemented in numerous programming libraries and systems, including almost all GUI toolkits.
 *
 * The Observer pattern addresses the following problems:[3]
 *
 * 1 - A one-to-many dependency between objects should be defined without making the objects tightly coupled.
 * 2 - It should be ensured that when one object changes state an open-ended number of dependent objects are updated automatically.
 * 3 - It should be possible that one object can notify an open-ended number of other objects.
 *
 * Defining a one-to-many dependency between objects by defining one object (subject) that updates the state of dependent objects
 * directly is inflexible because it commits (tightly couples) the subject to particular dependent objects. Tightly coupled objects
 * are hard to implement, change, test, and reuse because they refer to and know about (how to update) many different objects with
 * different interfaces.
 *
 * Solution:
 * 1 - Define Subject (maintains a list of observers, notifies them of state changes by calling their update() ) and Observer objects.
 * 2 - so that when a subject changes state, all registered observers are notified and updated automatically.
 *
 */

#include <vector>
#include <iostream>

using namespace std;

class IObserver {
public:
	virtual ~IObserver() {
	}
	virtual void update(std::string msg) = 0;
protected:
	string observer_name;

};

class Observer1: public IObserver {
public:
	Observer1(string name) {
		observer_name = name;
	}

	virtual ~Observer1() {
	}
	virtual void update(std::string msg) {
		cout << observer_name << ": got: " << msg << endl;
	}
};

class Observer2: public IObserver {
public:
	Observer2(string name) {

		observer_name = name;
	}

	virtual ~Observer2() {

	}
	virtual void update(std::string msg) {
		cout << observer_name << ": got: " << msg << endl;
	}
};

class ISubject {
public:
	vector<IObserver*> observers;
	virtual ~ISubject() {
	}

	void _register(IObserver* observer) {
		observers.push_back(observer);
	}

	void deregister(IObserver* observer) {
		for (auto itr = observers.begin(); itr != observers.end(); ++itr) {
			if (*itr == observer) {
				observers.erase(itr);
				break;
			}
		}
	}

	void notify_observer(string msg) {
		for (auto observer : observers) {
			observer->update(msg);
		}
	}
};

class Subject1: public ISubject {
public:
	virtual ~Subject1() {
	}

};

class ObserverDP {
public:
	static void run() {
		IObserver* o1 = new Observer1("observer1");
		IObserver* o2 = new Observer1("observer2");
		ISubject* subject = new Subject1();
		subject->_register(o1);
		subject->_register(o2);
		subject->notify_observer("my notification.");
	}
};

#endif /* OBSERVER_OBSERVER_H_ */
