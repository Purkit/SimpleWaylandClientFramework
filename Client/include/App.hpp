#ifndef APP_HPP
#define APP_HPP

namespace WaylandClient {

    class Application {

        public:

            Application(const Application&) = delete;
            Application(Application&&) = delete;
            Application& operator=(const Application&) = delete;
            Application& operator=(Application&&) = delete;


            void Run();

    };
}

#endif // ! APP_HPP