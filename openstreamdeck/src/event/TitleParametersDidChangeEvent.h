//
// Created by Cyril Vlaminck on 26/12/2021.
//

#ifndef STREAMDECK_COMMAND_TITLEPARAMETERSDIDCHANGEEVENT_H
#define STREAMDECK_COMMAND_TITLEPARAMETERSDIDCHANGEEVENT_H

#include <boost/json.hpp>

#include "Event.h"

namespace openstreamdeck {

constexpr char kTitleParametersDidChangeEvent[] = "titleParametersDidChange";

class TitleParametersDidChangeEvent : public Event {
   public:
    /**
     * This json object contains data that you can set and are stored persistently.
     */
    const boost::json::object settings;
    /**
     * The coordinates of the action triggered.
     */
    const uint8_t coordinatesColumn;
    /**
     * The coordinates of the action triggered.
     */
    const uint8_t coordinatesRow;
    /**
     * This value indicates for which state of the action the title or title parameters have been changed.
     */
    const uint8_t state;
    /**
     * The new title.
     */
    const std::string title;
    /**
     * The font family for the title.
     */
    const std::string fontFamily;
    /**
     * The font size for the title.
     */
    const uint8_t fontSize;
    /**
     * The font style for the title.
     */
    const std::string fontStyle;
    /**
     * Boolean indicating an underline under the title.
     */
    const bool fontUnderline;
    /**
     * Boolean indicating if the title is visible.
     */
    const bool showTitle;
    /**
     * Vertical alignment of the title. Possible values are "top", "bottom" and "middle".
     */
    const std::string titleAlignment;
    /**
     * Title color.
     */
    const std::string titleColor;

    TitleParametersDidChangeEvent(std::string action, std::string context, std::string device, boost::json::object settings, uint8_t coordinatesColumn,
                                  uint8_t coordinatesRow, uint8_t state, std::string title, std::string fontFamily, uint8_t fontSize, std::string fontStyle, bool fontUnderline,
                                  bool showTitle, std::string titleAlignment, std::string titleColor);
    ~TitleParametersDidChangeEvent() override;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_TITLEPARAMETERSDIDCHANGEEVENT_H
