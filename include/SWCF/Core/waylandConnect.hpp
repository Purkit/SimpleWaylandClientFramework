#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <SWCF/defines.h>
#include <wayland-client.h>

namespace SWCF {
    namespace Core {

        class WaylandCompositorConnection {

            public:
                static WaylandCompositorConnection& getInstance();

                bool connectToWaylandCompositor();
                bool disconnectFromWaylandCompositor();

                wl_display* getWaylandConnectionHandle();
            
            private:
                wl_display* m_compositor_connection;
            
            private:
                static WaylandCompositorConnection* m_Instance;
            
            private:                
                WaylandCompositorConnection() {}
                ~WaylandCompositorConnection() {}
            
            public:
                WaylandCompositorConnection(const WaylandCompositorConnection&) = delete;
                WaylandCompositorConnection& operator=(const WaylandCompositorConnection&) = delete;
            
        };

    }
}

#endif // ! CONNECT_HPP