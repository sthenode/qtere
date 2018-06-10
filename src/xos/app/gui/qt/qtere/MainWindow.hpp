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
#include "xos/gui/qt/standard/Item.hpp"
#include "xos/gui/qt/standard/ItemModel.hpp"
#include "xos/app/gui/qt/qtere/TreeView.hpp"
#include "xos/app/gui/qt/qtere/TableView.hpp"
#include "xos/app/gui/qt/qtere/ListView.hpp"
#include "xos/gui/qt/Splitter.hpp"
#include "xos/gui/qt/String.hpp"
#include "xos/fs/tree/branch.hpp"
#include "xos/os/os/fs.hpp"

namespace xos {
namespace app {
namespace gui {
namespace qt {
namespace qtere {

typedef xos::gui::qt::EventStatus EventStatus;
enum {
    EventUnhandled = xos::gui::qt::EventUnhandled,
    EventSuccess = xos::gui::qt::EventSuccess,
    EventFailed = xos::gui::qt::EventFailed
};
typedef xos::gui::qt::String String;
typedef xos::gui::qt::HSplitter HSplitter;
typedef xos::gui::qt::VSplitter VSplitter;
typedef xos::gui::qt::standard::Item Item;
typedef xos::gui::qt::standard::ItemModel ItemModel;

typedef xos::gui::qt::TreeViewEvents MainWindowImplements;
typedef xos::gui::qt::application::MainWindow MainWindowtExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainWindowt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = MainWindowImplements, class TExtends = MainWindowtExtends>

class _EXPORT_CLASS MainWindowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    MainWindowt() {
        construct();
    }
    virtual ~MainWindowt() {
        destruct();
    }
private:
    MainWindowt(const MainWindowt &copy) {
        LOG_ERROR("...unexpected throw (exception(exception_failed))...");
        throw (exception(exception_failed));
    }
    
protected:
    virtual EventStatus onTreeViewEventClicked(const QModelIndex& index) {
        LOG_DEBUG("...row = " << index.row() << " column = " << index.column());
        if ((treemodel_) && (treeview_)) {
            QStandardItem* item = 0;
            
            if ((item = treemodel_->itemFromIndex(index))) {
                fs::tree::node* node = 0;

                if ((node = ((fs::tree::branch*)item->data(Qt::UserRole+1).value<void*>()))) {
                    fs::tree::branch* branch = 0;
                    
                    if ((branch = ((fs::tree::branch*)(*node)))) {

                        if (!(branch->got_branches())) {
                            fs::tree::branch* childBranch = 0;
                            fs::tree::leaf* childLeaf = 0;
                            Item* childItem = 0;
                            
                            for (auto b: branch->branches()) {
                                if ((childBranch = (*b))) {
                                    if ((childItem = new Item(String(childBranch->name())))) {
                                        childItem->setData(QVariant::fromValue<void*>(childBranch));
                                        childItem->setIcon(style_->standardIcon(QStyle::SP_DirIcon));
                                        item->appendRow(childItem);
                                    }
                                }
                            }
                            for (auto l: branch->leaves()) {
                                if ((childLeaf = (*l))) {
                                    if ((childItem = new Item(String(childLeaf->name())))) {
                                        childItem->setData(QVariant::fromValue<void*>(childLeaf));
                                        childItem->setIcon(style_->standardIcon(QStyle::SP_FileIcon));
                                        item->appendRow(childItem);
                                    }
                                }
                            }
                        }
                        treeview_->expand(index);
                    }
                }
            }
        }
        return EventUnhandled;
    }

public:
    virtual bool afterCreate
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        bool result = true;

        style_ = qApplication.style();
        
        LOG_DEBUG("new TreeView(this)...");
        if ((treeview_ = new TreeView(this))) {
            treeview_->forwardTreeViewEventsTo(this);
        } else {
            LOG_ERROR("...failed on new TreeView(this)");
            result = false;
        }
        LOG_DEBUG("new TableView(this)...");
        if ((tableview_ = new TableView(this))) {
        } else {
            LOG_ERROR("...failed on new TableView(this)");
            result = false;
        }
        LOG_DEBUG("new ListView(this)...");
        if ((listview_ = new ListView(this))) {
        } else {
            LOG_ERROR("...failed on new ListView(this)");
            result = false;
        }
        LOG_DEBUG("new HSplitter(this)...");
        if ((hsplitter_ = new HSplitter(this))) {
            if (treeview_) {
                hsplitter_->addWidget(treeview_);
            }
            if (tableview_) {
                hsplitter_->addWidget(tableview_);
            }
        } else {
            LOG_ERROR("...failed on new HSplitter(this)");
            result = false;
        }
        LOG_DEBUG("new VSplitter(this)...");
        if ((vsplitter_ = new VSplitter(this))) {
            if (hsplitter_) {
                vsplitter_->addWidget(hsplitter_);
            }
            if (listview_) {
                vsplitter_->addWidget(listview_);
            }
        } else {
            LOG_ERROR("...failed on new VSplitter(this)");
            result = false;
        }
        if ((treeview_) && (optind < argc)) {
            const char_t* chars = 0;

            if ((chars = argv[optind]) && (chars[0])) {
                
                if ((treemodel_ = new ItemModel)) {
                    QStandardItem* root = 0;
                    
                    if ((root = treemodel_->invisibleRootItem())) {
                        Item* item = 0;
                        
                        if ((item = new Item(String(chars)))) {
                            root->appendRow(item);

                            if ((entry_.exists(chars))) {
                                
                                if ((entry_.is_directory())) {
                                    xos::fs::tree::node* node = 0;

                                    if ((node = &root_)) {
                                        root_ = chars;
                                        item->setData(QVariant::fromValue<void*>(node));
                                    }
                                }
                            }
                        }
                        treeview_->setModel(treemodel_);
                    } else {
                        delete treemodel_;
                        treemodel_ = 0;
                    }
                }
            }
        }
        return result;
    }
    virtual bool beforeDestroy
    (QApplication& qApplication, int argc, char_t** argv, char_t** env) {
        bool result = true;

        if ((treeview_)) {
            LOG_DEBUG("delete treeview...");
            delete treeview_;
            treeview_ = 0;
        } else {
            LOG_ERROR("...unexpected !(treeview_)");
            result = false;
        }
        if ((tableview_)) {
            LOG_DEBUG("delete tableview...");
            delete tableview_;
            tableview_ = 0;
        } else {
            LOG_ERROR("...unexpected !(tableview_)");
            result = false;
        }
        if ((listview_)) {
            LOG_DEBUG("delete listview...");
            delete listview_;
            listview_ = 0;
        } else {
            LOG_ERROR("...unexpected !(listview_)");
            result = false;
        }
        if ((hsplitter_)) {
            LOG_DEBUG("delete hsplitter...");
            delete hsplitter_;
            hsplitter_ = 0;
        } else {
            LOG_ERROR("...unexpected !(hsplitter_)");
            result = false;
        }
        if ((vsplitter_)) {
            LOG_DEBUG("delete vsplitter...");
            delete vsplitter_;
            vsplitter_ = 0;
        } else {
            LOG_ERROR("...unexpected !(vsplitter_)");
            result = false;
        }
        return result;
    }

protected:
    virtual void resizeEvent(QResizeEvent *event) {
        LOG_DEBUG("...width = " << event->size().width() << ", height = " << event->size().height());
        extends::resizeEvent(event);
        if ((treeview_) && (treeview_->parent() == this)) {
            treeview_->resizeToParent();
        }
        if ((tableview_) && (tableview_->parent() == this)) {
            tableview_->resizeToParent();
        }
        if ((listview_) && (listview_->parent() == this)) {
            listview_->resizeToParent();
        }
        if ((hsplitter_) && (hsplitter_->parent() == this)) {
            hsplitter_->resizeToParent();
        }
        if ((vsplitter_) && (vsplitter_->parent() == this)) {
            vsplitter_->resizeToParent();
            {
                QList<int> sizes = vsplitter_->sizes();
                if (1 < (sizes.length())) {
                    size_t size1 = sizes[0], size2 = sizes[1], size = size1 + size2;
                    LOG_DEBUG("...size1 = " << size1 << " size2 = " << size2 << "");
                    sizes.clear();
                    sizes.append(size*3/4);
                    sizes.append(size/4);
                    vsplitter_->setSizes(sizes);
                }
            }
        }
    }

    void construct() {
        style_ = 0;
        treemodel_ = 0;
        treeview_ = 0;
        tableview_ = 0;
        listview_ = 0;
        hsplitter_ = 0;
        vsplitter_ = 0;
    }
    void destruct() {
        if ((treeview_)) {
            LOG_ERROR("...unexpected (treeview_) throw (exception(exception_failed))...");
            throw (exception(exception_failed));
        }
        if ((tableview_)) {
            LOG_ERROR("...unexpected (tableview_) throw (exception(exception_failed))...");
            throw (exception(exception_failed));
        }
        if ((hsplitter_)) {
            LOG_ERROR("...unexpected (hsplitter_) throw (exception(exception_failed))...");
            throw (exception(exception_failed));
        }
        if ((vsplitter_)) {
            LOG_ERROR("...unexpected (vsplitter_) throw (exception(exception_failed))...");
            throw (exception(exception_failed));
        }
    }

protected:
    os::os::fs::directory::entry entry_;
    fs::tree::branch root_;
    QStyle* style_;
    ItemModel* treemodel_;
    TreeView* treeview_;
    TableView* tableview_;
    ListView* listview_;
    HSplitter* hsplitter_;
    VSplitter* vsplitter_;
};
typedef MainWindowt<> MainWindow;

} /// namespace qtere
} /// namespace qt
} /// namespace gui
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_GUI_QT_QTERE_MAINWINDOW_HPP 
