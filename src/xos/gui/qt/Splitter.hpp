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
///   File: Splitter.hpp
///
/// Author: $author$
///   Date: 6/6/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_SPLITTER_HPP
#define _XOS_GUI_QT_SPLITTER_HPP

#include "xos/gui/qt/Widget.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef Widgett<QSplitter> SplitterExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Splitter
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Splitter: public SplitterExtends {
Q_OBJECT
public:
    typedef SplitterExtends extends;

    Splitter(QWidget* parent): extends(parent) {
        construct();
    }
    Splitter() {
        construct();
    }
    virtual ~Splitter() {
        destruct();
    }
private:
    Splitter(const Splitter &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }
    
protected slots:
    virtual void onSplitterMoved(int pos, int index) {
        LOG_DEBUG("...pos = " << pos << " index = " << index);
    }

protected:
    void construct() {
        if (!(connect
            (this, SIGNAL(splitterMoved(int, int)),
             this, SLOT(onSplitterMoved(int, int))))) {
            LOG_ERROR("...failed on connect(..., SIGNAL(splitterMoved(int, int)), ...) throw (exception(exception_failed))...");
            throw (exception(exception_failed));
        }
    }
    void destruct() {
    }
    
protected:
};

typedef Splitter SplittertExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Splittert
///////////////////////////////////////////////////////////////////////
template <Qt::Orientation VOrientation, class TExtends = SplittertExtends>
class _EXPORT_CLASS Splittert: public TExtends {
public:
    typedef TExtends extends;

    Splittert(QWidget* parent): extends(parent) {
        construct();
    }
    Splittert() {
        construct();
    }
    virtual ~Splittert() {
        destruct();
    }
private:
    Splittert(const Splittert &copy) {
    }
    
protected:
    void construct() {
        this->setOrientation(VOrientation);
    }
    void destruct() {
    }

protected:
};
typedef Splittert<Qt::Horizontal> HSplitter;
typedef Splittert<Qt::Vertical> VSplitter;

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_SPLITTER_HPP 
