#include <SWCF/Setup/Connect.hpp>

namespace SWCF {
    namespace Setup {

        WaylandCompositorConnection* WaylandCompositorConnection::m_Instance = nullptr;

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

        wl_display* WaylandCompositorConnection::getWaylandConnectionHandle() {
            return compositor_connection_t;
        }

        WaylandCompositorConnection::WaylandCompositorConnection() {}

        WaylandCompositorConnection::~WaylandCompositorConnection() {
            if(compositor_connection_t)
                wl_display_disconnect(compositor_connection_t);
        }

    }
}