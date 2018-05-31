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
# build QtCreator .pri file for qtere
########################################################################

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# crono
#
# pkg-config --cflags --libs crono
#

# build crono INCLUDEPATH
#
build_crono_INCLUDEPATH += \

# build crono DEFINES
#
build_crono_DEFINES += \

# build crono LIBS
#
build_crono_LIBS += \

########################################################################
# fila
#
# pkg-config --cflags --libs fila
#

# build fila INCLUDEPATH
#
build_fila_INCLUDEPATH += \

# build fila DEFINES
#
build_fila_DEFINES += \

# build fila LIBS
#
build_fila_LIBS += \

########################################################################
# rete
#
# pkg-config --cflags --libs rete
#

# build rete INCLUDEPATH
#
build_rete_INCLUDEPATH += \

# build rete DEFINES
#
build_rete_DEFINES += \

# build rete LIBS
#
build_rete_LIBS += \

########################################################################
# lamna
#
# pkg-config --cflags --libs lamna
#

# build lamna INCLUDEPATH
#
build_lamna_INCLUDEPATH += \

# build lamna DEFINES
#
build_lamna_DEFINES += \

# build lamna LIBS
#
build_lamna_LIBS += \

########################################################################
# plena
#
# pkg-config --cflags --libs plena
#

# build plena INCLUDEPATH
#
build_plena_INCLUDEPATH += \

# build plena DEFINES
#
build_plena_DEFINES += \

# build plena LIBS
#
build_plena_LIBS += \

########################################################################
# vedere
#
# pkg-config --cflags --libs vedere
#

# build vedere INCLUDEPATH
#
build_vedere_INCLUDEPATH += \

# build vedere DEFINES
#
build_vedere_DEFINES += \

# build vedere LIBS
#
build_vedere_LIBS += \

########################################################################
# qtere

# build qtere INCLUDEPATH
#
build_qtere_INCLUDEPATH += \
$${build_vedere_INCLUDEPATH} \
$${build_plena_INCLUDEPATH} \
$${build_lamna_INCLUDEPATH} \
$${build_rete_INCLUDEPATH} \
$${build_fila_INCLUDEPATH} \
$${build_crono_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \


# build qtere DEFINES
#
build_qtere_DEFINES += \
$${build_rostra_DEFINES} \
$${build_nadir_DEFINES} \
$${build_crono_DEFINES} \
$${build_fila_DEFINES} \
$${build_rete_DEFINES} \
$${build_lamna_DEFINES} \
$${build_plena_DEFINES} \
$${build_vedere_DEFINES} \


# build qtere LIBS
#
build_qtere_LIBS += \
$${build_vedere_LIBS} \
$${build_plena_LIBS} \
$${build_lamna_LIBS} \
$${build_rete_LIBS} \
$${build_fila_LIBS} \
$${build_crono_LIBS} \
$${build_nadir_LIBS} \
$${build_rostra_LIBS} \


