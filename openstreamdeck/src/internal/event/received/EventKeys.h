//
// Created by Cyril Vlaminck on 26/12/2021.
//

#ifndef STREAMDECK_COMMAND_EVENTKEYS_H
#define STREAMDECK_COMMAND_EVENTKEYS_H

constexpr char kEventActionKey[] = "action";
constexpr char kEventDeviceKey[] = "device";
constexpr char kEventContextKey[] = "context";

constexpr char kEventPayloadKey[] = "payload";
constexpr char kEventPayloadSettingKey[] = "settings";
constexpr char kEventPayloadStateKey[] = "state";
constexpr char kEventPayloadTitleKey[] = "title";
constexpr char kEventPayloadUserDesiredStateKey[] = "userDesiredState";
constexpr char kEventPayloadIsInMultiActionKey[] = "isInMultiAction";
constexpr char kEventPayloadCoordinatesKey[] = "coordinates";
constexpr char kEventPayloadCoordinatesColumnKey[] = "column";
constexpr char kEventPayloadCoordinatesRowKey[] = "row";

constexpr char kEventDeviceInfoKey[] = "deviceInfo";
constexpr char kEventDeviceInfoTypeKey[] = "type";
constexpr char kEventDeviceInfoNameKey[] = "name";
constexpr char kEventDeviceInfoSizeKey[] = "size";
constexpr char kEventDeviceInfoSizeColumnsKey[] = "columns";
constexpr char kEventDeviceInfoSizeRowsKey[] = "rows";

constexpr char kEventPayloadTitleParameters[] = "titleParameters";
constexpr char kEventPayloadTitleParametersFontFamily[] = "fontFamily";
constexpr char kEventPayloadTitleParametersFontSize[] = "fontSize";
constexpr char kEventPayloadTitleParametersFontStyle[] = "fontStyle";
constexpr char kEventPayloadTitleParametersFontUnderline[] = "fontUnderline";
constexpr char kEventPayloadTitleParametersShowTitle[] = "showTitle";
constexpr char kEventPayloadTitleParametersTitleAlignment[] = "titleAlignment";
constexpr char kEventPayloadTitleParametersTitleColor[] = "titleColor";

constexpr char kEventPayloadApplication[] = "application";

#endif  // STREAMDECK_COMMAND_EVENTKEYS_H
