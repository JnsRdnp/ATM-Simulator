#ifndef MENUUIDLL_GLOBAL_H
#define MENUUIDLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENUUIDLL_LIBRARY)
#  define MENUUIDLL_EXPORT Q_DECL_EXPORT
#else
#  define MENUUIDLL_EXPORT Q_DECL_IMPORT
#endif

#endif // MENUUIDLL_GLOBAL_H
