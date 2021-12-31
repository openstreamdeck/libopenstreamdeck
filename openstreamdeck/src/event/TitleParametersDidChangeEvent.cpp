//
// Created by Cyril Vlaminck on 26/12/2021.
//

#include "TitleParametersDidChangeEvent.h"

#include <utility>

namespace openstreamdeck {

TitleParametersDidChangeEvent::TitleParametersDidChangeEvent(std::string action, std::string context, std::string device, boost::json::object settings,
                                                             uint8_t coordinatesColumn, uint8_t coordinatesRow, uint8_t state, std::string title,
                                                             std::string fontFamily, uint8_t fontSize, std::string fontStyle, bool fontUnderline,
                                                             bool showTitle, std::string titleAlignment, std::string titleColor)
    : Event(kTitleParametersDidChangeEvent, std::move(action), std::move(context), std::move(device)),
      settings(std::move(settings)),
      coordinatesColumn(coordinatesColumn),
      coordinatesRow(coordinatesRow),
      state(state),
      title(std::move(title)),
      fontFamily(std::move(fontFamily)),
      fontSize(fontSize),
      fontStyle(std::move(fontStyle)),
      fontUnderline(fontUnderline),
      showTitle(showTitle),
      titleAlignment(std::move(titleAlignment)),
      titleColor(std::move(titleColor)) {
}

TitleParametersDidChangeEvent::~TitleParametersDidChangeEvent() = default;

}  // namespace openstreamdeck
