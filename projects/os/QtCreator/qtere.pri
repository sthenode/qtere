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
# Os QtCreator .pri file for qtere
########################################################################
UNAME = $$system(uname)

contains(UNAME,Darwin) {
QTERE_OS = macosx
} else {
QTERE_OS = linux
}

#CONFIG += c++11
#CONFIG += c++0x

########################################################################
# rostra
ROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PKG_BLD = $${ROSTRA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_THIRDPARTY_PRJ_BLD = $${ROSTRA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PKG_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_PRJ_BLD = $${OTHER_BLD}/$${ROSTRA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PKG_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_THIRDPARTY_PRJ_BLD}/lib
#ROSTRA_LIB = $${ROSTRA_PKG_BLD}/lib
ROSTRA_LIB = $${ROSTRA_PRJ_BLD}/lib
#ROSTRA_LIB = $${QTERE_LIB}

# rostra LIBS
#
rostra_LIBS += \
-L$${ROSTRA_LIB}/lib$${ROSTRA_NAME} \
-l$${ROSTRA_NAME} \

########################################################################
# nadir
NADIR_THIRDPARTY_PKG_MAKE_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_MAKE_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PKG_BLD = $${NADIR_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_THIRDPARTY_PRJ_BLD = $${NADIR_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PKG_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_PRJ_BLD = $${OTHER_BLD}/$${NADIR_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PKG_BLD}/lib
#NADIR_LIB = $${NADIR_THIRDPARTY_PRJ_BLD}/lib
#NADIR_LIB = $${NADIR_PKG_BLD}/lib
NADIR_LIB = $${NADIR_PRJ_BLD}/lib
#NADIR_LIB = $${QTERE_LIB}

# nadir LIBS
#
nadir_LIBS += \
-L$${NADIR_LIB}/lib$${NADIR_NAME} \
-l$${NADIR_NAME} \

########################################################################
# crono
CRONO_THIRDPARTY_PKG_MAKE_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_MAKE_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PKG_BLD = $${CRONO_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_THIRDPARTY_PRJ_BLD = $${CRONO_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PKG_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_PRJ_BLD = $${OTHER_BLD}/$${CRONO_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PKG_BLD}/lib
#CRONO_LIB = $${CRONO_THIRDPARTY_PRJ_BLD}/lib
#CRONO_LIB = $${CRONO_PKG_BLD}/lib
CRONO_LIB = $${CRONO_PRJ_BLD}/lib
#CRONO_LIB = $${QTERE_LIB}

# crono LIBS
#
crono_LIBS += \
-L$${CRONO_LIB}/lib$${CRONO_NAME} \
-l$${CRONO_NAME} \

########################################################################
# arbora
ARBORA_THIRDPARTY_PKG_MAKE_BLD = $${ARBORA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PRJ_MAKE_BLD = $${ARBORA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PKG_BLD = $${ARBORA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_THIRDPARTY_PRJ_BLD = $${ARBORA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_PKG_BLD = $${OTHER_BLD}/$${ARBORA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARBORA_PRJ_BLD = $${OTHER_BLD}/$${ARBORA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PKG_BLD}/lib
#ARBORA_LIB = $${ARBORA_THIRDPARTY_PRJ_BLD}/lib
#ARBORA_LIB = $${ARBORA_PKG_BLD}/lib
ARBORA_LIB = $${ARBORA_PRJ_BLD}/lib
#ARBORA_LIB = $${QTERE_LIB}

# arbora LIBS
#
arbora_LIBS += \
-L$${ARBORA_LIB}/lib$${ARBORA_NAME} \
-l$${ARBORA_NAME} \

########################################################################
# archa
ARCHA_THIRDPARTY_PKG_MAKE_BLD = $${ARCHA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PRJ_MAKE_BLD = $${ARCHA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PKG_BLD = $${ARCHA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_THIRDPARTY_PRJ_BLD = $${ARCHA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_PKG_BLD = $${OTHER_BLD}/$${ARCHA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
ARCHA_PRJ_BLD = $${OTHER_BLD}/$${ARCHA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PKG_MAKE_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PKG_BLD}/lib
#ARCHA_LIB = $${ARCHA_THIRDPARTY_PRJ_BLD}/lib
#ARCHA_LIB = $${ARCHA_PKG_BLD}/lib
ARCHA_LIB = $${ARCHA_PRJ_BLD}/lib
#ARCHA_LIB = $${QTERE_LIB}

# archa LIBS
#
archa_LIBS += \
-L$${ARCHA_LIB}/lib$${ARCHA_NAME} \
-l$${ARCHA_NAME} \

########################################################################
# fila
FILA_THIRDPARTY_PKG_MAKE_BLD = $${FILA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_MAKE_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
FILA_THIRDPARTY_PKG_BLD = $${FILA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_THIRDPARTY_PRJ_BLD = $${FILA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PKG_BLD = $${OTHER_BLD}/$${FILA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
FILA_PRJ_BLD = $${OTHER_BLD}/$${FILA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#FILA_LIB = $${FILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PKG_BLD}/lib
#FILA_LIB = $${FILA_THIRDPARTY_PRJ_BLD}/lib
#FILA_LIB = $${FILA_PKG_BLD}/lib
FILA_LIB = $${FILA_PRJ_BLD}/lib
#FILA_LIB = $${QTERE_LIB}

# fila LIBS
#
fila_LIBS += \
-L$${FILA_LIB}/lib$${FILA_NAME} \
-l$${FILA_NAME} \

########################################################################
# rete
RETE_THIRDPARTY_PKG_MAKE_BLD = $${RETE_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_MAKE_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
RETE_THIRDPARTY_PKG_BLD = $${RETE_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_THIRDPARTY_PRJ_BLD = $${RETE_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PKG_BLD = $${OTHER_BLD}/$${RETE_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
RETE_PRJ_BLD = $${OTHER_BLD}/$${RETE_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#RETE_LIB = $${RETE_THIRDPARTY_PKG_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_MAKE_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PKG_BLD}/lib
#RETE_LIB = $${RETE_THIRDPARTY_PRJ_BLD}/lib
#RETE_LIB = $${RETE_PKG_BLD}/lib
RETE_LIB = $${RETE_PRJ_BLD}/lib
#RETE_LIB = $${QTERE_LIB}

# rete LIBS
#
rete_LIBS += \
-L$${RETE_LIB}/lib$${RETE_NAME} \
-l$${RETE_NAME} \

########################################################################
# lamna
LAMNA_THIRDPARTY_PKG_MAKE_BLD = $${LAMNA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PRJ_MAKE_BLD = $${LAMNA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PKG_BLD = $${LAMNA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_THIRDPARTY_PRJ_BLD = $${LAMNA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_PKG_BLD = $${OTHER_BLD}/$${LAMNA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
LAMNA_PRJ_BLD = $${OTHER_BLD}/$${LAMNA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PKG_MAKE_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PKG_BLD}/lib
#LAMNA_LIB = $${LAMNA_THIRDPARTY_PRJ_BLD}/lib
#LAMNA_LIB = $${LAMNA_PKG_BLD}/lib
LAMNA_LIB = $${LAMNA_PRJ_BLD}/lib
#LAMNA_LIB = $${QTERE_LIB}

# lamna LIBS
#
lamna_LIBS += \
-L$${LAMNA_LIB}/lib$${LAMNA_NAME} \
-l$${LAMNA_NAME} \

########################################################################
# plena
PLENA_THIRDPARTY_PKG_MAKE_BLD = $${PLENA_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PRJ_MAKE_BLD = $${PLENA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PKG_BLD = $${PLENA_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_THIRDPARTY_PRJ_BLD = $${PLENA_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_PKG_BLD = $${OTHER_BLD}/$${PLENA_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
PLENA_PRJ_BLD = $${OTHER_BLD}/$${PLENA_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#PLENA_LIB = $${PLENA_THIRDPARTY_PKG_MAKE_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PKG_BLD}/lib
#PLENA_LIB = $${PLENA_THIRDPARTY_PRJ_BLD}/lib
#PLENA_LIB = $${PLENA_PKG_BLD}/lib
PLENA_LIB = $${PLENA_PRJ_BLD}/lib
#PLENA_LIB = $${QTERE_LIB}

# plena LIBS
#
plena_LIBS += \
-L$${PLENA_LIB}/lib$${PLENA_NAME} \
-l$${PLENA_NAME} \

########################################################################
# vedere
VEDERE_THIRDPARTY_PKG_MAKE_BLD = $${VEDERE_THIRDPARTY_PKG}/build/$${QTERE_OS}/$${BUILD_CONFIG}
VEDERE_THIRDPARTY_PRJ_MAKE_BLD = $${VEDERE_THIRDPARTY_PRJ}/build/$${QTERE_OS}/$${BUILD_CONFIG}
VEDERE_THIRDPARTY_PKG_BLD = $${VEDERE_THIRDPARTY_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
VEDERE_THIRDPARTY_PRJ_BLD = $${VEDERE_THIRDPARTY_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
VEDERE_PKG_BLD = $${OTHER_BLD}/$${VEDERE_PKG}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
VEDERE_PRJ_BLD = $${OTHER_BLD}/$${VEDERE_PRJ}/build/$${QTERE_OS}/QtCreator/$${BUILD_CONFIG}
#VEDERE_LIB = $${VEDERE_THIRDPARTY_PKG_MAKE_BLD}/lib
#VEDERE_LIB = $${VEDERE_THIRDPARTY_PRJ_MAKE_BLD}/lib
#VEDERE_LIB = $${VEDERE_THIRDPARTY_PKG_BLD}/lib
#VEDERE_LIB = $${VEDERE_THIRDPARTY_PRJ_BLD}/lib
#VEDERE_LIB = $${VEDERE_PKG_BLD}/lib
VEDERE_LIB = $${VEDERE_PRJ_BLD}/lib
#VEDERE_LIB = $${QTERE_LIB}

# vedere LIBS
#
vedere_LIBS += \
-L$${VEDERE_LIB}/lib$${VEDERE_NAME} \
-l$${VEDERE_NAME} \

########################################################################
# qtere

# qtere INCLUDEPATH
#
qtere_INCLUDEPATH += \

# qtere DEFINES
#
qtere_DEFINES += \

# qtere LIBS
#
qtere_LIBS += \
$${vedere_LIBS} \
$${plena_LIBS} \
$${lamna_LIBS} \
$${rete_LIBS} \
$${fila_LIBS} \
$${archa_LIBS} \
$${arbora_LIBS} \
$${crono_LIBS} \
$${nadir_LIBS} \
$${rostra_LIBS} \
$${build_qtere_LIBS} \
-lpthread \
-ldl \

contains(QTERE_OS,linux) {
qtere_LIBS += \
-lrt
} else {
}

contains(QTERE_OS,linux) {
} else {
qtere_FRAMEWORKS += -framework QtWidgets
}
