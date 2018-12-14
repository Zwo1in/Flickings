#include <ctime>
#include <cstdlib>

struct random {

    random() = delete;
    random(random&) = delete;
    random(random&&) = delete;
    void operator= (random&) = delete;
    void operator= (random&&) = delete;

    static inline void init();
    static inline float randf();
    static inline float randf(int);
    static inline float randf(int, int);
    static inline int randi();
    static inline int randi(int);
    static inline int randi(int, int);
};