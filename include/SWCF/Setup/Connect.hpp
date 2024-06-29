#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <SWCF/defines.h>
#include <wayland-client.h>

namespace SWCF {
    namespace Setup {

        class WaylandCompositorConnection {
            public:
                static WaylandCompositorConnection& getInstance();

                bool connectToWaylandCompositor();

                wl_display* getWaylandConnectionHandle();
            
            private:
                WaylandCompositorConnection() {}
                ~WaylandCompositorConnection();
            
            private:
                wl_display* compositor_connection_t;
            
            private:
                static WaylandCompositorConnection* m_Instance;


        };



    }
}

#endif // ! CONNECT_HPP