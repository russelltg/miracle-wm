#ifndef WORKSPACE_MANAGER_H
#define WORKSPACE_MANAGER_H

#include <memory>
#include <vector>
#include <miral/window_manager_tools.h>
#include <list>
#include <map>

namespace miracle
{

using miral::Window;
using miral::WindowInfo;
using miral::WindowManagerTools;
using miral::WindowSpecification;
using miral::Workspace;

class Screen;

// TODO:
// As it stands, this isn't exactly what I want. What I do want
// is a workspace manager that is output-aware. The data structure
// should be a global WorkspaceManager who holds a mapping of Screens -> Workspaces.
// Workspaces should have a name and be organized according to that name. This
// goes to mean that we should ignore the idea of a vector of workspaces, and settle
// for char-encoded workspaces instead.

struct WorkspaceInfo
{
    char key;
    std::shared_ptr<Screen> screen;
};


class WorkspaceManager
{
public:
    explicit WorkspaceManager(WindowManagerTools const& tools);
    virtual ~WorkspaceManager() = default;

    /// Request the workspace. If it does not yet exist, then one
    /// is created on the current Screen. If it does exist, we navigate
    /// to the screen containing that workspace and show it if it
    /// isn't already shown.
    std::shared_ptr<Screen> request_workspace(std::shared_ptr<Screen> screen, char workspace);

    bool request_first_available_workspace(std::shared_ptr<Screen> screen);

    bool move_active_to_workspace(std::shared_ptr<Screen> screen, char workspace);

    bool delete_workspace(char workspace);

private:
    WindowManagerTools tools_;

    std::vector<WorkspaceInfo> workspaces;

    void erase_if_empty(std::vector<std::shared_ptr<Workspace>>::iterator const& old_workspace);
};
}

#endif
