//
// Created by Cyril Vlaminck on 24/12/2021.
//

#include <boost/test/unit_test.hpp>

#define private public
#include "internal/RegistrationParser.h"
#undef private

using openstreamdeck::internal::RegistrationParser;

BOOST_AUTO_TEST_SUITE(RegistrationParserTests)

BOOST_AUTO_TEST_CASE(parse) {
    const char* argv[] = {"openstreamdeck_test", "-port", "8080", "-pluginUUID", "11df1864-f611-46eb-8efd-4fb32deccbb9", "-registerEvent", "register"};

    RegistrationParser parser;
    auto registration = parser.parse(7, argv);

    BOOST_TEST(registration->port == 8080);
    BOOST_TEST(registration->pluginUUID == "11df1864-f611-46eb-8efd-4fb32deccbb9");
    BOOST_TEST(registration->registerEvent == "register");
}

BOOST_AUTO_TEST_SUITE_END()
