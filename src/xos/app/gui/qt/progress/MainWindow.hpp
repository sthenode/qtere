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
///   File: MainWindow.hpp
///
/// Author: $author$
///   Date: 10/22/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MAINWINDOW_HPP
#define _XOS_MAINWINDOW_HPP

#include "xos/app/gui/qt/MainWindow.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace progress {

typedef app::gui::qt::MainWindow::implements MainWindowt_implements;
typedef app::gui::qt::MainWindow MainWindowt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainWindowt_implements, class TExtends = MainWindowt_extends>
class _EXPORT_CLASS MainWindowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef MainWindowt derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainWindowt() {
    }
    virtual ~MainWindowt() {
    }
private:
    MainWindowt(const MainWindowt &copy) {
        LOG_ERROR("...unexpected throw exception(exception_unexpected)...");
        throw exception(exception_unexpected);
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool afterCreate
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        if ((progressBar_ = new QProgressBar(this))) {
            progressBar_->setMinimum(0);
            progressBar_->setMaximum(100);
            progressBar_->setValue(50);
            progressBar_->setTextVisible(false);
            progressBar_->show();
        }
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
        size_t width = this->width(), height = this->height();
        LOG_DEBUG("extends::resizeEvent(event)...");
        extends::resizeEvent(event);
        if (progressBar_) {
            progressBar_->resize(width, progressBar_->height());
            progressBar_->move(0, height - progressBar_->height());
        }
    }
    virtual void paintEvent(QPaintEvent *event) {
        extends::paintEvent(event);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool HideProgress() {
        if ((progressBar_)) {
            progressBar_->hide();
            return true;
        }
        return false;
    }
    virtual bool ShowProgress(int maximum = 100) {
        if ((progressBar_)) {
            progressBar_->setMaximum(maximum);
            if ((UpdateProgress())) {
                progressBar_->show();
                return true;
            }
        }
        return false;
    }
    virtual bool UpdateProgress(int value = 100) {
        if ((0 < (value)) && (progressBar_)) {
            progressBar_->setValue(value);
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    QProgressBar* progressBar_;
}; /// class _EXPORT_CLASS MainWindowt
typedef MainWindowt<> MainWindow;

} /// namespace progress
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_MAINWINDOW_HPP 
