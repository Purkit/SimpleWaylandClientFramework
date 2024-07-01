#include <Client/include/App.hpp>

#include <SWCF/DebugUtil/Logger/logger.hpp>

#include <SWCF/Core/waylandConnect.hpp>
#include <SWCF/Core/waylandInterface.hpp>

namespace WaylandClient {

    void Application::Run() {

        SWCF::Core::WaylandCompositorConnection& waylandCompositorConnection = SWCF::Core::WaylandCompositorConnection::getInstance();
        if (waylandCompositorConnection.connectToWaylandCompositor()) {
            DEBUG("Connection to Wayland Compositor established successfully.");
        }
        else {
            ERROR("Failed to connect with Wayland Compositor. Make sure a Wayland Compositor is running in the background");
            ERROR("Quiting...");
            exit(1);
        }

        SWCF::Core::WaylandCompositorInterface& waylandCompositorInterface = SWCF::Core::WaylandCompositorInterface::getInstance();
        waylandCompositorInterface.Setup(waylandCompositorConnection.getWaylandConnectionHandle());

        if (waylandCompositorConnection.disconnectFromWaylandCompositor()) {
            DEBUG("Disconnected with Wayland Compositor successfully.");
        }
        else {
            WARN("Quiting without disconnecting with Wayland compositor!");
            exit(1);
        }
        

        INFO("[SUCCESS]");
    }
}