/* FilterProcess_p.h ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef FILTERPROCESS_P_H
#define FILTERPROCESS_P_H


#include <dtkCoreSupport/dtkAbstractProcess_p.h>

class FilterProcess;

////////////////////////////////////////////////////
// FilterProcessPrivate interface
////////////////////////////////////////////////////

class FilterProcessPrivate : public dtkAbstractProcessPrivate
{
public:
    FilterProcessPrivate(FilterProcess *q = 0) : dtkAbstractProcessPrivate(q) {}
    FilterProcessPrivate(const FilterProcessPrivate& other) : dtkAbstractProcessPrivate(other) {}

public:
    virtual ~FilterProcessPrivate(void) {}

public:
   Image *imageIn,*filter,*filteredImage;
};

////////////////////////////////////////////////////
// FilterProcess protected constructors
////////////////////////////////////////////////////

DTK_IMPLEMENT_PRIVATE(FilterProcess, dtkAbstractProcess);

#endif

