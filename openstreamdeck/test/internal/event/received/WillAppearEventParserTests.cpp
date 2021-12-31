//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include <boost/test/unit_test.hpp>

#include "event/WillAppearEvent.h"

#define private public
#include "internal/event/received/WillAppearEventParser.h"
#undef private

using namespace openstreamdeck;
using namespace openstreamdeck::internal::event;

BOOST_AUTO_TEST_SUITE(WillAppearEventParserTests)

BOOST_AUTO_TEST_CASE(parseEvent) {
    const auto payload =
        "{\"action\":\"fr.cvlaminck.example\",\"context\":\"C39764456C45C700004EF120E2FFDC4F\",\"device\":\"389A1599AE83DFFF401B5430DEC7DA79\",\"event\":"
        "\"willAppear\",\"payload\":{\"coordinates\":{\"column\":4,\"row\":2},\"isInMultiAction\":false,\"settings\":{}}}";
    auto json = boost::json::parse(payload).as_object();

    const WillAppearEventParser parser;
    std::unique_ptr<WillAppearEvent> event(static_cast<WillAppearEvent*>(parser.parseEvent(json).release()));

    BOOST_TEST(event->event == kWillAppearEvent);
    BOOST_TEST(event->action == "fr.cvlaminck.example");
    BOOST_TEST(event->context == "C39764456C45C700004EF120E2FFDC4F");
    BOOST_TEST(event->device == "389A1599AE83DFFF401B5430DEC7DA79");
    BOOST_TEST(event->coordinatesColumn == 4);
    BOOST_TEST(event->coordinatesRow == 2);
    BOOST_TEST(event->isInMultiAction == false);
}

BOOST_AUTO_TEST_SUITE_END()
