#include <SWCF/Core/waylandConnect.hpp>

namespace SWCF {
    namespace Core {

        WaylandCompositorConnection* WaylandCompositorConnection::m_Instance = nullptr;

        WaylandCompositorConnection& WaylandCompositorConnection::getInstance() {
            if (!m_Instance)
                m_Instance = new WaylandCompositorConnection();
            
            return *m_Instance;
        }

        bool WaylandCompositorConnection::connectToWaylandCompositor() {
            m_compositor_connection = wl_display_connect(NULL);
            if (!m_compositor_connection)
                return false;
            return true;
        }

        bool WaylandCompositorConnection::disconnectFromWaylandCompositor() {
            if (m_compositor_connection)
                wl_display_disconnect(m_compositor_connection);
                return true;
            return false;
        }

        wl_display* WaylandCompositorConnection::getWaylandConnectionHandle() {
            return m_compositor_connection;
        }
    }
}