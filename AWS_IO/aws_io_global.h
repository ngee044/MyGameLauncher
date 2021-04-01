#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(AWS_IO_LIB)
#  define AWS_IO_EXPORT Q_DECL_EXPORT
# else
#  define AWS_IO_EXPORT Q_DECL_IMPORT
# endif
#else
# define AWS_IO_EXPORT
#endif
