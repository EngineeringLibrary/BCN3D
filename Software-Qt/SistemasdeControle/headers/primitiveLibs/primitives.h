#ifndef PRIMITIVES_H
#define PRIMITIVES_H

inline unsigned factorial(unsigned n)
{
    unsigned retval = 1;
    for (int i = n; i > 1; --i)  retval *= i;
    return retval;
}

#endif // PRIMITIVES_H
