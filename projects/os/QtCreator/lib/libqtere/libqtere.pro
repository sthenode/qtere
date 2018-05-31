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
#   File: libqtere.pro
#
# Author: $author$
#   Date: 5/30/2018
#
# QtCreator .pro file for qtere library libqtere
########################################################################
include(../../../../../build/QtCreator/qtere.pri)
include(../../../../QtCreator/qtere.pri)
include(../../qtere.pri)
include(../../../../QtCreator/lib/libqtere/libqtere.pri)

TARGET = $${libqtere_TARGET}
TEMPLATE = $${libqtere_TEMPLATE}
CONFIG += $${libqtere_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libqtere_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libqtere_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libqtere_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
SOURCES += \
$${libqtere_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libqtere_HEADERS} \

# SOURCES
#
SOURCES += \
$${libqtere_SOURCES} \
$${OBJECTIVE_SOURCES} \

########################################################################


