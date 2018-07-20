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
///   Date: 6/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_GUI_QT_VEDERE_MAIN_HPP
#define _XOS_APP_GUI_QT_VEDERE_MAIN_HPP

#include "xos/app/gui/qt/vedere/MainWindow.hpp"
#include "xos/gui/qt/application/WindowMain.hpp"
#include "xos/app/gui/vedere/main.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace vedere {

typedef xos::gui::qt::application::WindowMain::implements MainImplements;
typedef gui::vedere::maint
<MainImplements, gui::vedere::main_optt
 <MainImplements, xos::gui::qt::application::WindowMain> > MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements implements;
    typedef MainExtends extends;

    Main()
    : mainWindow_(0), 
      mainWindowWidth_(defaultMainWindowWidth()),
      mainWindowHeight_(defaultMainWindowHeight()) {
    }
    virtual ~Main() {
    }
private:
    Main(const Main &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
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
                size_t width = image_width(), height = image_height(), depth = image_depth();
                const char* file = image_file();
                gui::vedere::image::format_t format = image_format();
                gui::vedere::image::transform_t transform = image_transform();

                LOG_DEBUG("mainWindow->init(width = " << width << ", height = " << height << ", depth = " << depth << ", file = \"" << file << "\", format, transform)...");
                if (!(mainWindow->init(width, height, depth, file, format, transform))) {
                } else {
                    LOG_ERROR("...failed on mainWindow->init(width = " << width << ", height = " << height << ", depth = " << depth << ", file = \"" << file << "\", format, transform)");
                }
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

            LOG_DEBUG("mainWindow->finish()...");
            mainWindow->finish();
            
            LOG_DEBUG("mainWindow->beforeDestroy(qApplication, argc, argv, env)...");
            if ((mainWindow->beforeDestroy(qApplication, argc, argv, env))) {
                return true;
            } else {
                LOG_ERROR("...failed on beforeDestroyCreate(qApplication, argc, argv, env)");
            }
        }
        return false;
    }

protected:
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

} /// namespace vedere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_VEDERE_MAIN_HPP 
