#define GAME_SCRIPT(className)                              \
engine::GameScript* getGameScript() {                       \
    return new className();                                 \
}