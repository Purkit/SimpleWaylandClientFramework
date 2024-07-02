#include <Client/include/App.hpp>

#include <SWCF/DebugUtil/Logger/logger.hpp>

#include <SWCF/Core/waylandConnect.hpp>
#include <SWCF/Core/waylandInterface.hpp>

#include <iostream>


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

        if(waylandCompositorInterface.HasInterface("wl_compositor")) {
            std::cout << "Interface 'wl_compositor' is supported." << "\n";
        }
        else
            std::cout << "Interface 'wl_compositor is unsupported.'" << "\n";
        
        if(waylandCompositorInterface.HasInterface("wl_seat")) {
            std::cout << "Interface 'wl_seat' is supported." << "\n";
        }
        else
            std::cout << "Interface 'wl_seat' is unsupported.'" << "\n";

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