########################################################################
# Copyright (c) 1988-2018 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: vedere.pri
#
# Author: $author$
#   Date: 6/17/2018
#
# QtCreator .pri file for qtere executable vedere
########################################################################

########################################################################
# vedere

# vedere_exe TARGET
#
vedere_exe_TARGET = vedere

# vedere_exe INCLUDEPATH
#
vedere_exe_INCLUDEPATH += \
$${qtere_INCLUDEPATH} \

# vedere_exe DEFINES
#
vedere_exe_DEFINES += \
$${qtere_DEFINES} \

########################################################################
# vedere_exe OBJECTIVE_HEADERS
#
#vedere_exe_OBJECTIVE_HEADERS += \
#$${QTERE_SRC}/qtere/base/Base.hh \

# vedere_exe OBJECTIVE_SOURCES
#
#vedere_exe_OBJECTIVE_SOURCES += \
#$${QTERE_SRC}/qtere/base/Base.mm \

########################################################################
# vedere_exe HEADERS
#
vedere_exe_HEADERS += \
$${FILA_SRC}/xos/console/main_main.hpp \
$${LAMNA_SRC}/xos/graphic/image/base.hpp \
$${LAMNA_SRC}/xos/graphic/image/base/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/base/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/base/image.hpp \
$${LAMNA_SRC}/xos/graphic/image/bresenham_line.hpp \
$${LAMNA_SRC}/xos/graphic/image/midpoint_circle.hpp \
$${LAMNA_SRC}/xos/graphic/image/hollow_midpoint_circle.hpp \
$${LAMNA_SRC}/xos/graphic/image/midpoint_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/image/hollow_midpoint_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/image/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/shape/bresenham_line.hpp \
$${LAMNA_SRC}/xos/graphic/image/shape/midpoint_circle.hpp \
$${LAMNA_SRC}/xos/graphic/image/shape/midpoint_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/image/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/pixel/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/pixel/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/context/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/context/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/area/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/interface.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/color.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/filled_circle.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/filled_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/area/extend.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/pixel.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/context.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/area.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/shape.hpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/color.hpp \
$${QTERE_SRC}/xos/app/gui/qt/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/Main.hpp \

# vedere_exe SOURCES
#
vedere_exe_SOURCES += \
$${FILA_SRC}/xos/console/main_main.cpp \
$${LAMNA_SRC}/xos/graphic/image/base.cpp \
$${LAMNA_SRC}/xos/graphic/image/base/image.cpp \
$${LAMNA_SRC}/xos/graphic/image/shape/midpoint_circle.cpp \
$${LAMNA_SRC}/xos/graphic/image/hollow_midpoint_circle.cpp \
$${LAMNA_SRC}/xos/graphic/image/shape/midpoint_ellipse.cpp \
$${LAMNA_SRC}/xos/graphic/image/hollow_midpoint_ellipse.cpp \
$${LAMNA_SRC}/xos/graphic/image/shape/bresenham_line.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/area/interface.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/area/extend.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/filled_circle.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/shape/filled_ellipse.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/pixel.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/context.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/area.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/shape.cpp \
$${LAMNA_SRC}/xos/graphic/image/surface/qt/color.cpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/MainWindow.cpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/Main.cpp \

########################################################################
# vedere_exe FRAMEWORKS
#
vedere_exe_FRAMEWORKS += \
$${qtere_FRAMEWORKS} \

# vedere_exe LIBS
#
vedere_exe_LIBS += \
$${qtere_LIBS} \
