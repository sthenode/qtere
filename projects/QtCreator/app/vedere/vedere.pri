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
$${VEDERE_SRC}/xos/graphic/surface/base.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/interface_base.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/base.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/bresenham_line.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/midpoint_circle.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/hollow_midpoint_circle.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/midpoint_ellipse.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/hollow_midpoint_ellipse.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/interface.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/extend.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/base.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/bresenham_line.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/midpoint_circle.hpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/midpoint_ellipse.hpp \
$${QTERE_SRC}/xos/app/gui/qt/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/vedere/Main.hpp \

# vedere_exe SOURCES
#
vedere_exe_SOURCES += \
$${FILA_SRC}/xos/console/main_main.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/interface_base.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/midpoint_circle.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/hollow_midpoint_circle.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/midpoint_ellipse.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/hollow_midpoint_ellipse.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/bresenham_line.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/shape/base.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/interface.cpp \
$${VEDERE_SRC}/xos/graphic/surface/image/extend.cpp \
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


