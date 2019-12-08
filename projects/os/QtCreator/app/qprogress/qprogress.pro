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
#   File: qprogress.pro
#
# Author: $author$
#   Date: 10/22/2019
#
# QtCreator .pro file for qtere executable qprogress
########################################################################
include(../../../../../build/QtCreator/qtere.pri)
include(../../../../QtCreator/qtere.pri)
include(../../qtere.pri)
include(../../../../QtCreator/app/qprogress/qprogress.pri)

TARGET = $${qprogress_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${qprogress_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${qprogress_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${qprogress_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${qprogress_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${qprogress_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${qprogress_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${qprogress_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${qprogress_LIBS} \
$${FRAMEWORKS} \


