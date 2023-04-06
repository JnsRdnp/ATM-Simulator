#ifndef BALANCE_GLOBAL_H
#define BALANCE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BALANCE_LIBRARY)
#  define BALANCE_EXPORT Q_DECL_EXPORT
#else
#  define BALANCE_EXPORT Q_DECL_IMPORT
#endif

#endif // BALANCE_GLOBAL_H
