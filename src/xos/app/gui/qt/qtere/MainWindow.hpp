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
#ifndef _XOS_APP_GUI_QT_QTERE_MAINWINDOW_HPP
#define _XOS_APP_GUI_QT_QTERE_MAINWINDOW_HPP

#include "xos/gui/qt/application/MainWindow.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace qtere {

typedef xos::gui::qt::application::MainWindow MainWindowt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template <class TExtends = MainWindowt_extends>
class _EXPORT_CLASS MainWindowt: public TExtends {
public:
    typedef TExtends extends;

    MainWindowt() {
    }
    virtual ~MainWindowt() {
    }
private:
    MainWindowt(const MainWindowt &copy) {
    }
    
protected:
    virtual void resizeEvent(QResizeEvent *event) {
        const QSize& size = event->size();
        size_t width = size.width(), height = size.height();
        LOG_DEBUG("...width = " << width << ", height = " << height);
        extends::resizeEvent(event);
    }
};
typedef MainWindowt<> MainWindow;

} /// namespace qtere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_QTERE_MAINWINDOW_HPP 