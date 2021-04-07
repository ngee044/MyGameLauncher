#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(UICOMPONENT_LIB)
#  define UICOMPONENT_EXPORT Q_DECL_EXPORT
# else
#  define UICOMPONENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define UICOMPONENT_EXPORT
#endif
