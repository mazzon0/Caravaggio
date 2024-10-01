#ifndef CRVG_GAMESCRIPT
#define CRVG_GAMESCRIPT

namespace engine {

    class GameScript {
    public:
        GameScript() = default;
        ~GameScript() = default;

        virtual void init()=0;
        virtual void update()=0;
        virtual void exit()=0;

    };

}

#endif