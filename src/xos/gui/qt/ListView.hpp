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
///   File: ListView.hpp
///
/// Author: $author$
///   Date: 6/3/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_LISTVIEW_HPP
#define _XOS_GUI_QT_LISTVIEW_HPP

#include "xos/gui/qt/Widget.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef Widgett<QListView> ListViewExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ListView
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ListView: public ListViewExtends {
Q_OBJECT
public:
    typedef ListViewExtends extends;

    ListView(QWidget* parent): extends(parent) {
        construct();
    }
    ListView() {
        construct();
    }
    virtual ~ListView() {
        destruct();
    }
private:
    ListView(const ListView &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }

protected slots:
    virtual void onActivated(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
    }
    virtual void onClicked(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
    }
    virtual void onDoubleClicked(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
    }

protected:
    void construct() {
        connect
        (this, SIGNAL(activated(const QModelIndex)),
         this, SLOT(onActivated(const QModelIndex)));

        connect
        (this, SIGNAL(clicked(const QModelIndex)),
         this, SLOT(onClicked(const QModelIndex)));

        connect
        (this, SIGNAL(doubleClicked(const QModelIndex)),
         this, SLOT(onDoubleClicked(const QModelIndex)));
    }
    void destruct() {
    }
    
protected:
};

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_LISTVIEW_HPP 
