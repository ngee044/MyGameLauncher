#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(REDISDBIO_LIB)
#  define REDISDBIO_EXPORT Q_DECL_EXPORT
# else
#  define REDISDBIO_EXPORT Q_DECL_IMPORT
# endif
#else
# define REDISDBIO_EXPORT
#endif
