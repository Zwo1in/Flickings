#include <cmath>

struct vec {
    float x, y;

    vec();
    vec(float, float);

    const float len() const;
    const float arc() const;
    const vec   unit() const;
    void  setLen(const float&);
    void  setArc(const float&);
    void  rotate(const float&);
    void  limit(const float&);
    friend vec  operator+  (const vec&, const vec&);
    friend vec  operator-  (const vec&, const vec&);
    vec& operator+= (const vec&);
    vec& operator-= (const vec&);
    friend vec operator*  (const vec&, const float&);
    friend vec operator/  (const vec&, const float&);
    friend vec operator*  (const float&, const vec&);
    friend vec operator/  (const float&, const vec&);
    vec& operator*= (const float&);
    vec& operator/= (const float&);
    friend bool operator== (const vec&, const vec&);
    friend bool operator!= (const vec&, const vec&);
};