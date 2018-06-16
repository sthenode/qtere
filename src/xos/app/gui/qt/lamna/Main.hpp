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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 6/11/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_LAMNA_MAIN_HPP
#define _XOS_APP_GUI_QT_LAMNA_MAIN_HPP

#include "xos/gui/qt/application/WindowMain.hpp"
#include "xos/app/gui/qt/lamna/MainWindow.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace lamna {

typedef xos::gui::qt::application::WindowMain::implements MaintImplements;
typedef xos::gui::qt::application::WindowMain MaintExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = MaintImplements, class TExtends = MaintExtends>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    Maint()
    : mainWindow_(0), 
      mainWindowWidth_(defaultMainWindowWidth()),
      mainWindowHeight_(defaultMainWindowHeight()) {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy) {
    }

protected:
    virtual QMainWindow* createMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        MainWindow* mainWindow = 0;

        LOG_DEBUG("new MainWindow())...");
        if ((mainWindow = new MainWindow())) {
            mainWindow_ = mainWindow;
            return mainWindow;
        } else {
            LOG_ERROR("...failed on new MainWindow()");
        }
        return 0;
    }
    virtual bool afterCreateMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        MainWindow* mainWindow = 0;

        if (qMainWindow == (mainWindow = mainWindow_)) {
            mainWindow->resize(mainWindowWidth(), mainWindowHeight());

            LOG_DEBUG("mainWindow->afterCreate(qApplication, argc, argv, env)...");
            if ((mainWindow->afterCreate(qApplication, argc, argv, env))) {
                return true;
            } else {
                LOG_ERROR("...failed on mainWindow->afterCreate(qApplication, argc, argv, env)");
            }
        }
        return false;
    }
    virtual bool beforeDestroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        MainWindow* mainWindow = 0;

        if (qMainWindow == (mainWindow = mainWindow_)) {

            LOG_DEBUG("mainWindow->beforeDestroy(qApplication, argc, argv, env)...");
            if ((mainWindow->beforeDestroy(qApplication, argc, argv, env))) {
                return true;
            } else {
                LOG_ERROR("...failed on beforeDestroyCreate(qApplication, argc, argv, env)");
            }
        }
        return false;
    }

    virtual size_t mainWindowWidth() const {
        return mainWindowWidth_;
    }
    virtual size_t mainWindowHeight() const {
        return mainWindowHeight_;
    }
    virtual size_t defaultMainWindowWidth() const {
        return 700;
    }
    virtual size_t defaultMainWindowHeight() const {
        return 300;
    }

protected:
    MainWindow* mainWindow_;
    size_t mainWindowWidth_, mainWindowHeight_;
};
typedef Maint<> Main;

} /// namespace lamna
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_LAMNA_MAIN_HPP 
