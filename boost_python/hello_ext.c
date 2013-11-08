//  Copyright Joel de Guzman 2002-2004. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//  Hello World Example from the tutorial
//  [Joel de Guzman 10/9/2002]

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <iostream>

char const* greet()
{
   return "hello, world";
}

int increment(int a) {
    return a+1;
}

int sum(int a, int b) {
    return a+b;
}

int counter() {
    static int c = 0;
    c++;
    return c;
}

class School {
 public:
 School(int students, int teachers) :
    nStudents(students),
    nTeachers(teachers) {
	std::cout << "In School ctor()" << std::endl;
    }
 School(int students):
    nStudents(students),
    nTeachers(0) {}

    int getStudents() const { return nStudents; }
    int setStudents(int a) { nStudents = a; }
    void print() { std::cout << "We have " << nStudents << " and " << nTeachers << std::endl; }

 private:
    int nStudents;
    int nTeachers;
};

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
    def("increment", increment);
    def("sum", sum);
    def("counter", counter);
    class_<School>("School", init<int>())
	.def(init<int, int>())
	.add_property("rostudents", &School::getStudents)
	.add_property("students", &School::getStudents, &School::setStudents)
	.def("toString", &School::print);
}
