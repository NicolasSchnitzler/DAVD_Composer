/* FilterProcess.cpp ---
 *
 * Author: Nicolas Schnitzler
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "FilterProcess.h"
#include "FilterProcess_p.h"

#include <dtkLog/dtkLog.h>

// /////////////////////////////////////////////////////////////////
// FilterProcess implementation
// /////////////////////////////////////////////////////////////////

FilterProcess::FilterProcess(void) : dtkAbstractProcess(*new FilterProcessPrivate(this), 0)
{
    // DTK_D(FilterProcess);
}


FilterProcess::~FilterProcess(void)
{

}

void FilterProcess::run()
{

}

Image *FilterProcess::output()
{
    return d->filteredImage;
}

QString FilterProcess::identifier(void) const
{
    return "FilterProcess";
}

