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
#ifndef _XOS_APP_GUI_QT_QTERE_TREEVIEW_HPP
#define _XOS_APP_GUI_QT_QTERE_TREEVIEW_HPP

#include "xos/gui/qt/TreeView.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace qtere {

typedef implement_base TreeViewt_implements;
typedef xos::gui::qt::TreeView TreeViewt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: TreeViewt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = TreeViewt_implements, class TExtends = TreeViewt_extends>

class _EXPORT_CLASS TreeViewt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    TreeViewt(QWidget* parent): extends(parent) {
        construct();
    }
    TreeViewt() {
        construct();
    }
    virtual ~TreeViewt() {
        destruct();
    }
private:
    TreeViewt(const TreeViewt &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }

protected:
    void construct() {
        this->resizeToParent();
        this->header()->hide();
    }
    void destruct() {
    }

protected:
};
typedef TreeViewt<> TreeView;

} /// namespace qtere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_QTERE_TREEVIEW_HPP 
