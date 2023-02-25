#ifndef TILING_WINDOW_MANAGER_HPP
#define TILING_WINDOW_MANAGER_HPP

#include "TileNode.hpp"
#include "miral/window_management_policy.h"
#include "miral/window_specification.h"
#include <memory>
#include <miral/minimal_window_manager.h>
#include <mir_toolkit/events/enums.h>
#include <chrono>
#include <map>
#include <vector>

namespace miral { class InternalClientLauncher; }

using namespace mir::geometry;

/**
* An implementation of a tiling window manager, much like i3.
*/
class FloatingWindowManagerPolicy : public miral::MinimalWindowManager {
public:
    FloatingWindowManagerPolicy(
        miral::WindowManagerTools const& tools,
        miral::InternalClientLauncher const& launcher,
        std::function<void()>& shutdown_hook);
    ~FloatingWindowManagerPolicy();

    /**
    * Positions the new window in reference to the currently selected window and the current mode.
    */
    virtual miral::WindowSpecification place_new_window(
        miral::ApplicationInfo const& app_info, miral::WindowSpecification const& request_parameters) override;


    bool handle_pointer_event(MirPointerEvent const* event) override;
    bool handle_touch_event(MirTouchEvent const* event) override;
    bool handle_keyboard_event(MirKeyboardEvent const* event) override;

    /** Add the window to the active zone. */
    void advise_new_window(miral::WindowInfo const& window_info) override;
    void handle_window_ready(miral::WindowInfo& window_info) override;
    void advise_focus_gained(miral::WindowInfo const& info) override;

    void handle_modify_window(miral::WindowInfo& window_info, miral::WindowSpecification const& modifications) override;

protected:
    static const int pModifierMask =
        mir_input_event_modifier_alt |
        mir_input_event_modifier_shift |
        mir_input_event_modifier_sym |
        mir_input_event_modifier_ctrl |
        mir_input_event_modifier_meta;

private:
    std::shared_ptr<TileNode> mRootTileNode;
    std::shared_ptr<TileNode> mActiveTileNode;
    PlacementStrategy mDefaultStrategy;
    std::shared_ptr<miral::Window> mActiveWindow;

    void requestPlacementStrategyChange(PlacementStrategy strategy);
    void requestQuitSelectedApplication();
    void requestChangeActiveWindow(int, std::shared_ptr<TileNode>);
};

#endif //TILING_WINDOW_MANAGER_HPP
