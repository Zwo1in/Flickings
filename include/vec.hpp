#include <cmath>
#include "rand.hpp"

struct vec {
    float x, y;

    vec();
    vec(float, float);
    static inline vec randVec(int, int);
    static inline vec randVec(int, int, int, int);

    inline const float len() const;
    inline const float arc() const;
    inline vec   unit() const;
    inline void  setLen(const float&);
    inline void  setArc(const float&);
    inline void  rotate(const float&);
    inline void  limit(const float&);

    friend vec  operator+  (const vec&, const vec&);
    friend vec  operator-  (const vec&, const vec&);
    inline vec& operator+= (const vec&);
    inline vec& operator-= (const vec&);
    friend vec operator*  (const vec&, const float&);
    friend vec operator/  (const vec&, const float&);
    friend vec operator*  (const float&, const vec&);
    friend vec operator/  (const float&, const vec&);
    inline vec& operator*= (const float&);
    inline vec& operator/= (const float&);
    friend bool operator== (const vec&, const vec&);
    friend bool operator!= (const vec&, const vec&);
};