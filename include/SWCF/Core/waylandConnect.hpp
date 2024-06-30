#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <SWCF/defines.h>
#include <wayland-client.h>

namespace SWCF {
    namespace Core {

        class WaylandCompositorConnection {
            public:
                static WaylandCompositorConnection& getInstance();

                static bool connectToWaylandCompositor();
                static bool disconnectFromWaylandCompositor();

                static wl_display* getWaylandConnectionHandle();
            
            private:
                static wl_display* compositor_connection_t;
            
            private:
                static WaylandCompositorConnection* m_Instance;
            
        };

    }
}

#endif // ! CONNECT_HPP