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
#   File: lamna.pri
#
# Author: $author$
#   Date: 6/11/2018
#
# QtCreator .pri file for qtere executable lamna
########################################################################

########################################################################
# lamna

# lamna_exe TARGET
#
lamna_exe_TARGET = lamna

# lamna_exe INCLUDEPATH
#
lamna_exe_INCLUDEPATH += \
$${qtere_INCLUDEPATH} \

# lamna_exe DEFINES
#
lamna_exe_DEFINES += \
$${qtere_DEFINES} \

########################################################################
# lamna_exe OBJECTIVE_HEADERS
#
#lamna_exe_OBJECTIVE_HEADERS += \
#$${QTERE_SRC}/qtere/base/Base.hh \

# lamna_exe OBJECTIVE_SOURCES
#
#lamna_exe_OBJECTIVE_SOURCES += \
#$${QTERE_SRC}/qtere/base/Base.mm \

########################################################################
# lamna_exe HEADERS
#
lamna_exe_HEADERS += \
$${NADIR_SRC}/xos/base/linked/item.hpp \
$${NADIR_SRC}/xos/base/linked/list.hpp \
$${FILA_SRC}/xos/console/main_main.hpp \
$${LAMNA_SRC}/xos/graphic/base.hpp \
$${LAMNA_SRC}/xos/graphic/image_base_interface.hpp \
$${LAMNA_SRC}/xos/graphic/image_base.hpp \
$${LAMNA_SRC}/xos/graphic/image_interface.hpp \
$${LAMNA_SRC}/xos/graphic/bresenham_line.hpp \
$${LAMNA_SRC}/xos/graphic/bresenham_image.hpp \
$${LAMNA_SRC}/xos/graphic/midpoint_circle.hpp \
$${LAMNA_SRC}/xos/graphic/hollow_midpoint_circle.hpp \
$${LAMNA_SRC}/xos/graphic/midpoint_circle_image.hpp \
$${LAMNA_SRC}/xos/graphic/midpoint_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/hollow_midpoint_ellipse.hpp \
$${LAMNA_SRC}/xos/graphic/midpoint_ellipse_image.hpp \
$${LAMNA_SRC}/xos/graphic/base_image.hpp \
$${LAMNA_SRC}/xos/graphic/image.hpp \
$${LAMNA_SRC}/xos/graphic/shape_item.hpp \
$${LAMNA_SRC}/xos/graphic/shape_interface.hpp \
$${LAMNA_SRC}/xos/graphic/shape.hpp \
$${LAMNA_SRC}/xos/graphic/surface/pixel_interface.hpp \
$${LAMNA_SRC}/xos/graphic/surface/pixel.hpp \
$${LAMNA_SRC}/xos/graphic/surface/context_interface.hpp \
$${LAMNA_SRC}/xos/graphic/surface/context.hpp \
$${LAMNA_SRC}/xos/graphic/surface/image_interface.hpp \
$${LAMNA_SRC}/xos/graphic/surface/image.hpp \
$${LAMNA_SRC}/xos/graphic/surface/shape.hpp \
$${LAMNA_SRC}/xos/graphic/surface/color.hpp \
$${LAMNA_SRC}/xos/graphic/surface/filled_circle.hpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/pixel.hpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/context.hpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/image.hpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/shape.hpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/color.hpp \
$${QTERE_SRC}/xos/app/gui/qt/lamna/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/lamna/Main.hpp \

# lamna_exe SOURCES
#
lamna_exe_SOURCES += \
$${NADIR_SRC}/xos/base/linked/item.cpp \
$${NADIR_SRC}/xos/base/linked/list.cpp \
$${FILA_SRC}/xos/console/main_main.cpp \
$${LAMNA_SRC}/xos/graphic/base.cpp \
$${LAMNA_SRC}/xos/graphic/image_base_interface.cpp \
$${LAMNA_SRC}/xos/graphic/image_base.cpp \
$${LAMNA_SRC}/xos/graphic/bresenham_line.cpp \
$${LAMNA_SRC}/xos/graphic/bresenham_image.cpp \
$${LAMNA_SRC}/xos/graphic/midpoint_circle.cpp \
$${LAMNA_SRC}/xos/graphic/hollow_midpoint_circle.cpp \
$${LAMNA_SRC}/xos/graphic/midpoint_circle_image.cpp \
$${LAMNA_SRC}/xos/graphic/midpoint_ellipse.cpp \
$${LAMNA_SRC}/xos/graphic/hollow_midpoint_ellipse.cpp \
$${LAMNA_SRC}/xos/graphic/midpoint_ellipse_image.cpp \
$${LAMNA_SRC}/xos/graphic/base_image.cpp \
$${LAMNA_SRC}/xos/graphic/shape_item.cpp \
$${LAMNA_SRC}/xos/graphic/shape_interface.cpp \
$${LAMNA_SRC}/xos/graphic/surface/pixel_interface.cpp \
$${LAMNA_SRC}/xos/graphic/surface/context_interface.cpp \
$${LAMNA_SRC}/xos/graphic/surface/image_interface.cpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/pixel.cpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/context.cpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/image.cpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/shape.cpp \
$${LAMNA_SRC}/xos/graphic/surface/qt/color.cpp \
$${LAMNA_SRC}/xos/graphic/surface/filled_circle.cpp \
$${QTERE_SRC}/xos/app/gui/qt/lamna/MainWindow.cpp \
$${QTERE_SRC}/xos/app/gui/qt/lamna/Main.cpp \

########################################################################
# lamna_exe FRAMEWORKS
#
lamna_exe_FRAMEWORKS += \
$${qtere_FRAMEWORKS} \

# lamna_exe LIBS
#
lamna_exe_LIBS += \
$${qtere_LIBS} \

