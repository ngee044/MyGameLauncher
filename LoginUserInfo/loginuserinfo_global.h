#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LOGINUSERINFO_LIB)
#  define LOGINUSERINFO_EXPORT Q_DECL_EXPORT
# else
#  define LOGINUSERINFO_EXPORT Q_DECL_IMPORT
# endif
#else
# define LOGINUSERINFO_EXPORT
#endif
