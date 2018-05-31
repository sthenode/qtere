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
///   Date: 5/30/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_APPLICATION_MAIN_HPP
#define _XOS_GUI_QT_APPLICATION_MAIN_HPP

#include "xos/gui/qt/Qt.hpp"
#include "xos/gui/main.hpp"

namespace xos {
namespace gui {
namespace qt {
namespace application {

typedef main::implements MaintImplements;
typedef main MaintExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = MaintImplements, class TExtends = MaintExtends>
class _EXPORT_CLASS Maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    Maint() {
    }
    virtual ~Maint() {
    }
private:
    Maint(const Maint &copy) {
    }

protected:
    virtual int exec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOG_DEBUG("qApplication.exec()...");
        if ((err = qApplication.exec())) {
            LOG_ERROR("failed err = " << err << " on qApplication.exec()...");
        }
        return err;
    }
    virtual int beforeExec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int afterExec
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int event_loop(int argc, char_t** argv, char_t** env) {
        int err = 0;
        QApplication qApplication(argc, argv);

        LOG_DEBUG("beforeExec(qApplication, argc, argv, env)...");
        if (!(err = beforeExec(qApplication, argc, argv, env))) {
            int err2 = 0;

            LOG_DEBUG("exec(qApplication, argc, argv, env)...");
            if ((err = exec(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed " << err << " on exec(qApplication, argc, argv, env)");
            }

            LOG_DEBUG("afterExec(qApplication, argc, argv, env)...");
            if ((err2 = afterExec(qApplication, argc, argv, env))) {
                LOG_ERROR("...failed " << err2 << " on afterExec(qApplication, argc, argv, env)");
                if (!err) err = err2;
            }
        } else {
            LOG_ERROR("...failed " << err << " on beforeExec(qApplication, argc, argv, env)");
        }
        return err;
    }
};
typedef Maint<> Main;

} /// namespace application
} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_APPLICATION_MAIN_HPP 
