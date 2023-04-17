#ifndef CHOICES_GLOBAL_H
#define CHOICES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHOICES_LIBRARY)
#  define CHOICES_EXPORT Q_DECL_EXPORT
#else
#  define CHOICES_EXPORT Q_DECL_IMPORT
#endif

#endif // CHOICES_GLOBAL_H
