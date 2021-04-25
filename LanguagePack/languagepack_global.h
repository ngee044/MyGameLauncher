#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LANGUAGEPACK_LIB)
#  define LANGUAGEPACK_EXPORT Q_DECL_EXPORT
# else
#  define LANGUAGEPACK_EXPORT Q_DECL_IMPORT
# endif
#else
# define LANGUAGEPACK_EXPORT
#endif
