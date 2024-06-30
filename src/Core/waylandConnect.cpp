#include <SWCF/Core/waylandConnect.hpp>

namespace SWCF {
    namespace Core {

        WaylandCompositorConnection* WaylandCompositorConnection::m_Instance = nullptr;
        wl_display* WaylandCompositorConnection::compositor_connection_t;

        WaylandCompositorConnection& WaylandCompositorConnection::getInstance() {
            if (!m_Instance)
                m_Instance = new WaylandCompositorConnection();
            
            return *m_Instance;
        }

        bool WaylandCompositorConnection::connectToWaylandCompositor() {
            compositor_connection_t = wl_display_connect(NULL);
            if (!compositor_connection_t)
                return false;
            return true;
        }

        bool WaylandCompositorConnection::disconnectFromWaylandCompositor() {
            if (compositor_connection_t)
                wl_display_disconnect(compositor_connection_t);
        }

        wl_display* WaylandCompositorConnection::getWaylandConnectionHandle() {
            return compositor_connection_t;
        }
    }
}