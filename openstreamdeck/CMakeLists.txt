set(TARGET openstreamdeck)
set(TEST_TARGET ${TARGET}_test)
set(TARGETS ${TARGET} ${TEST_TARGET})

#
# Create library
#
set(
        SOURCE_FILES
        src/event/ApplicationDidLaunchEvent.cpp src/event/ApplicationDidLaunchEvent.h
        src/event/ApplicationDidTerminateEvent.cpp src/event/ApplicationDidTerminateEvent.h
        src/event/DeviceDidConnectEvent.cpp src/event/DeviceDidConnectEvent.h
        src/event/DeviceDidDisconnectEvent.cpp src/event/DeviceDidDisconnectEvent.h
        src/event/DidReceiveGlobalSettingsEvent.cpp src/event/DidReceiveGlobalSettingsEvent.h
        src/event/DidReceiveSettingsEvent.cpp src/event/DidReceiveSettingsEvent.h
        src/event/Event.cpp src/event/Event.h
        src/event/KeyDownEvent.cpp src/event/KeyDownEvent.h
        src/event/KeyUpEvent.cpp src/event/KeyUpEvent.h
        src/event/PropertyInspectorDidAppearEvent.cpp src/event/PropertyInspectorDidAppearEvent.h
        src/event/PropertyInspectorDidDisappearEvent.cpp src/event/PropertyInspectorDidDisappearEvent.h
        src/event/SendToPluginEvent.cpp src/event/SendToPluginEvent.h
        src/event/SystemDidWakeUpEvent.cpp src/event/SystemDidWakeUpEvent.h
        src/event/TitleParametersDidChangeEvent.cpp src/event/TitleParametersDidChangeEvent.h
        src/event/WillAppearEvent.cpp src/event/WillAppearEvent.h
        src/event/WillDisappearEvent.cpp src/event/WillDisappearEvent.h
        src/internal/event/received/ApplicationDidLaunchEventParser.cpp src/internal/event/received/ApplicationDidLaunchEventParser.h
        src/internal/event/received/ApplicationDidTerminateEventParser.cpp src/internal/event/received/ApplicationDidTerminateEventParser.h
        src/internal/event/received/DeviceDidConnectEventParser.cpp src/internal/event/received/DeviceDidConnectEventParser.h
        src/internal/event/received/DeviceDidDisconnectEventParser.cpp src/internal/event/received/DeviceDidDisconnectEventParser.h
        src/internal/event/received/DidReceiveGlobalSettingsEventParser.cpp src/internal/event/received/DidReceiveGlobalSettingsEventParser.h
        src/internal/event/received/DidReceiveSettingsEventParser.cpp src/internal/event/received/DidReceiveSettingsEventParser.h
        src/internal/event/received/EventParser.cpp src/internal/event/received/EventParser.h
        src/internal/event/received/KeyDownEventParser.cpp src/internal/event/received/KeyDownEventParser.h
        src/internal/event/received/KeyUpEventParser.cpp src/internal/event/received/KeyUpEventParser.h
        src/internal/event/received/PropertyInspectorDidAppearEventParser.cpp src/internal/event/received/PropertyInspectorDidAppearEventParser.h
        src/internal/event/received/PropertyInspectorDidDisappearEventParser.cpp src/internal/event/received/PropertyInspectorDidDisappearEventParser.h
        src/internal/event/received/SendToPluginEventParser.cpp src/internal/event/received/SendToPluginEventParser.h
        src/internal/event/received/SystemDidWakeUpEventParser.cpp src/internal/event/received/SystemDidWakeUpEventParser.h
        src/internal/event/received/TitleParametersDidChangeEventParser.cpp src/internal/event/received/TitleParametersDidChangeEventParser.h
        src/internal/event/received/WillAppearEventParser.cpp src/internal/event/received/WillAppearEventParser.h
        src/internal/event/received/WillDisappearEventParser.cpp src/internal/event/received/WillDisappearEventParser.h
        src/internal/event/sent/GetGlobalSettingsSentEvent.cpp src/internal/event/sent/GetGlobalSettingsSentEvent.h
        src/internal/event/sent/GetSettingsSentEvent.cpp src/internal/event/sent/GetSettingsSentEvent.h
        src/internal/event/sent/LogMessageSentEvent.cpp src/internal/event/sent/LogMessageSentEvent.h
        src/internal/event/sent/OpenUrlSentEvent.cpp src/internal/event/sent/OpenUrlSentEvent.h
        src/internal/event/sent/RegistrationSentEvent.cpp src/internal/event/sent/RegistrationSentEvent.h
        src/internal/event/sent/SendToPropertyInspectorSentEvent.cpp src/internal/event/sent/SendToPropertyInspectorSentEvent.h
        src/internal/event/sent/SentEvent.cpp src/internal/event/sent/SentEvent.h
        src/internal/event/sent/SetGlobalSettingsSentEvent.cpp src/internal/event/sent/SetGlobalSettingsSentEvent.h
        src/internal/event/sent/SetImageSentEvent.cpp src/internal/event/sent/SetImageSentEvent.h
        src/internal/event/sent/SetSettingsSentEvent.cpp src/internal/event/sent/SetSettingsSentEvent.h
        src/internal/event/sent/SetStateSentEvent.cpp src/internal/event/sent/SetStateSentEvent.h
        src/internal/event/sent/SetTitleSentEvent.cpp src/internal/event/sent/SetTitleSentEvent.h
        src/internal/event/sent/ShowAlertSentEvent.cpp src/internal/event/sent/ShowAlertSentEvent.h
        src/internal/event/sent/ShowOkSentEvent.cpp src/internal/event/sent/ShowOkSentEvent.h
        src/internal/event/sent/SwitchToProfileSentEvent.cpp src/internal/event/sent/SwitchToProfileSentEvent.h
        src/internal/ActionManager.cpp src/internal/ActionManager.h
        src/internal/CommunicationManager.cpp src/internal/CommunicationManager.h
        src/internal/EventManager.cpp src/internal/EventManager.h
        src/internal/EventParsingManager.cpp src/internal/EventParsingManager.h
        src/internal/Logger.cpp src/internal/Logger.h
        src/internal/RegistrationParser.cpp src/internal/RegistrationParser.h
        src/internal/StreamDeckPluginImpl.cpp src/internal/StreamDeckPluginImpl.h
        src/internal/Registration.cpp src/internal/Registration.h
        src/StreamDeckPlugin.cpp src/StreamDeckPlugin.h
        src/Actions.h
        src/Events.h
        src/StreamDeckPluginStatus.cpp src/StreamDeckPluginStatus.h)

add_library(
        ${TARGET} STATIC ${SOURCE_FILES}
)
target_include_directories(${TARGET} PUBLIC src src/model)

# Boost
target_link_libraries(${TARGET} Boost::headers)

#
# Create executable to run unit tests
#
add_executable(
        ${TEST_TARGET}
        test/main.cpp
        test/internal/event/received/WillAppearEventParserTests.cpp
        test/internal/RegistrationParserTests.cpp
)

# libopenstreamdeck
target_link_libraries(${TEST_TARGET} ${TARGET})

# Boost
target_link_libraries(${TEST_TARGET} Boost::test)
target_link_libraries(${TEST_TARGET} Boost::unit_test_framework)

add_test(
        NAME ${TEST_TARGET}
        COMMAND ${TARGET}_test
)
