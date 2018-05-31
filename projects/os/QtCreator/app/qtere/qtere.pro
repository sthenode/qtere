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
#   File: qtere.pro
#
# Author: $author$
#   Date: 5/30/2018
#
# QtCreator .pro file for qtere executable qtere
########################################################################
include(../../../../../build/QtCreator/qtere.pri)
include(../../../../QtCreator/qtere.pri)
include(../../qtere.pri)
include(../../../../QtCreator/app/qtere/qtere.pri)

TARGET = $${qtere_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${qtere_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${qtere_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${qtere_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${qtere_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${qtere_exe_HEADERS} \

# SOURCES
#
SOURCES += \
$${qtere_exe_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${qtere_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${qtere_exe_LIBS} \
$${FRAMEWORKS} \


