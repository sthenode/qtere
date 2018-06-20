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
///   File: MainWindow.hpp
///
/// Author: $author$
///   Date: 6/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_MAINWINDOW_HPP
#define _XOS_APP_GUI_QT_MAINWINDOW_HPP

#include "xos/gui/qt/application/MainWindow.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {

typedef implement_base MainWindowtImplements;
typedef xos::gui::qt::application::MainWindow MainWindowtExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = MainWindowtImplements, class TExtends = MainWindowtExtends>

class _EXPORT_CLASS MainWindowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef MainWindowt derives;

    MainWindowt() {
        construct();
    }
    virtual ~MainWindowt() {
        destruct();
    }
private:
    MainWindowt(const MainWindowt &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }

protected:
    virtual void onMessage(const xos::gui::qt::Message::Type& type, const xos::gui::qt::Message::Data& data) {
        if (xos::gui::qt::Message::InvalidateWidget == (type)) {
            this->update();
        }
    }
    virtual void onButtonReleaseEvent(const QPoint& pos, const QMouseEvent& event) {
        LOG_DEBUG("this->postMessage(xos::gui::qt::Message::InvalidateWidget)...");
        this->postMessage(xos::gui::qt::Message::InvalidateWidget);
    }

private:
    void construct() {
    }
    void destruct() {
    }
};
typedef MainWindowt<> MainWindow;

} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_MAINWINDOW_HPP 
