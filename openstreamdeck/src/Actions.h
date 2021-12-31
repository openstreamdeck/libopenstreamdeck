//
// Created by Cyril Vlaminck on 27/12/2021.
//

#ifndef STREAMDECK_COMMAND_ACTIONS_H
#define STREAMDECK_COMMAND_ACTIONS_H

#include <boost/json.hpp>
#include <optional>
#include <string>

namespace openstreamdeck {

typedef enum { kSetTitleTargetBoth = 0, kSetTitleTargetHardware = 1, kSetTitleTargetSoftware = 2 } SetTitleTarget;
typedef enum { kSetImageTargetBoth = 0, kSetImageTargetHardware = 1, kSetImageTargetSoftware = 2 } SetImageTarget;

class Actions {
   public:
    /**
     * Save data persistently for the action's instance.
     *
     * @param context An opaque value identifying the instance's action.
     * @param payload A json object which is persistently saved for the action's instance.
     */
    virtual auto setSettings(std::string context, boost::json::object payload) -> void = 0;

    /**
     * Request the persistent data stored for the action's instance.
     *
     * The plugin will receive asynchronously an event didReceiveSettings containing the settings for this action.
     *
     * @param context An opaque value identifying the instance's action.
     */
    virtual auto getSettings(std::string context) -> void = 0;

    /**
     * Save persistent data globally and not just to one instance of an action.
     *
     * The data will be saved securely to the Keychain on macOS and to the Credential Store on Windows.
     * This API can be used for example to save tokens that should be available to all the actions of the plugin.
     *
     * @param payload A json object which is persistently saved globally.
     */
    virtual auto setGlobalSettings(boost::json::object payload) -> void = 0;

    /**
     * Request the global persistent data.
     *
     * The plugin will receive asynchronously an event didReceiveGlobalSettings containing the global settings.
     */
    virtual auto getGlobalSettings() -> void = 0;

    /**
     * Open an URL in the default browser.
     *
     * @param url An URL to open in the default browser.
     */
    virtual auto openUrl(std::string url) -> void = 0;

    /**
     * Write a debug message to the logs file.
     *
     * @param message A string to write to the logs file.
     */
    virtual auto logMessage(std::string message) -> void = 0;

    /**
     * Change the title displayed by an instance of an action.
     *
     * @param context An opaque value identifying the instance's action you want to modify.
     * @param title The title to display. If there is no title parameter, the title is reset to the title set by the user.
     * @param target Specify if you want to display the title on the hardware and software, only on the hardware or only on the software.
     * @param state A 0-based integer value representing the state of an action with multiple states. This is an optional parameter. If not specified, the title
     * is set to all states.
     */
    virtual auto setTitle(std::string context, std::string title, SetTitleTarget target, std::optional<uint8_t> state) -> void = 0;

    /**
     * Change the image displayed by an instance of an action.
     *
     * @param context An opaque value identifying the instance's action you want to modify.
     * @param image The image to display encoded in base64 with the image format declared in the mime type (PNG, JPEG, BMP, ...). svg is also supported. If no
     * image is passed, the image is reset to the default image from the manifest.
     * @param target Specify if you want to display the title on the hardware and software, only on the hardware or only on the software.
     * @param state A 0-based integer value representing the state of an action with multiple states. This is an optional parameter. If not specified, the image
     * is set to all states.
     */
    virtual auto setImage(std::string context, std::optional<std::string> image, SetImageTarget target, std::optional<uint8_t> state) -> void = 0;

    /**
     * Temporarily show an alert icon on the image displayed by an instance of an action.
     *
     * @param context An opaque value identifying the instance's action you want to modify.
     */
    virtual auto showAlert(std::string context) -> void = 0;

    /**
     * Temporarily show an OK checkmark icon on the image displayed by an instance of an action.
     *
     * @param context An opaque value identifying the instance's action you want to modify.
     */
    virtual auto showOk(std::string context) -> void = 0;

    /**
     * Change the state of an action supporting multiple states.
     *
     * @param context An opaque value identifying the instance's action you want to modify.
     * @param state A 0-based integer value representing the state requested.
     */
    virtual auto setState(std::string context, uint8_t state) -> void = 0;

    /**
     * Switch to one of his preconfigured read-only profile.
     *
     * @param device An opaque value identifying the device.
     * @param profile The name of the profile to switch to. The name should be identical to the name provided in the manifest.json file.
     */
    virtual auto switchToProfile(std::string device, std::string profile) -> void = 0;

    /**
     * Send a payload to the Property Inspector.
     *
     * @param context An opaque value identifying the instance's action.
     * @param action The action unique identifier.
     * @param payload A json object that will be received by the Property Inspector.
     */
    virtual auto sendToPropertyInspector(std::string context, std::string action, boost::json::object payload) -> void = 0;
};

}  // namespace openstreamdeck

#endif  // STREAMDECK_COMMAND_ACTIONS_H
