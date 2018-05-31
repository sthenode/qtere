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
#   File: qtere.pri
#
# Author: $author$
#   Date: 5/30/2018
#
# QtCreator .pri file for qtere executable qtere
########################################################################

########################################################################
# qtere

# qtere_exe TARGET
#
qtere_exe_TARGET = qtere

# qtere_exe INCLUDEPATH
#
qtere_exe_INCLUDEPATH += \
$${qtere_INCLUDEPATH} \

# qtere_exe DEFINES
#
qtere_exe_DEFINES += \
$${qtere_DEFINES} \

########################################################################
# qtere_exe OBJECTIVE_HEADERS
#
#qtere_exe_OBJECTIVE_HEADERS += \
#$${QTERE_SRC}/qtere/base/Base.hh \

# qtere_exe OBJECTIVE_SOURCES
#
#qtere_exe_OBJECTIVE_SOURCES += \
#$${QTERE_SRC}/qtere/base/Base.mm \

########################################################################
# qtere_exe HEADERS
#
qtere_exe_HEADERS += \
$${FILA_SRC}/xos/console/main_main.hpp \
$${VEDERE_SRC}/xos/gui/main.hpp \
$${QTERE_SRC}/xos/gui/qt/Qt.hpp \
$${QTERE_SRC}/xos/gui/qt/application/MainWindow.hpp \
$${QTERE_SRC}/xos/gui/qt/application/Main.hpp \
$${QTERE_SRC}/xos/gui/qt/application/WindowMain.hpp \
$${QTERE_SRC}/xos/app/gui/qt/qtere/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/qtere/Main.hpp \

# qtere_exe SOURCES
#
qtere_exe_SOURCES += \
$${FILA_SRC}/xos/console/main_main.cpp \
$${QTERE_SRC}/xos/gui/qt/Qt.cpp \
$${QTERE_SRC}/xos/gui/qt/application/WindowMain.cpp \
$${QTERE_SRC}/xos/app/gui/qt/qtere/MainWindow.cpp \
$${QTERE_SRC}/xos/app/gui/qt/qtere/Main.cpp \

########################################################################
# qtere_exe FRAMEWORKS
#
qtere_exe_FRAMEWORKS += \
$${qtere_FRAMEWORKS} \

# qtere_exe LIBS
#
qtere_exe_LIBS += \
$${qtere_LIBS} \


