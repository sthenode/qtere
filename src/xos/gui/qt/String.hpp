///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: String.hpp
///
/// Author: $author$
///   Date: 6/7/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_STRING_HPP
#define _XOS_GUI_QT_STRING_HPP

#include "xos/gui/qt/Qt.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef QString StringtExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Stringt
///////////////////////////////////////////////////////////////////////
template <class TExtends = StringtExtends>
class _EXPORT_CLASS Stringt: public TExtends {
public:
    typedef TExtends extends;

    Stringt(const wchar_t* chars): extends(char_string(chars).chars()) {
    }
    Stringt(const char* chars): extends(chars) {
    }
    Stringt(const Stringt &copy): extends(copy) {
    }
    Stringt() {
    }
    virtual ~Stringt() {
    }
};
typedef Stringt<> String;

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_STRING_HPP 
