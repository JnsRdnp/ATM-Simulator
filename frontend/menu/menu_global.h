#ifndef MENU_GLOBAL_H
#define MENU_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENU_LIBRARY)
#  define MENU_EXPORT Q_DECL_EXPORT
#else
#  define MENU_EXPORT Q_DECL_IMPORT
#endif

#endif // MENU_GLOBAL_H
