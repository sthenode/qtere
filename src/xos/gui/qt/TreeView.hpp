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
///   File: TreeView.hpp
///
/// Author: $author$
///   Date: 6/1/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GUI_QT_TREEVIEW_HPP
#define _XOS_GUI_QT_TREEVIEW_HPP

#include "xos/gui/qt/Widget.hpp"

namespace xos {
namespace gui {
namespace qt {

typedef int EventStatus;
enum {
    EventUnhandled = 0,
    EventSuccess,
    EventFailed
};

typedef implement_base TreeViewEventstImplements;
///////////////////////////////////////////////////////////////////////
///  Class: TreeViewEventst
///////////////////////////////////////////////////////////////////////
template <class TImplements = TreeViewEventstImplements>
class _EXPORT_CLASS TreeViewEventst: virtual public TImplements {
public:
    typedef TImplements implements;
    typedef TreeViewEventst TreeViewEvents;
    virtual EventStatus onTreeViewEventClicked(const QModelIndex& index) {
        return EventUnhandled;
    }
    virtual EventStatus onTreeViewEventDoubleClicked(const QModelIndex& index) {
        return EventUnhandled;
    }
    virtual EventStatus onTreeViewEventActivated(const QModelIndex& index) {
        return EventUnhandled;
    }
    virtual EventStatus onTreeViewEventCollapsed(const QModelIndex& index) {
        return EventUnhandled;
    }
    virtual EventStatus onTreeViewEventExpanded(const QModelIndex& index) {
        return EventUnhandled;
    }
    virtual TreeViewEvents* forwardTreeViewEventsTo(TreeViewEvents* to) {
        TreeViewEvents* forwardTo = this->treeViewEventsForwardTo();
        return forwardTo;
    }
    virtual TreeViewEvents* treeViewEventsForwardTo() const {
        return 0;
    }
};
typedef TreeViewEventst<> TreeViewEvents;

typedef Widgett<QTreeView> TreeViewExtends;
///////////////////////////////////////////////////////////////////////
///  Class: TreeView
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS TreeView: public TreeViewExtends {
Q_OBJECT
public:
    typedef TreeViewExtends extends;

    TreeView(QWidget* parent): extends(parent) {
        construct();
    }
    TreeView() {
        construct();
    }
    virtual ~TreeView() {
        destruct();
    }
private:
    TreeView(const TreeView &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }

public:
    virtual TreeViewEvents* forwardTreeViewEventsTo(TreeViewEvents* to) {
        TreeViewEvents* forwardTo = this->treeViewEventsForwardTo();
        treeViewEventsForwardTo_ = to;
        return forwardTo;
    }
    virtual TreeViewEvents* treeViewEventsForwardTo() const {
        return treeViewEventsForwardTo_;
    }

protected slots:
    virtual void onClicked(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        TreeViewEvents* forwardTo = 0;
        if ((forwardTo = this->treeViewEventsForwardTo())) {
            EventStatus status = EventUnhandled;
            if ((status = forwardTo->onTreeViewEventClicked(index))) {
                return;
            }
        }
    }
    virtual void onDoubleClicked(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        TreeViewEvents* forwardTo = 0;
        if ((forwardTo = this->treeViewEventsForwardTo())) {
            EventStatus status = EventUnhandled;
            if ((status = forwardTo->onTreeViewEventDoubleClicked(index))) {
                return;
            }
        }
    }
    virtual void onActivated(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        TreeViewEvents* forwardTo = 0;
        if ((forwardTo = this->treeViewEventsForwardTo())) {
            EventStatus status = EventUnhandled;
            if ((status = forwardTo->onTreeViewEventActivated(index))) {
                return;
            }
        }
    }
    virtual void onCollapsed(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        TreeViewEvents* forwardTo = 0;
        if ((forwardTo = this->treeViewEventsForwardTo())) {
            EventStatus status = EventUnhandled;
            if ((status = forwardTo->onTreeViewEventCollapsed(index))) {
                return;
            }
        }
    }
    virtual void onExpanded(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        TreeViewEvents* forwardTo = 0;
        if ((forwardTo = this->treeViewEventsForwardTo())) {
            EventStatus status = EventUnhandled;
            if ((status = forwardTo->onTreeViewEventExpanded(index))) {
                return;
            }
        }
    }
    
protected:
    void construct() {
        treeViewEventsForwardTo_ = 0;
        
        connect
        (this, SIGNAL(activated(const QModelIndex)),
         this, SLOT(onActivated(const QModelIndex)));

        connect
        (this, SIGNAL(clicked(const QModelIndex)),
         this, SLOT(onClicked(const QModelIndex)));

        connect
        (this, SIGNAL(doubleClicked(const QModelIndex)),
         this, SLOT(onDoubleClicked(const QModelIndex)));

        connect
        (this, SIGNAL(expanded(const QModelIndex)),
         this, SLOT(onExpanded(const QModelIndex)));

        connect
        (this, SIGNAL(collapsed(const QModelIndex)),
         this, SLOT(onCollapsed(const QModelIndex)));
    }
    void destruct() {
    }
    
protected:
    TreeViewEvents* treeViewEventsForwardTo_;
};

} /// namespace qt
} /// namespace gui
} /// namespace xos

#endif /// _XOS_GUI_QT_TREEVIEW_HPP 
