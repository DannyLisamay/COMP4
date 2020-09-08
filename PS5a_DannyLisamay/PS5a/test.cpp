// Copyright 2015 fredm@cs.uml.edu for 91.204 Computing IV
// Wed Mar 25 06:32:17 2015
// Dr. Y. Rykalova:
// Edited by: Danny Lisamay and Dheera Vuppala
// Please be aware that it is an "start-up" code
// You should use the proper naming (RingBuffer, etc.) according to
// the assignment  requirements

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/included/unit_test.hpp>
// #include <boost/test/unit_test.hpp>
#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "RingBuffer.hpp"
BOOST_AUTO_TEST_CASE(RBcontructor) {
// good constructor - no exception
BOOST_REQUIRE_NO_THROW(RingBuffer(100));
// bad constructor - should fail
BOOST_CHECK_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
// checks that enqueue, isFUll,isEmpty and size works properly
RingBuffer rb(3);
BOOST_REQUIRE(rb.isFull() == false);
BOOST_REQUIRE(rb.isEmpty() == true);
rb.enqueue(2);
rb.enqueue(1);
BOOST_REQUIRE_NO_THROW(rb.enqueue(0));
// this should work without an exception, since it's not full.
BOOST_REQUIRE(rb.isFull() == true);
BOOST_REQUIRE(rb.isEmpty() == false);
BOOST_REQUIRE(rb.size() == 3);
BOOST_REQUIRE_THROW(rb.enqueue(4), std::runtime_error);
// can't enqueue when RB is full, so should throw
BOOST_REQUIRE(rb.dequeue() == 2);
BOOST_REQUIRE(rb.dequeue() == 1);
BOOST_REQUIRE(rb.dequeue() == 0);
BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
}
