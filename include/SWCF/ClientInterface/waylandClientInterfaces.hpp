#ifndef WAYLAND_CLIENT_INTERFACE_HPP
#define WAYLAND_CLIENT_INTERFACE_HPP

#include <wayland-client.h>

namespace SWCF {
    namespace ClientInterface {


        class Compositor {

            public:
                static Compositor& GetInstance();
                wl_compositor* GetCompositor() const { return m_compositor; }

                bool Initialize();

            private:
                static Compositor* m_Instance;

                wl_compositor* m_compositor;
            
            public:
                Compositor(const Compositor&) = delete;
                Compositor& operator=(const Compositor&) = delete;
            
            private:
                Compositor() {}
                ~Compositor() {}


        };




        
    }
}

#endif // ! WAYLAND_CLIENT_INTERFACE_HPP