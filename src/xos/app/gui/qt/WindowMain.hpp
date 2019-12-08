///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
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
///   File: WindowMain.hpp
///
/// Author: $author$
///   Date: 10/22/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_WINDOWMAIN_HPP
#define _XOS_APP_GUI_QT_WINDOWMAIN_HPP

#include "xos/gui/qt/application/WindowMain.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {

typedef xos::gui::qt::application::WindowMain::implements WindowMaint_implements;
typedef xos::gui::qt::application::WindowMain WindowMaint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: WindowMaint
///////////////////////////////////////////////////////////////////////
template <class TImplements = WindowMaint_implements, class TExtends = WindowMaint_extends>
class _EXPORT_CLASS WindowMaint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef WindowMaint derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WindowMaint() {
    }
    virtual ~WindowMaint() {
    }
private:
    WindowMaint(const WindowMaint &copy) {
        LOG_ERROR("...unexpected throw exception(exception_unexpected)...");
        throw exception(exception_unexpected);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS WindowMaint
typedef WindowMaint<> WindowMain;

} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_WINDOWMAIN_HPP 
