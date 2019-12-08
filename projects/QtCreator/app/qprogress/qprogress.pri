########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: qprogress.pri
#
# Author: $author$
#   Date: 10/22/2019
#
# QtCreator .pri file for qtere executable qprogress
########################################################################

########################################################################
# qprogress

# qprogress TARGET
#
qprogress_TARGET = qprogress

# qprogress INCLUDEPATH
#
qprogress_INCLUDEPATH += \
$${qtere_INCLUDEPATH} \

# qprogress DEFINES
#
qprogress_DEFINES += \
$${qtere_DEFINES} \

########################################################################
# qprogress OBJECTIVE_HEADERS
#
#qprogress_OBJECTIVE_HEADERS += \
#$${QTERE_SRC}/qtere/base/Base.hh \

# qprogress OBJECTIVE_SOURCES
#
#qprogress_OBJECTIVE_SOURCES += \
#$${QTERE_SRC}/qtere/base/Base.mm \

########################################################################
# qprogress HEADERS
#
qprogress_HEADERS += \
$${QTERE_SRC}/xos/app/gui/qt/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/WindowMain.hpp \
$${QTERE_SRC}/xos/app/gui/qt/MainMain.hpp \
$${QTERE_SRC}/xos/app/gui/qt/progress/MainWindow.hpp \
$${QTERE_SRC}/xos/app/gui/qt/progress/Main.hpp \

# qprogress SOURCES
#
qprogress_SOURCES += \
$${QTERE_SRC}/xos/app/gui/qt/WindowMain.cpp \
$${QTERE_SRC}/xos/app/gui/qt/MainMain.cpp \
$${QTERE_SRC}/xos/app/gui/qt/progress/MainWindow.cpp \
$${QTERE_SRC}/xos/app/gui/qt/progress/Main.cpp \

########################################################################
# qprogress FRAMEWORKS
#
qprogress_FRAMEWORKS += \
$${qtere_FRAMEWORKS} \

# qprogress LIBS
#
qprogress_LIBS += \
$${qtere_LIBS} \


