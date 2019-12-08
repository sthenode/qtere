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
///   Date: 5/31/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_APPLICATION_MAINWINDOW_HPP
#define _XOS_GUI_QT_APPLICATION_MAINWINDOW_HPP

#include "xos/gui/qt/Widget.hpp"

#if (!defined(WINDOWS) || !(QT_VERSION < 0x040700))
#define XOS_GUI_QT_APPLICATION_MAINWINDOW_ACCEPT_DROPS
#endif /// (!defined(WINDOWS) || !(QT_VERSION < 0x040700))

namespace xos {
namespace gui {
namespace qt {
namespace application {

typedef Widgett<QMainWindow> MainWindowt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template <class TExtends = MainWindowt_extends>
class _EXPORT_CLASS MainWindowt: public TExtends {
public:
    typedef TExtends extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindowt() {
    }
    virtual ~MainWindowt() {
    }
private:
    MainWindowt(const MainWindowt &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool afterCreate
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool beforeDestroy
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void resizeEvent(QResizeEvent *event) {
        extends::resizeEvent(event);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};
typedef MainWindowt<> MainWindow;

} /// namespace application
} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_APPLICATION_MAINWINDOW_HPP 
