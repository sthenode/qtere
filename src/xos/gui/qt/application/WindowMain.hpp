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
///   File: WindowMain.hpp
///
/// Author: $author$
///   Date: 5/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_APPLICATION_WINDOWMAIN_HPP
#define _XOS_GUI_QT_APPLICATION_WINDOWMAIN_HPP

#include "xos/gui/qt/application/Main.hpp"

namespace xos {
namespace gui {
namespace qt {
namespace application {

typedef Main::implements WindowMaint_implements;
typedef Main WindowMaint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: WindowMaint
///////////////////////////////////////////////////////////////////////
template <class TImplements = WindowMaint_implements, class TExtends = WindowMaint_extends>
class _EXPORT_CLASS WindowMaint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    WindowMaint(): qMainWindow_(0) {
    }
    virtual ~WindowMaint() {
    }
private:
    WindowMaint(const WindowMaint &copy): qMainWindow_(0) {
    }

protected:
    virtual QMainWindow* createMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        QMainWindow* qMainWindow = 0;

        LOG_DEBUG("new QMainWindow())...");
        if ((qMainWindow = new QMainWindow())) {
            return qMainWindow;
        } else {
            LOG_ERROR("...failed on new QMainWindow()");
        }
        return 0;
    }
    virtual bool beforeCreateMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterCreateMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }

    virtual bool destroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow) && (qMainWindow == (qMainWindow_))) {
            LOG_DEBUG("delete qMainWindow...");
            delete qMainWindow;
            return true;
        } else {
            LOG_ERROR("...unexpected (!qMainWindow) || (qMainWindow != (qMainWindow_))");
        }
        return false;
    }
    virtual bool beforeDestroyMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterDestroyMainWindow
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        return true;
    }

    virtual bool showMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        if ((qMainWindow)) {
            LOG_DEBUG("qMainWindow_->show()...");
            qMainWindow->show();
            return true;
        }
        return false;
    }
    virtual bool beforeShowMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }
    virtual bool afterShowMainWindow
    (QMainWindow* qMainWindow, QApplication& qApplication,
     int argc, char_t** argv, char_t** env) {
        return true;
    }

    virtual int beforeExec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOG_DEBUG("beforeCreateMainWindow(qApplication, argc, argv, env)...");
        if ((beforeCreateMainWindow(qApplication, argc, argv, env))) {

            LOG_DEBUG("createMainWindow(qApplication, argc, argv, env)...");
            if ((qMainWindow_ = createMainWindow(qApplication, argc, argv, env))) {

                LOG_DEBUG("afterCreateMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
                if ((afterCreateMainWindow(qMainWindow_, qApplication, argc, argv, env))) {

                    LOG_DEBUG("beforeShowMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
                    if ((beforeShowMainWindow(qMainWindow_, qApplication, argc, argv, env))) {

                        LOG_DEBUG("showMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
                        if ((showMainWindow(qMainWindow_, qApplication, argc, argv, env))) {

                            LOG_DEBUG("afterShowMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
                            if ((afterShowMainWindow(qMainWindow_, qApplication, argc, argv, env))) {
                                return err = 0;
                            } else {
                                LOG_ERROR("...failed on afterShowMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                            }
                        } else {
                            LOG_ERROR("...failed on showMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                        }
                    } else {
                        LOG_ERROR("...failed on beforeShowMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                    }
                } else {
                    LOG_ERROR("failed on afterCreateMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                }
                LOG_DEBUG("destroyMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
                if (!(destroyMainWindow(qMainWindow_, qApplication, argc, argv, env))) {
                    LOG_ERROR("...failed on destroyMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                }
                qMainWindow_ = 0;
            } else {
                LOG_ERROR("...failed on createMainWindow(qApplication, argc, argv, env)");
            }
        } else {
            LOG_ERROR("...failed on beforeMainWindow(qApplication, argc, argv, env)");
        }
        return err;
    }
    virtual int afterExec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 0;

        if ((qMainWindow_)) {
            LOG_DEBUG("beforeDestroyMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
            if (!(beforeDestroyMainWindow(qMainWindow_, qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on beforeDestroyMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                if (!err) err = 1;
            }
            LOG_DEBUG("destroyMainWindow(qMainWindow_, qApplication, argc, argv, env)...");
            if (!(destroyMainWindow(qMainWindow_, qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on destroyMainWindow(qMainWindow_, qApplication, argc, argv, env)");
                if (!err) err = 1;
            }
            qMainWindow_ = 0;
            LOG_DEBUG("afterDestroyMainWindow(qApplication, argc, argv, env)...");
            if (!(afterDestroyMainWindow(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed on afterDestroyMainWindow(qApplication, argc, argv, env)");
                if (!err) err = 1;
            }
        } else {
            LOG_ERROR("...unexpected 0 = qMainWindow_");
            if (!err) err = 1;
        }
        return err;
    }

protected:
    QMainWindow* qMainWindow_;
};
typedef WindowMaint<> WindowMain;

} /// namespace application
} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_APPLICATION_WINDOWMAIN_HPP 
