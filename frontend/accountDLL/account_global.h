#ifndef ACCOUNT_GLOBAL_H
#define ACCOUNT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ACCOUNT_LIBRARY)
#  define ACCOUNT_EXPORT Q_DECL_EXPORT
#else
#  define ACCOUNT_EXPORT Q_DECL_IMPORT
#endif

#endif // ACCOUNT_GLOBAL_H
